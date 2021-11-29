#ifndef _POLYNOMINAL_
#define _POLYNOMINAL_

#include "linkedlist.h"


void    PrintPoly(LinkedList *pList);
int addPolyNodeLast(LinkedList* pList, float coef, int degree);
LinkedList  *addPoly(LinkedList* A,LinkedList* B);

#endif
