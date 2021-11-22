#include "arraylist.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

ArrayList* createArrayList(int maxElementCount)
{
	ArrayList *array;

	array = NULL;
	if (maxElementCount > 0)
	{
		if (!(array = (ArrayList *)malloc(sizeof(ArrayList))))
			return (NULL);
	array->maxElementCount = maxElementCount;
	array->currentElementCount = 0;
	array->pElement = NULL;
	}
	if (!(array->pElement = (ArrayListNode *)malloc(sizeof(ArrayListNode) * maxElementCount)))
		return (NULL);
	memset(array->pElement, 0, sizeof(ArrayListNode) * maxElementCount);
	return (array);
}

void	deleteArrayList(ArrayList *pList)
{
	if (pList != NULL)
	{
		free(pList->pElement);
		free(pList);
	}
}

int	isArrayListFull(ArrayList* pList)
{
	int	ret;

	ret = FALSE;
	if (pList != NULL)
	{
		if (pList->currentElementCount == pList->maxElementCount)
			ret = TRUE;
	}
	return (ret);
}

int	addALElement(ArrayList* pList, int position, ArrayListNode element)
{
	int	ret;
	int	i;

	ret = FALSE;
	i = 0;
	if (pList != NULL)
	{
		if (isArrayListFull(pList) == FALSE)
		{
			if (position >= 0)
			{
				if (position <= pList->currentElementCount)
				{
					i = pList->currentElementCount - 1;
					while (i >= position)
					{
						pList->pElement[i + 1] = pList->pElement[i];
						i--;
					}
				}
				pList->pElement[position] = element;
				pList->currentElementCount++;
				ret = TRUE;
			}
		}
	}
	return (ret);
}

int	removeALElement(ArrayList *pList, int position)
{
	int ret;
	int	i;

	ret = FALSE;
	i = 0;

	if (pList == NULL)
		return (ret);
	if (position >= 0)
	{
		if (position < pList->currentElementCount)
		{
			i = position;
			while (i < pList->currentElementCount - 1)
			{
				pList->pElement[i] = pList->pElement[i + 1];
				i++;
			}
			pList->currentElementCount--;
			ret = TRUE;
		}
	}
	return (ret);
}

ArrayListNode*	getALElement(ArrayList* pList, int position)
{
	ArrayListNode*	node;

	node = NULL;
	if (pList == NULL)
		return (NULL);
	if (position >= 0 && position < pList->currentElementCount)
		node = &(pList->pElement[position]);
	return (node);
}

void	displayArrayList(ArrayList* pList)
{
	int	i;

	if (pList == NULL)
	{
		printf("ArrayList is NULL\n");
		return ;
	}
	printf("currentElementCount is %d\n", pList->currentElementCount);
	printf("maxElementCount is %d\n", pList->maxElementCount);
	i = 0;
	while(i < pList->currentElementCount)
	{
		printf("[%d] index is %d\n", i, getALElement(pList, i)->data);
		i++;
	}
	while (i < pList->maxElementCount)
	{
		printf("%d index is empty\n", i);
		i++;
	}
}

void	clearArrayList(ArrayList* pList)
{
	int	i;
	ArrayListNode *node;

	i = 0;
	if (pList == NULL)
		return ;
	while (i < pList->currentElementCount)
	{
		node = getALElement(pList, i);
		node->data = 0;
		i++;
	}
	pList->currentElementCount = 0;
}

int	getArrayListLength(ArrayList* pList)
{
	if (pList == NULL)
		return (FALSE);
	return (pList->currentElementCount);
}
