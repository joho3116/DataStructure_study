#include "arrayqueue.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

ArrayQueue* createArrayQueue(int maxElementCount)
{
    ArrayQueue *queue;

    queue = NULL;
    if (maxElementCount > 0)
    {
        if (!(queue = malloc(sizeof(ArrayQueue))))
            return (NULL);
        queue->maxElementCount = maxElementCount;
        queue->currentElementCount = 0;
        queue->front = 0;
        queue->rear = queue->maxElementCount - 1;
        queue->pElement = NULL;
        if (!(queue->pElement = malloc(sizeof(ArrayQueueNode) * maxElementCount)))
        {
            free(queue);
            return (NULL);
        }
        memset(queue->pElement, 0, sizeof(ArrayQueueNode) * maxElementCount);
    }
    return (queue);
}
int enqueueAQ(ArrayQueue* pQueue, ArrayQueueNode element)
{
    int ret;

    ret = FALSE;
    if (pQueue == NULL || isArrayQueueFull(pQueue))
        return (ret);
    pQueue->rear = (pQueue->rear + 1) % pQueue->maxElementCount;
    pQueue->pElement[pQueue->rear] = element;
    pQueue->currentElementCount++;
    ret = TRUE;
    return (ret);
}
ArrayQueueNode *dequeueAQ(ArrayQueue* pQueue)
{
    int ret;

    ret = pQueue->front;
    if (pQueue == NULL || isArrayQueueEmpty(pQueue))
        return (NULL);
    pQueue->front = (pQueue->front + 1) % pQueue->maxElementCount;
    pQueue->currentElementCount--;
    return (pQueue->pElement + ret);
}
ArrayQueueNode *peekAQ(ArrayQueue* pQueue)
{
    if (pQueue == NULL || isArrayQueueEmpty(pQueue))
        return (NULL);
    return (pQueue->pElement + pQueue->front);
}
void deleteArrayQueue(ArrayQueue* pQueue)
{
    if (pQueue != NULL)
    {
        free(pQueue->pElement);
        free(pQueue);
    }
}
int isArrayQueueFull(ArrayQueue* pQueue)
{
    int ret;

    ret = FALSE;
    if (pQueue == NULL)
        return (ret);
    if (pQueue->currentElementCount == pQueue->maxElementCount)
        ret = TRUE;
    return (ret);
    
}
int isArrayQueueEmpty(ArrayQueue* pQueue)
{
    int ret;

    ret = FALSE;
    if (pQueue == NULL)
        return (ret);
    if (pQueue->currentElementCount == 0)
        ret = TRUE;
    return (ret);
}