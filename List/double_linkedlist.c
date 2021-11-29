#include "doublylist.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

DoublyList* createDoublyList()
{
    DoublyList *list;

    if (!(list = (DoublyList *)malloc(sizeof(DoublyList))))
        return (NULL);
    list->currentElementCount = 0;
    list->headerNode.pLLink = NULL;
    list->headerNode.pRLink = NULL;
    return (list);
}


void deleteDoublyList(DoublyList* pList)
{

}
int addDLElement(DoublyList* pList, int position, DoublyListNode element)
{

}
int removeDLElement(DoublyList* pList, int position)
{

}
void clearDoublyList(DoublyList* pList)
{

}
int getDoublyListLength(DoublyList* pList)
{

}
DoublyListNode* getDLElement(DoublyList* pList, int position)
{

}
void displayDoublyList(DoublyList* pList)
{
    
}