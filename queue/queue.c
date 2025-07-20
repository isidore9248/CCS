/**
  **********************************************************************************************************************
  * @file    queue.c
  * @brief   环形队列功能实现
  * @author  const_zpc  any question please send mail to const_zpc@163.com
  * @version V1.0.0
  * @date    2022-05-02
  *
  * @details  功能详细说明：
  *           + 支持定长数据队列和不定长数据队列
  *           + 动态创建/销毁队列内存，静态初始化队列内存
  *           + 数据添加/删除元素
  *
  **********************************************************************************************************************
  * 源码路径：https://gitee.com/const-zpc/queue.git 具体问题及建议可在该网址填写 Issue
  *
  * 定长数据队列使用方式:
  *    1、若需要动态内存申请, 则使用函数 Queue_Creat；否则定义静态变量，使用初始化函数 Queue_Init
  *    2、通过函数 Queue_Push 添加往队列的末尾加入数据，可通过 Queue_Request 请求队列中空闲的内存，减少内存拷贝
  *    3、通过函数 Queue_Pop 删除队列顶端数据
  *
  * 不定长数据队列使用方式:
  *    1、若需要动态内存申请, 则使用函数 Queue_ArgCreat；否则定义静态变量，使用初始化函数 Queue_ArgInit
  *    2、通过函数 Queue_ArgPush 添加往队列的末尾加入数据，可通过 Queue_ArgRequest 请求队列中空闲的内存，减少内存拷贝
  *    3、通过函数 Queue_ArgPop 删除队列顶端数据
  *    4、函数 Queue_ArgPush 添加往队列的末尾加入数据会根据实际大小存入，因此 Queue_ArgRequest 请求队列中空闲的内存可以多一些，
  *       最后再按照实际使用的大小写入即可
  *
  **********************************************************************************************************************
  */

/* Includes ----------------------------------------------------------------------------------------------------------*/
#include "queue.h"
#include <string.h>
#include <stdlib.h>

/* Private typedef ---------------------------------------------------------------------------------------------------*/
/* Private define ----------------------------------------------------------------------------------------------------*/

#define QUEUE_ENABLE_COVER      (0X80)
#define QUEUE_EXIT_DATA         (0X01)
#define QUEUE_DATA_FULL         (0X02)
#define QUEUE_DISABLE_PUSH      (0X04)

/* Private macro -----------------------------------------------------------------------------------------------------*/

#define IS_QUEUE_STATE_SET(x, mask)     (((x->state) & (mask)) == (mask) ? 1 : 0)

#define QUEUE_STATE_SET(x, mask)        ((x->state) |= (mask))
#define QUEUE_STATE_CLEAR(x, mask)      ((x->state) &= ~(mask))

/* Private variables -------------------------------------------------------------------------------------------------*/
/* Private function prototypes ---------------------------------------------------------------------------------------*/
/* Private function --------------------------------------------------------------------------------------------------*/

/**
  * @brief      创建队列并完成初始化, 采用的是动态分配方式
  *
  * @param[in]  queueNum 队列组数
  * @param[in]  size     队列中单组内存大小
  * @param[in]  isCover  false,不覆盖; true,队列满了覆盖未读取的最早旧数据
  * @return     QueueCtrl_t 队列控制句柄指针
  */
QueueCtrl_t *Queue_Creat(queuesize_t queueNum, queuesize_t size, bool isCover)
{
    QueueCtrl_t *pQueue = (QueueCtrl_t *)malloc(sizeof(QueueCtrl_t) + size * queueNum);
    
    if (NULL != pQueue)
    {
        Queue_Init(pQueue, (char *)pQueue + sizeof(QueueCtrl_t), queueNum, size, isCover);
    }
    
    return pQueue;
}

/**
  * @brief      销毁队列
  *
  * @param[in,out] pCtrl 队列控制句柄指针
  */
void Queue_Destory(QueueCtrl_t *pCtrl)
{
    free(pCtrl);
}

/**
  * @brief      队列控制初始化, 可采用的是动态/静态内存分配方式
  *
  * @param[in,out] pCtrl 队列控制句柄
  * @param[in]  buf      buf 地址
  * @param[in]  queueNum 队列数目大小
  * @param[in]  size     队列中单个内存大小
  * @param[in]  isCover  false,不覆盖; true,队列满了覆盖未读取的最早旧数据
  * @return     0,成功; -1,失败
  */
int Queue_Init(QueueCtrl_t *pCtrl, const void *pBufMem, queuesize_t queueNum, queuesize_t size, bool isCover)
{
    if (pCtrl == NULL || pBufMem == NULL || queueNum == 0 || size == 0)
    {
        return -1;
    }

    pCtrl->end     = 0;
    pCtrl->head    = 0;
    pCtrl->pBufMem = (char *)pBufMem;
    pCtrl->un.num  = queueNum;
    pCtrl->size    = size;
    pCtrl->state   = 0x00;
    
    if (isCover)
    {
        QUEUE_STATE_SET(pCtrl, QUEUE_ENABLE_COVER);
    }

    return 0;
}

/**
  * @brief      请求返回队列末尾空闲的内存地址
  *
  * @note       之后再通过 Queue_Push 标记已被使用
  * @param[in]  pCtrl 队列控制句柄
  * @retval     末尾空闲的内存地址指针, NULL代表入参错误或无空闲内存
  */
void *Queue_Request(QueueCtrl_t *pCtrl)
{
    if (pCtrl == NULL)
    {
        return NULL;
    }
    
    if (IS_QUEUE_STATE_SET(pCtrl, QUEUE_DISABLE_PUSH))
    {
        return NULL;
    }
    
    return &pCtrl->pBufMem[pCtrl->end * pCtrl->size];
}

/**
  * @brief      在队列末尾加入新的数据
  *
  * @param[in,out] pCtrl 队列控制句柄
  * @param[in]     src   新的数据
  * @retval     返回的值含义如下
  *             @arg 0: 写入成功
  *             @arg -1: 写入失败
  */
extern int Queue_Push(QueueCtrl_t *pCtrl, const void *src)
{
    if (pCtrl == NULL || src == NULL)
    {
        return -1;
    }
    
    if (IS_QUEUE_STATE_SET(pCtrl, QUEUE_DISABLE_PUSH))
    {
        return -1;
    }
    
    if ((char *)src < pCtrl->pBufMem || (char *)src > (pCtrl->pBufMem + pCtrl->size * pCtrl->un.num))
    {
        memcpy(&pCtrl->pBufMem[pCtrl->end * pCtrl->size], src, pCtrl->size);
    }

    pCtrl->end++;
    QUEUE_STATE_SET(pCtrl, QUEUE_EXIT_DATA);

    if ((pCtrl->end) >= (pCtrl->un.num))
    {
        (pCtrl->end) = 0;
    }

    if (IS_QUEUE_STATE_SET(pCtrl, QUEUE_DATA_FULL))
    {
        (pCtrl->head) = (pCtrl->end);
    }
    else if ((pCtrl->end) == (pCtrl->head))
    {
        QUEUE_STATE_SET(pCtrl, QUEUE_DATA_FULL);

        if (!IS_QUEUE_STATE_SET(pCtrl, QUEUE_ENABLE_COVER))
        {
            QUEUE_STATE_SET(pCtrl, QUEUE_DISABLE_PUSH);
        }
    }

    return 0;
}

/**
  * @brief      返回队列顶端未读取的内存地址
  *
  * @note       之后通过 Queue_Pop 将数据弹出队列
  * @param[in]  pCtrl 队列控制句柄
  * @retval     顶端未读取的内存地址指针, NULL代表入参错误或无数据
  */
void *Queue_Front(QueueCtrl_t *pCtrl)
{
    if (pCtrl == NULL)
    {
        return NULL;
    }
    
    if (!IS_QUEUE_STATE_SET(pCtrl, QUEUE_EXIT_DATA))
    {
        return NULL;
    }
    
    return &pCtrl->pBufMem[pCtrl->head * pCtrl->size];
}

/**
  * @brief      弹出队列顶端的数据
  *
  * @param[in,out] pCtrl 队列控制句柄
  * @retval     返回的值含义如下
  *             @arg 0: 成功
  *             @arg -1: 失败
  */
int Queue_Pop(QueueCtrl_t *pCtrl)
{
    if (pCtrl == NULL)
    {
        return -1;
    }

    if (!IS_QUEUE_STATE_SET(pCtrl, QUEUE_EXIT_DATA))
    {
        return -1;
    }

    pCtrl->head++;

    if ((pCtrl->head) >= (pCtrl->un.num))
    {
        pCtrl->head = 0;
    }

    if ((pCtrl->head) == (pCtrl->end))
    {
        if (!IS_QUEUE_STATE_SET(pCtrl, QUEUE_DATA_FULL))
        {
            QUEUE_STATE_CLEAR(pCtrl, QUEUE_EXIT_DATA);
        }
    }

    QUEUE_STATE_CLEAR(pCtrl, QUEUE_DISABLE_PUSH);
    QUEUE_STATE_CLEAR(pCtrl, QUEUE_DATA_FULL);

    return 0;
}

/**
  * @brief      创建不定长数据队列并完成初始化, 采用的是动态分配方式
  *
  * @param[in]  size     内存大小
  * @return     QueueCtrl_t 队列控制句柄指针
  */
QueueCtrl_t *Queue_ArgCreat(queuesize_t size)
{
    QueueCtrl_t *pQueue = (QueueCtrl_t *)malloc(sizeof(QueueCtrl_t) + size);
    
    if (NULL != pQueue)
    {
        Queue_ArgInit(pQueue, (char *)pQueue + sizeof(QueueCtrl_t), size);
    }
    
    return pQueue;
}

/**
  * @brief      销毁不定长数据队列
  *
  * @param[in,out] pCtrl 队列控制句柄指针
  */
void Queue_ArgDestory(QueueCtrl_t *pCtrl)
{
    free(pCtrl);
}

/**
  * @brief      不定长数据队列控制初始化, 可采用的是动态/静态内存分配方式
  *
  * @param[in,out] pCtrl 队列控制句柄
  * @param[in]  buf      buf 内存地址
  * @param[in]  size     内存大小
  * @return     0,成功; -1,失败
  */
int Queue_ArgInit(QueueCtrl_t *pCtrl, const void *pBufMem, queuesize_t size)
{
    if (pCtrl == NULL || pBufMem == NULL || size == 0)
    {
        return -1;
    }

    pCtrl->end     = 0;
    pCtrl->head    = 0;
    pCtrl->pBufMem = (char *)pBufMem;
    pCtrl->un.virsize  = size;
    pCtrl->size    = size;
    pCtrl->state   = 0x00;
    
    return 0;
}

/**
  * @brief      请求返回不定长数据队列末尾空闲的内存地址
  *
  * @note       之后再通过 Queue_ArgPush 标记已被使用
  * @param[in]  pCtrl 队列控制句柄
  * @param[in]  size  请求的内存大小
  * @retval     末尾空闲的内存地址指针, NULL代表入参错误或无空闲内存
  */
void *Queue_ArgRequest(QueueCtrl_t *pCtrl, queuesize_t size)
{
    if (pCtrl == NULL)
    {
        return NULL;
    }

    if (pCtrl->end == pCtrl->head && IS_QUEUE_STATE_SET(pCtrl, QUEUE_EXIT_DATA))
    {
        return NULL;
    }

    if (pCtrl->end >= pCtrl->head)
    {
        pCtrl->un.virsize = pCtrl->size;

        if (pCtrl->size - pCtrl->end >= (size + sizeof(queuesize_t)))
        {
            memcpy(&pCtrl->pBufMem[pCtrl->end], &size, sizeof(queuesize_t));
            return &pCtrl->pBufMem[pCtrl->end + sizeof(queuesize_t)];
        }
        else
        {
            if (pCtrl->head >= (size + sizeof(queuesize_t)))
            {
                pCtrl->un.virsize = pCtrl->end;
                pCtrl->end = 0;
                memcpy(&pCtrl->pBufMem[pCtrl->end], &size, sizeof(queuesize_t));
                return &pCtrl->pBufMem[pCtrl->end + sizeof(queuesize_t)];
            }
        }
    }
    else
    {
        if (pCtrl->head - pCtrl->end >= (size + sizeof(queuesize_t)))
        {
            memcpy(&pCtrl->pBufMem[pCtrl->end], &size, sizeof(queuesize_t));
            return &pCtrl->pBufMem[pCtrl->end + sizeof(queuesize_t)];
        }
    }

    return NULL;
}

/**
  * @brief      在队列末尾加入新的数据
  *
  * @note       如果是通过函数 Queue_ArgRequest 请求的内存，那么 size 不能大于请求的内存大小
  *             最终会按照 size 的大小存入数据，所以一开始通过函数 Queue_ArgRequest 请求的内存可以大些
  * @param[in,out] pCtrl 队列控制句柄
  * @param[in]     src   新的数据
  * @param[in]     size  新的数据内存大小
  * @retval     返回的值含义如下
  *             @arg 0: 写入成功
  *             @arg -1: 写入失败
  */
int Queue_ArgPush(QueueCtrl_t *pCtrl, const void *pSrc, queuesize_t size)
{
    if (pCtrl == NULL || pSrc == NULL)
    {
        return -1;
    }

    if (pCtrl->end == pCtrl->head && IS_QUEUE_STATE_SET(pCtrl, QUEUE_EXIT_DATA))
    {
        return -1;
    }

    if ((char *)pSrc < pCtrl->pBufMem || (char *)pSrc > (pCtrl->pBufMem + pCtrl->size))
    {
        if (pCtrl->end >= pCtrl->head)
        {
            pCtrl->un.virsize = pCtrl->size;

            if (pCtrl->size - pCtrl->end < (size + sizeof(queuesize_t)))
            {
                if (pCtrl->head < (size + sizeof(queuesize_t)))
                {
                    return -1;
                }
                
                pCtrl->un.virsize = pCtrl->end;
                pCtrl->end = 0;
            }
        }
        else
        {
            if (pCtrl->head - pCtrl->end < (size + sizeof(queuesize_t)))
            {
                return -1;
            }
        }

        memcpy(&pCtrl->pBufMem[pCtrl->end], &size, sizeof(queuesize_t));
        memcpy(&pCtrl->pBufMem[pCtrl->end + sizeof(queuesize_t)], pSrc, size);
    }
    else
    {
        queuesize_t tmpsize;

        memcpy(&tmpsize, &pCtrl->pBufMem[pCtrl->end], sizeof(queuesize_t));

        if (tmpsize < size)
        {
            return -1;
        }

        memcpy(&pCtrl->pBufMem[pCtrl->end], &size, sizeof(queuesize_t));
    }

    pCtrl->end += (size + sizeof(queuesize_t));
    QUEUE_STATE_SET(pCtrl, QUEUE_EXIT_DATA);

    /* 再次判断防止 pop 任务优先级高于 push时连续 pop 出现异常 */
    if (pCtrl->head == pCtrl->end)
    {
        QUEUE_STATE_CLEAR(pCtrl, QUEUE_EXIT_DATA);
    }

    return 0;
}

void *Queue_ArgFront(QueueCtrl_t *pCtrl, queuesize_t *psize)
{
    if (pCtrl == NULL || psize == NULL)
    {
        return NULL;
    }

    if (!IS_QUEUE_STATE_SET(pCtrl, QUEUE_EXIT_DATA))
    {
        return NULL;
    }

    memcpy(psize, &pCtrl->pBufMem[pCtrl->head], sizeof(queuesize_t));

    return &pCtrl->pBufMem[pCtrl->head + sizeof(queuesize_t)];
}

int Queue_ArgPop(QueueCtrl_t *pCtrl)
{
    queuesize_t size;

    if (pCtrl == NULL)
    {
        return -1;
    }

    if (!IS_QUEUE_STATE_SET(pCtrl, QUEUE_EXIT_DATA))
    {
        return -1;
    }

    memcpy(&size, &pCtrl->pBufMem[pCtrl->head], sizeof(queuesize_t));
    pCtrl->head += (size + sizeof(queuesize_t));

    if (pCtrl->head >= pCtrl->un.virsize)
    {
        pCtrl->head = 0;
    }

    if (pCtrl->head == pCtrl->end)
    {
        QUEUE_STATE_CLEAR(pCtrl, QUEUE_EXIT_DATA);
    }

    return 0;
}


/**
 * @brief      判断该队列是否为空
 * 
  * @param[in]  pCtrl 队列控制句柄
 * @return      若为空返回 true，否则返回 false 
 */
bool Queue_IsEmpty(QueueCtrl_t *pCtrl)
{
    if (pCtrl == NULL)
    {
        return true;
    }

    if (IS_QUEUE_STATE_SET(pCtrl, QUEUE_EXIT_DATA))
    {
        return false;
    }

    return true;
}

/**
  * @brief      清空队列
  *
  * @param[in,out] pCtrl 队列控制句柄
  */
void Queue_Clear(QueueCtrl_t *pCtrl)
{
    if (pCtrl != NULL)
    {
        pCtrl->end    = 0;
        pCtrl->head   = 0;
        pCtrl->state  &= QUEUE_ENABLE_COVER;
    }
}
