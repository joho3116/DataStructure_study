#include "doublylist.h"
#include <stdlib.h>
#include <stdio.h>

DoublyList* createDoublyList()
{
	DoublyList *list;

	list = (DoublyList *)malloc(sizeof(DoublyList));
	if (!list){
		printf("메모리 할당 오류. createDoublylist()\n");
		return (NULL);
	}
	list->currentElementCount = 0;
	list->headerNode.pLLink = &(list->headerNode);
	list->headerNode.pRLink =  &(list->headerNode);
	return (list);
}

void deleteDoublyList(DoublyList* pList)
{
	if (!pList){
		clearDoublyList(pList);
		free(pList);
	}
}

int addDLElement(DoublyList* pList, int position, DoublyListNode element)
{
	DoublyListNode *pNewNode;
	DoublyListNode *pPreNode;
	int ret = FALSE;

	if (!pList)
		return ret;
	pNewNode = (DoublyListNode *)malloc(sizeof(DoublyListNode));
	if (!pNewNode){
		printf("메모리 할당 오류, addDLElement()\n");
		return ret;
	}
	if (position >= 0 && position <= pList->currentElementCount)
	{
		*pNewNode = element;
		pNewNode->pRLink = NULL;
		pNewNode->pLLink = NULL;
		pPreNode = &(pList->headerNode);
		for(int i = 0; i < position; i++){
			pPreNode = pPreNode->pRLink;
		}
		pNewNode->pLLink = pPreNode;
		pNewNode->pRLink = pPreNode->pRLink;
		pPreNode->pRLink = pNewNode;
		pNewNode->pRLink->pLLink = pNewNode;
		pList->currentElementCount++;
		ret=TRUE;
	}
	return (ret);
}

int removeDLElement(DoublyList* pList, int position)
{
	DoublyListNode *pPreNode;
	DoublyListNode *pDelNode;
	int ret = FALSE;

	if (position >= 0 && position <= pList->currentElementCount)
	{
		pPreNode = &(pList->headerNode);
		for (int i = 0; i < position; i++){
			pPreNode = pPreNode->pRLink;
		}
		pDelNode = pPreNode->pRLink;
		pPreNode->pRLink = pDelNode->pRLink;
		pDelNode->pRLink->pLLink = pPreNode;
		free(pDelNode);
		pList->currentElementCount--;
		ret = TRUE;
	}
	else
		printf("position 오류, removeDLELement\n");
	return (ret);
}

void clearDoublyList(DoublyList* pList)
{
	if (!pList){
		while(pList->currentElementCount > 0)
			removeDLElement(pList, 0);
	}
}

int getDoublyListLength(DoublyList* pList)
{
	int ret = 0;
	if (!pList)
		ret = pList->currentElementCount;
	return (ret);
}

DoublyListNode* getDLElement(DoublyList* pList, int position)
{
	DoublyListNode *pNode = NULL;
	int i = 0;

	if (!pList){
		printf("position 오류, getDLElement()\n");
		return (NULL);
	}
	if (position >= 0 && position <= pList->currentElementCount)
	{
		pNode = pList->headerNode.pRLink;
		while(i < position)
		{
			pNode = pNode->pRLink;
			i++;
		}
	}
	return pNode;
}

void displayDoublyList(DoublyList* pList)
{
	int i = 0;
	if (!pList)
		printf("원소가 업습니다.\n");
	printf("원소 개수:%d\n", pList->currentElementCount);
	while(i < pList->currentElementCount)
	{
		printf("[%d]: %d\n", i, getDLElement(pList, i)->data);
		i++;
	}
}

