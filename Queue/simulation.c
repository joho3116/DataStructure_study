#include "simutil.h"
#include <stdio.h>
#include <stdlib.h>

int insertRearLD_Sim(LinkedDeque* pDeque, SimCustomer customer)
{
	int ret;
	DequeNode *node;

	ret = FALSE;
	if (pDeque == NULL)
		return (ret);
	if (!(node = malloc(sizeof(DequeNode))))
		return (ret);
	node->man = customer;
	node->pRLink = NULL;
	node->pLLink = pDeque->pRearNode;
	if (!pDeque->pRearNode)
		pDeque->pFrontNode = node;
	else
		pDeque->pRearNode->pRLink = node;
	pDeque->pRearNode = node;
	pDeque->currentElementCount++;
	ret = TRUE;
	return (ret);
}

void    insertCustomer(int arrivalTime, int processTime, LinkedDeque *pDeque)
{
	SimCustomer customer;

	if (arrivalTime / 2 == 0 || arrivalTime / 2 == 4)
		customer.serviceTime = 3;
	else if (arrivalTime / 2 == 1)
		customer.serviceTime = 2;
	else
		customer.serviceTime = 1;
	customer.arrivalTime = arrivalTime;
	customer.status = arrival;
	if (!(insertRearLD_Sim(pDeque, customer)))
		return ;
	printSimCustomer(arrivalTime, customer);
}

void	processArrival(int currentTime, LinkedDeque *pArrivalDeque, LinkedDeque *pWaitDeque)
{
	DequeNode *node;

	if (!(node = deleteFrontLD(pArrivalDeque)))
		return ;
	free(pArrivalDeque->pFrontNode);
	if (!(insertRearLD_Sim(pWaitDeque, node->man)))
		return ;
}

void    printSimCustomer(int currentTime, SimCustomer customer)
{
	int	i;

	printf("\n\n======customer status ======\n");
	printf("current time %d, customer%d's status is ", currentTime, currentTime / 2 + 1);
	if (customer.status == arrival)
		printf("arrival\n");
	else if (customer.status == start)
		printf("service start\n");
	else if (customer.status == end)
		printf("service end\n");
}

DequeNode* processServiceNodeStart(int currentTime, LinkedDeque *pWaitDeque)
{
	DequeNode *node;

	if (!(node = deleteFrontLD(pWaitDeque)))
		return (NULL);
	node->man.startTime = currentTime;
	node->man.status = start;
	printSimCustomer(currentTime, node->man);
	return (node);
}

DequeNode* processServiceNodeEnd(int currentTime, DequeNode *pServiceNode)
{
	pServiceNode->man.endTime = currentTime;
	pServiceNode->man.status = end;
	printSimCustomer(currentTime, pServiceNode->man);
	pServiceNode = NULL;
	return (pServiceNode);
}

void	printWaitQueueStatus(int currentTime, LinkedDeque *pWaitDeque)
{
	DequeNode *node;
	int	i;

	i = 0;
	if (pWaitDeque->pFrontNode == NULL)
		return ;
	printf("\n\n\n");
	printf("====== WaitDeque status ======\n");
	printf("current time is %d\n", currentTime);
	node = pWaitDeque->pFrontNode;
	while(i < pWaitDeque->currentElementCount)
		i++;
	printf("current waiting customer's number is == %d\n", i);
}

void printReport(LinkedDeque *pWaitDeque, int serviceUserCount, int totalWaitTime)
{
	printf("\n\n\n====== Report ======\n");
	printf("total customer count is == %d\n", serviceUserCount);
	printf("total waiting time is == %d\n", totalWaitTime);
}

int main()
{
	int arrivalTime = 0;
	int customerNumber = 0;
	int t = 0;
	int	waitTime = 0;
	LinkedDeque *pArrivalDeque;
	LinkedDeque *pWaitDeque;
	DequeNode	*service;

	pArrivalDeque = createLinkedDeque();
	pWaitDeque = createLinkedDeque();
	service = NULL;
	t = 0;
	while (t != 12)
	{
		if (!(t % 2) && (t / 2) < 5)
		{
			insertCustomer(t, t, pArrivalDeque);
			processArrival(t, pArrivalDeque, pWaitDeque);
			customerNumber++;
		}
		if (service && t == service->man.startTime + service->man.serviceTime)
			service = processServiceNodeEnd(t, service);
		if (service == NULL)
			service = processServiceNodeStart(t, pWaitDeque);
		printWaitQueueStatus(t, pWaitDeque);
		if (pWaitDeque->currentElementCount != 0)
			waitTime++;	
		t++;
	}
	printReport(pWaitDeque, customerNumber, waitTime);
	return (0);
}