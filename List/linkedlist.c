#include "linkedlist.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

LinkedList *createLinkedList()
{
    LinkedList *list;

    if (!(list = (LinkedList *)malloc(sizeof(LinkedList))))
        return (NULL);
    list->currentElementCount = 0;
    list->headerNode.pLink = NULL;
    return (list);
}

int addLLElement(LinkedList* pList, int position, ListNode element)
{
    ListNode *node;
    ListNode *tmp;
    int i;
    int ret;

    i = 0;
    ret = FALSE;
    if (pList == NULL)
        return (ret);
    if (!(node = (ListNode *)malloc(sizeof(ListNode))))
        return (FALSE);
    if (position >= 0 && pList->currentElementCount >= position)
    {
        *node = element;
        node->pLink = NULL;
        tmp = &(pList->headerNode);
        while (i++ < position)
            tmp = tmp->pLink;
        node->pLink = tmp->pLink;
        tmp->pLink = node;
        pList->currentElementCount++;
        ret = TRUE;
    }
    return (ret);
}

int removeLLElement(LinkedList* pList, int position)
{
    ListNode *tmp;
    ListNode *node;
    int i;
    int ret;

    i = 0;
    ret = FALSE;
    if (pList == NULL)
        return (ret);
    if (position >= 0 && pList->currentElementCount > position)
    {
        tmp = &(pList->headerNode);
        while (i++ < position)
            tmp = tmp->pLink;
        node = tmp->pLink;
        tmp->pLink = node->pLink;
        free(node);
        pList->currentElementCount--;
        ret = TRUE;
    }
    return (ret);
}

ListNode *getLLElement(LinkedList* pList, int position)
{
    ListNode *node;
    int i;

    node = NULL;
    i = 0;
    if (pList == NULL)
        return (NULL);
    if (position >= 0 && pList->currentElementCount >= position)
    {
        node = &(pList->headerNode);
        while (i++ < position)
            node = node->pLink;
    }
    return (node);
}

void    clearLinkedList(LinkedList* pList)
{
    int i;

    i = 0;
    if (pList == NULL)
        return ;
    while (pList->currentElementCount > 0)
        removeLLElement(pList, 0);
}

int getLinkedListLength(LinkedList *pList)
{
    int ret;

    ret = FALSE;
    if (pList == NULL)
        return (ret);
    ret = pList->currentElementCount;
    return (ret);
}

void deleteLinkedList(LinkedList* pList)
{
    if (pList != NULL)
    {
        clearLinkedList(pList);
        free(pList);
    }
}

void    displayList(LinkedList *pList)
{
    int i;
    int len;

    i = 0;
    len = getLinkedListLength(pList);
    if (pList == NULL)
    {
        printf("List is empty.\n");
        return (NULL);
    printf ("Current element count is %d\n", len);
    while (i < len)
    {
        printf("[%d] Index element is %d\n", i, getLLElement(pList, i)->data);
        i++;
    }

}