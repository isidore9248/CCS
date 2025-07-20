/**
  **********************************************************************************************************************
  * @file    queue.c
  * @brief   该文件提供环形队列功能函数原型
  * @author  const_zpc    any question please send mail to const_zpc@163.com
  * @date    2022-05-02
  **********************************************************************************************************************
  *
  **********************************************************************************************************************
  */

/* Define to prevent recursive inclusion -----------------------------------------------------------------------------*/
#ifndef QUEUE_H
#define QUEUE_H

/* Includes ----------------------------------------------------------------------------------------------------------*/
#include <stdint.h>
#include <stdbool.h>

#ifndef NULL
#define NULL   (void *)0
#endif

/* Exported types ----------------------------------------------------------------------------------------------------*/

typedef uint16_t queuesize_t;


/**
  * @brief  队列操作信息结构体定义
  */
typedef struct{
    volatile uint8_t state; /*!< 控制状态 */

    queuesize_t end;        /*!< 循环队列尾哨兵 */

    queuesize_t head;       /*!< 循环队列首哨兵 */

    union
    {
        queuesize_t num;        /*!< 循环队列中能存储的最多组数 */

        queuesize_t virsize;    /*!< Buf 内存基准大小 */
    }un;
    
    queuesize_t size;       /*!< 单组内存大小 */

    char  *pBufMem;         /*!< Buf 指针 */
} QueueCtrl_t;

/* Exported constants ------------------------------------------------------------------------------------------------*/
/* Exported macro ----------------------------------------------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------------------------------------------------*/

/**** 定长队列相关函数 *****/

extern QueueCtrl_t *Queue_Creat(queuesize_t queueNum, queuesize_t size, bool isCover);
extern void Queue_Destory(QueueCtrl_t *pCtrl);

extern int Queue_Init(QueueCtrl_t *pCtrl, const void *pBufMem, queuesize_t queueNum, queuesize_t size, bool isCover);

extern void *Queue_Request(QueueCtrl_t *pCtrl);
extern int Queue_Push(QueueCtrl_t *pCtrl, const void *src);

extern void *Queue_Front(QueueCtrl_t *pCtrl);
extern int Queue_Pop(QueueCtrl_t *pCtrl);

/**** 不定长队列相关函数 *****/

extern QueueCtrl_t *Queue_ArgCreat(queuesize_t size);
extern void Queue_ArgDestory(QueueCtrl_t *pCtrl);

extern int Queue_ArgInit(QueueCtrl_t *pCtrl, const void *pBufMem, queuesize_t size);

extern void *Queue_ArgRequest(QueueCtrl_t *pCtrl, queuesize_t size);
extern int Queue_ArgPush(QueueCtrl_t *pCtrl, const void *src, queuesize_t size);

extern void *Queue_ArgFront(QueueCtrl_t *pCtrl, queuesize_t *psize);
extern int Queue_ArgPop(QueueCtrl_t *pCtrl);

/**** 队列通用函数 *****/

extern bool Queue_IsEmpty(QueueCtrl_t *pCtrl);
extern void Queue_Clear(QueueCtrl_t *pCtrl);

#endif // !QUEUE_H
