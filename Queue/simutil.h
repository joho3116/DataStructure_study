#ifndef _SIM_UTIL_
#define _SIM_UTIL_

#include "linkeddeque.h"
#include "simdef.h"

// �� ���� ť�� �� �߰�.
void insertCutomer(int arrivalTime, int processTime, LinkedDeque *pDeque);

// �� ���� ó��.
void processArrival(int currentTime, LinkedDeque *pArrivalDeque, LinkedDeque *pWaitDeque);

// ���� ���� ó��.
DequeNode* processServiceNodeStart(int currentTime, LinkedDeque *pWaitDeque);

// ���� ���� ó��.
DequeNode* processServiceNodeEnd(int currentTime, DequeNode *pServiceNode);
// ���� ���¸� ���.
void printSimCustomer(int currentTime, SimCustomer customer);

// ��� ���� ���¸� ���.
void printWaitQueueStatus(int currentTime, LinkedDeque *pWaitDeque);

// ���� �ùķ��̼� ���(���ġ) ���.
void printReport(LinkedDeque *pWaitDeque, int serviceUserCount, int totalWaitTime);

#endif