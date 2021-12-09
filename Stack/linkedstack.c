#include "linkedstack.h"
#include <stdio.h>

LinkedStack* createLinkedStack()
{
	LinkedStack *stack;

	if (!(stack = malloc(sizeof(LinkedStack))))
		return (NULL);
	stack->currentElementCount = 0;
	if (!(stack->pTopElement = malloc(sizeof(StackNode))))
    {
        free(stack);
		return (NULL);
    }
	stack->pTopElement->data = 0;
	stack->pTopElement->pLink = NULL;
	return (stack);
}

int pushLS(LinkedStack* pStack, StackNode element)
{
	int	ret;
	StackNode *node;

	ret = FALSE;
	if (pStack == NULL)
		return (ret);
	if (!(node = malloc(sizeof(StackNode))))
		return (ret);
	node->data = element.data;
	node->pLink = pStack->pTopElement->pLink;
	pStack->pTopElement->pLink = node;
	pStack->currentElementCount++;
	ret = TRUE;
	return (ret);
}

StackNode* popLS(LinkedStack* pStack)
{
	StackNode *node;

	if (pStack == NULL)
		return (NULL);
	if (isLinkedStackEmpty(pStack))
		return (NULL);
	node = pStack->pTopElement->pLink;
	pStack->pTopElement->pLink = node->pLink;
	pStack->currentElementCount--;
	return (node);
}

StackNode* peekLS(LinkedStack* pStack)
{
	StackNode *node;

	if (pStack == NULL)
		return (NULL);
	if (isLinkedStackEmpty(pStack))
		return (NULL);
	node = pStack->pTopElement->pLink;
	return (node);
}

void deleteLinkedStack(LinkedStack* pStack)
{
	int i;

	i = 0;
	if (pStack == NULL)
		return (NULL);
	while (i < pStack->currentElementCount)
	{
		free(popLS(pStack));
		i++;
	}
	free(pStack->pTopElement);
	free(pStack);
}

int isLinkedStackEmpty(LinkedStack* pStack)
{
	int	ret;

	ret = FALSE;
	if (pStack == NULL)
		return (ret);
	if (pStack->currentElementCount == 0)
		ret = TRUE;
	return (ret);
}
