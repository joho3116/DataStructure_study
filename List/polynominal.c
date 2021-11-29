# include "polynominal.h"
# include <stdio.h>
# include <stdlib.h>

int addPolyNodeLast(LinkedList* pList, float coef, int degree)
{
    ListNode node;
    int ret;
    int i;

    ret = FALSE;
    i = 0;
    if (pList == NULL)
        return (ret);
    node.coef = coef;
    node.deg = degree;
    i = getLinkedListLength(pList);
    ret = addLLElement(pList, i, node);
    return (ret);
}

LinkedList  *addPoly(LinkedList* A, LinkedList* B)
{
    ListNode *pA;
    ListNode *pB;
    LinkedList *ANS;
    int sum;

    ANS = createLinkedList();
    sum = 0;
    if (A == NULL || B == NULL)
        return (NULL);
    pA = A->headerNode.pLink;
    pB = B->headerNode.pLink;
    while (pA && pB)
    {
        if (pA->deg == pB->deg)
        {
            sum = pA->coef + pB->coef;
            addPolyNodeLast(ANS, sum, pA->deg);
            pA = pA->pLink;
            pB = pB->pLink;
        }
        else if (pA->deg > pB->deg)
        {
            addPolyNodeLast(ANS, pA->coef, pA->deg);
            pA = pA->pLink;
        }
        else
        {
            addPolyNodeLast(ANS, pB->coef, pB->deg);
            pB = pB->pLink;
        }
    }
    while (pA)
    {
        addPolyNodeLast(ANS, pA->coef, pA->deg);
        pA = pA->pLink;
    }
    while (pB)
    {
        addPolyNodeLast(ANS, pB->coef, pB->deg);
        pB = pB->pLink;
    }
    return (ANS);
}

void    PrintPoly(LinkedList *pList)
{
    int len;
    int i;

    len = getLinkedListLength(pList);
    i = 0;
    printf("len is %d\n", pList->currentElementCount);
    while (i < len)
    {
        printf("%3.0fX^%d", getLLElement(pList, i)->coef, getLLElement(pList, i)->deg);
        i++;
    }
    printf("\n");
}

int main()
{
    LinkedList *A;
    LinkedList *B;
    LinkedList *C;

    A = createLinkedList();
    B = createLinkedList();

    addPolyNodeLast(A, 3, 4);
    addPolyNodeLast(A, 6, 4);
    addPolyNodeLast(A, 4, 3);
    addPolyNodeLast(A, 7, 1);
    addPolyNodeLast(A, 9, 0);
    addPolyNodeLast(B, -3, 4);
    addPolyNodeLast(B, 4, 2);
    addPolyNodeLast(B, 3, 1);
    C = addPoly(A, B);
    PrintPoly(A);
    PrintPoly(B);
    PrintPoly(C);
    return(0);
}
