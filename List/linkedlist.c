#include "linkedlist.h"

LinkedList *createLinkedList()
{
    LinkedList *list;

    list = (LinkedList *)malloc(sizeof(LinkedList));

    if (!list)
        printf("createLinkedlist 동적할당 실패\n");
    list->currentElementCount = 0;
    list->headerNode.pLink = NULL;
    return list;
}

int addLLElement(LinkedList* pList, int position, ListNode element)
{
    ListNode *new_node;
    ListNode *temp;
    int i=0;

    if (!pList)
        return FALSE;
    new_node = (ListNode *)malloc(sizeof(ListNode));
    if (!new_node)
        return FALSE;
    if (position >= 0 && pList->currentElementCount >= position)
    {
        *new_node = element;
        new_node->pLink = NULL;
        temp = &(pList->headerNode);
        while(i++ < position)
            temp = temp->pLink;
        new_node->pLink = temp->pLink;
        temp->pLink = new_node;
        pList->currentElementCount++;
        return TRUE;
    }
    else {
        printf("addLLElement position 오류\n");
        return FALSE;
    }

}

int removeLLElement(LinkedList* pList, int position)
{
    ListNode *temp;
    ListNode *del_node;
    int i = 0;

    if (!pList)
        return FALSE;
    if (position >= 0 && pList->currentElementCount > position)
    {
        temp = &(pList->headerNode);
        while(i++<position)
            temp = temp->pLink;
        del_node = temp->pLink;
		temp->pLink = del_node->pLink;
        free(del_node);
        pList->currentElementCount--;
        return TRUE;
    }
    else {
        printf("removeLLElement position 오류\n");
        return FALSE;
    }
}

ListNode *getLLElement(LinkedList* pList, int position)
{
    ListNode *node;
    int i = 0;

    if (!pList)
        return NULL;
    if (position >= 0 && pList->currentElementCount >= position)
    {
        node = &(pList->headerNode);
        while (i++ <= position)
            node = node->pLink;
        return node;
    }
    return NULL;
}


void clearLinkedList(LinkedList* pList)
{
    if (pList != NULL)
        if (pList->currentElementCount > 0)
            removeLLElement(pList, 0);
}

int getLinkedListLength(LinkedList* pList)
{
    int ret = FALSE;
    if(pList != NULL)
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

// void displayList(LinkedList *pList)
// {
//     int i = 0;
//     int num = getLinkedListLength(pList);
//     if (pList != NULL) {
// 		printf("현재 원소 개수 : %d\n", num);
//         while (i < num)
//         {
//             printf("[%d]: %d\n", i, getLLElement(pList, i)->data);
//             i++;
//         }
//     }
//     else
//         printf("원소 없음\n");
// }

void reverseLinkedList(LinkedList* pList)
{
	ListNode *pNode = NULL;
	ListNode *pCurrentNode = NULL;
	ListNode *pPrevNode = NULL;

	if (!pList)
		return ;
	pNode = pList->headerNode.pLink;
	while(pNode)
	{
		pPrevNode = pCurrentNode;
		pCurrentNode = pNode;
		pNode =pNode->pLink;
		pCurrentNode->pLink = pPrevNode;
	}
	pList->headerNode.pLink = pCurrentNode;
}
