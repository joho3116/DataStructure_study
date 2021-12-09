#include "linkeddeque.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

LinkedDeque* createLinkedDeque()
{
    LinkedDeque *deque;

    if (!(deque = malloc(sizeof(LinkedDeque))))
        return (NULL);
    deque->currentElementCount = 0;
    deque->pFrontNode = NULL;
    deque->pRearNode = NULL;
    return (deque);
}

// int insertFrontLD(LinkedDeque* pDeque, DequeNode element)
// {
//     int ret;
//     DequeNode *node;

//     ret = FALSE;
//     if (pDeque == NULL)
//         return (ret);
//     if (!(node = malloc(sizeof(DequeNode))))
//         return (ret);
//     node->data = element.data;
//     node->pLLink = NULL;
//     node->pRLink = pDeque->pFrontNode;
//     if (!pDeque->pFrontNode)
//         pDeque->pRearNode = node;
//     else
//         pDeque->pFrontNode->pLLink = node;
//     pDeque->pFrontNode = node;
//     pDeque->currentElementCount++;
//     ret = TRUE;
//     return (ret);
// }

// int insertRearLD(LinkedDeque* pDeque, DequeNode element)
// {
//     int ret;
//     DequeNode *node;

//     ret = FALSE;
//     if (pDeque == NULL)
//         return (ret);
//     if (!(node = malloc(sizeof(DequeNode))))
//         return (ret);
//     node->data = element.data;
//     node->pRLink = NULL;
//     node->pLLink = pDeque->pRearNode;
//     if (!pDeque->pRearNode)
//         pDeque->pFrontNode = node;
//     else
//         pDeque->pRearNode->pRLink = node;
//     pDeque->pRearNode = node;
//     pDeque->currentElementCount++;
//     ret = TRUE;
//     return (ret);
// }

DequeNode* deleteFrontLD(LinkedDeque* pDeque)
{
    DequeNode *node;

    if (pDeque == NULL || isLinkedDequeEmpty(pDeque))
        return (NULL);
    node = pDeque->pFrontNode;
    if (!(pDeque->pFrontNode->pRLink))
        pDeque->pRearNode = NULL;
    else
        pDeque->pFrontNode->pRLink->pLLink = NULL;
    pDeque->pFrontNode = pDeque->pFrontNode->pRLink;
    pDeque->currentElementCount--;
    return (node);
}

DequeNode* deleteRearLD(LinkedDeque* pDeque)
{
    DequeNode *node;

    if (pDeque == NULL || isLinkedDequeEmpty(pDeque))
        return (NULL);
    node = pDeque->pRearNode;
    if (!(pDeque->pRearNode->pLLink))
        pDeque->pFrontNode = NULL;
    else
        pDeque->pRearNode->pLLink->pRLink = NULL;
    pDeque->pRearNode = pDeque->pRearNode->pLLink;
    pDeque->currentElementCount--;
    return (node);
}

DequeNode* peekFrontLD(LinkedDeque* pDeque)
{
    if (pDeque == NULL || isLinkedDequeEmpty(pDeque))
        return (NULL);
    return (pDeque->pFrontNode);
}

DequeNode* peekRearLD(LinkedDeque* pDeque)
{
if (pDeque == NULL || isLinkedDequeEmpty(pDeque))
        return (NULL);
    return (pDeque->pRearNode);
}

void deleteLinkedDeque(LinkedDeque* pDeque)
{
    if (pDeque == NULL)
        return ;
    while (pDeque->pFrontNode)
    {
        free(deleteFrontLD(pDeque));
    }
    free(pDeque);
}

int isLinkedDequeEmpty(LinkedDeque* pDeque)
{
    int ret;

    ret = FALSE;
    if (pDeque == NULL)
        return (ret);
    if (pDeque->currentElementCount == 0)
        ret = TRUE;
    return (ret);
}