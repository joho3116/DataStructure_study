#include "arraystack.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

ArrayStack* createArrayStack(int maxElementCount)
{
    ArrayStack *array;

    array = NULL;
    if (maxElementCount > 0)
    {
        if (!(array = malloc(sizeof(ArrayStack))))
            return (NULL);
        array->maxElementCount = maxElementCount;
        array->currentElementCount = 0;
        array->pElement = NULL;
    }
    if (!(array->pElement = malloc(sizeof(ArrayStackNode) * maxElementCount)))
    {
        free(array);
        return (NULL);
    }
    memset(array->pElement, 0, sizeof(ArrayStackNode) * maxElementCount);
    return (array);
}

int pushAS(ArrayStack* pStack, ArrayStackNode element)
{
    int ret;
    int head;

    ret = FALSE;
    head = pStack->currentElementCount;
    if (pStack == NULL)
        return (ret);
    if (!isArrayStackFull(pStack))
    {
        pStack->pElement[head] = element;
        pStack->currentElementCount++;
        ret = TRUE;
    }
    return (ret);

}

ArrayStackNode* popAS(ArrayStack* pStack)
{
    ArrayStackNode *node;

    node = NULL;
    if (pStack == NULL)
        return (NULL);
    if (!isArrayStackEmpty(pStack))
    {
        node = &(pStack->pElement[pStack->currentElementCount - 1]);
        pStack->currentElementCount--;
    }
    return (node);
}

ArrayStackNode* peekAS(ArrayStack* pStack)
{
    ArrayStackNode *node;

    node = NULL;
    if (pStack == NULL)
        return (NULL);
    if (!isArrayStackEmpty(pStack))
        node = &(pStack->pElement[pStack->currentElementCount - 1]);
    return (node);
}

void deleteArrayStack(ArrayStack* pStack)
{
    if (pStack != NULL)
    {
        free(pStack->pElement);
        free(pStack);
    }
}

int isArrayStackFull(ArrayStack* pStack)
{
    int ret;

    ret = FALSE;
    if (pStack != NULL)
    {
        if (pStack->currentElementCount == pStack->maxElementCount)
            ret = TRUE;
    }
    return (ret);
}

int isArrayStackEmpty(ArrayStack* pStack)
{
    int ret;

    ret = FALSE;
    if (pStack != NULL)
    {
        if (pStack->currentElementCount == 0)
            ret = TRUE;
    }
    return (ret);
}

void    printArrayStack(ArrayStack* pStack)
{
    int i;

    i = 0;
    printf("current element count is == %d\n", pStack->currentElementCount);
    printf("max element count is == %d\n", pStack->maxElementCount);
    while (i < pStack->maxElementCount)
    {
        printf("element %d is == [%c]\n", i, pStack->pElement[i].data);
        i++;
    }
}
