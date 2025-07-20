/* Demo */
#include <stdio.h>
#include <string.h>
#include "queue.h"
#include <time.h>
#include <stdarg.h>
#include <sys/time.h>
#include <unistd.h>

typedef struct
{
    char szDesc[5000];
    int value;
    float fValue;
} QueueTest_t;

#define QUEUE_MAX_NUM 10

QueueCtrl_t sg_tQueueCtrl;
QueueTest_t sg_arrQueueTestBuf[QUEUE_MAX_NUM];

/* 通过动态内存分配的方式申请队列 */
void TestMallocQueue(void)
{
    QueueCtrl_t *pCtrl = Queue_Creat(QUEUE_MAX_NUM, sizeof(QueueTest_t), 0);
    QueueTest_t test;
    QueueTest_t *ptest;

    for (int i = 0; i < QUEUE_MAX_NUM + 1; i++)
    {
        printf("Queue_Push(%d)\n", i);

        // memset(&test, 0, sizeof(QueueTest_t));
        snprintf(test.szDesc, sizeof(test.szDesc), "que%d", i);
        test.value = i;
        test.fValue = 1.1 * i;

        if (Queue_Push(pCtrl, &test) != 0)
        {
            printf("Queue_Push(%d) Fail\n", i);
        }
        else
        {
            printf("PUSH -- %s: %d -> %f\n", test.szDesc, test.value, test.fValue);
        }
    }

    for (int i = 0; i < QUEUE_MAX_NUM + 1; i++)
    {
        memset(&test, 0, sizeof(QueueTest_t));

        printf("Queue_Front(%d)\n", i);
        ptest = Queue_Front(pCtrl);

        if (ptest == NULL)
        {
            printf("Queue_Front(%d) Fail\n", i);
        }
        else
        {
            printf("Front -- %s: %d -> %f\n", ptest->szDesc, ptest->value, ptest->fValue);
        }

        Queue_Pop(pCtrl);
    }

    Queue_Destory(pCtrl);
}

/* 通过静态内存的方式申请队列 */
void TestStaticQueue(void)
{
    QueueTest_t test;
    QueueTest_t *ptest;

    Queue_Init(&sg_tQueueCtrl, sg_arrQueueTestBuf, QUEUE_MAX_NUM, sizeof(QueueTest_t), 0);

    for (int i = 0; i < QUEUE_MAX_NUM + 1; i++)
    {
        printf("Queue_Push(%d)\n", i);

        // memset(&test, 0, sizeof(QueueTest_t));
        snprintf(test.szDesc, sizeof(test.szDesc), "que%d", i);
        test.value = i;
        test.fValue = 1.1 * i;

        if (Queue_Push(&sg_tQueueCtrl, &test) != 0)
        {
            printf("Queue_Push(%d) Fail\n", i);
        }
        else
        {
            printf("PUSH -- %s: %d -> %f\n", test.szDesc, test.value, test.fValue);
        }
    }

    for (int i = 0; i < QUEUE_MAX_NUM + 1; i++)
    {
        memset(&test, 0, sizeof(QueueTest_t));

        printf("Queue_Front(%d)\n", i);
        ptest = Queue_Front(&sg_tQueueCtrl);

        if (ptest == NULL)
        {
            printf("Queue_Front(%d) Fail\n", i);
        }
        else
        {
            printf("Front -- %s: %d -> %f\n", ptest->szDesc, ptest->value, ptest->fValue);
        }

        Queue_Pop(&sg_tQueueCtrl);
    }

    printf("\n");

    /* 请求队列中的空闲内存使用，减少内存拷贝动作 */
    for (int i = 0; i < QUEUE_MAX_NUM + 1; i++)
    {
        printf("Queue_Request(%d)\n", i);
        ptest = Queue_Request(&sg_tQueueCtrl);

        if (ptest != NULL)
        {
            snprintf(ptest->szDesc, sizeof(ptest->szDesc), "que%d", i);
            ptest->value = i;
            ptest->fValue = 2.1 * i;

            if (Queue_Push(&sg_tQueueCtrl, ptest) != 0)
            {
                printf("Queue_Push(%d) Fail\n", i);
            }
            else
            {
                printf("PUSH -- %s: %d -> %f\n", ptest->szDesc, ptest->value, ptest->fValue);
            }
        }
        else
        {
            printf("Queue_Push(%d) Fail\n", i);
        }
    }

    for (int i = 0; i < QUEUE_MAX_NUM + 1; i++)
    {
        memset(&test, 0, sizeof(QueueTest_t));

        printf("Queue_Front(%d)\n", i);
        ptest = Queue_Front(&sg_tQueueCtrl);

        if (ptest == NULL)
        {
            printf("Queue_Front(%d) Fail\n", i);
        }
        else
        {
            printf("Front -- %s: %d -> %f\n", ptest->szDesc, ptest->value, ptest->fValue);
        }

        Queue_Pop(&sg_tQueueCtrl);
    }
}

/* 通过动态内存分配的方式申请支持可存不定长数据队列 */
void TestMallocArgQueue(void)
{
    printf("\n\nTestMallocArgQueue\n\n");

    QueueCtrl_t *pCtrl = Queue_ArgCreat(100);

    for (int i = 0; i < QUEUE_MAX_NUM + 1; i++)
    {
        char szDesc[50];

        snprintf(szDesc, sizeof(szDesc), "que%d", i);

        if (Queue_ArgPush(pCtrl, szDesc, strlen(szDesc) + 1 + i) != 0)
        {
            printf("Queue_ArgPush(%d) Fail\n", i);
        }
        else
        {
            printf("PUSH -- (%p)%s\n", szDesc, szDesc);
        }
    }

    Queue_ArgPop(pCtrl);
    Queue_ArgPop(pCtrl);

    for (int i = 0; i < QUEUE_MAX_NUM + 1; i++)
    {
        char *pszDesc = Queue_ArgRequest(pCtrl, i + 11);

        if (pszDesc != NULL)
        {
            snprintf(pszDesc, i + 11, "2.que%d", i);

            // 请求的内存可以大于加入队列的大小，最终会根据实际加入的大小存入
            if (Queue_ArgPush(pCtrl, pszDesc, strlen(pszDesc) + 2 + i) != 0)
            {
                printf("2.Queue_ArgPush(%d) Fail\n", i);
            }
            else
            {
                printf("2.PUSH -- (%p)%s\n", pszDesc, pszDesc);
            }
        }
        else
        {
            printf("2.Queue_ArgRequest(%d) Fail\n", i);
        }
    }

    for (int i = 0; i < QUEUE_MAX_NUM + 1; i++)
    {
        printf("Queue_Front(%d)\n", i);
        queuesize_t size;
        char *pszDesc = Queue_ArgFront(pCtrl, &size);

        if (pszDesc == NULL)
        {
            printf("Queue_ArgFront(%d) Fail\n", i);
        }
        else
        {
            printf("Front -- (%p)[%d]%s\n", pszDesc, size, pszDesc);
        }

        Queue_ArgPop(pCtrl);
    }

    Queue_ArgDestory(pCtrl);
}
int main()
{
        // TestMallocQueue();

    // TestStaticQueue();

    // TestMallocArgQueue();

    // SummarizeAndDemoQueueUsage(); // 调用新的总结和演示函数

    QueueCtrl_t *fixedQueue = Queue_Creat(5, sizeof(int), true); // 创建可覆盖的定长队列
        // if (fixedQueue == NULL)
    // {
    //     printf("Fixed queue creation failed!\n");
    //     return;
    // }
    int data = 1;
        Queue_Push(fixedQueue, &data); //* ret = 0 正常返回
        Queue_IsEmpty(fixedQueue);

        //* 出队
    //! 需要需要先使用Queue_Front读取队首数据
    int *frontData = (int *)Queue_Front(fixedQueue);
        Queue_Pop(fixedQueue);

        //Queue_Clear(fixedQueue);   // 清空队列
    Queue_Destory(fixedQueue); // 销毁队列

        return 0;
}
