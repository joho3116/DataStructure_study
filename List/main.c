#include "arraylist.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

	int i = 0, arrayCount = 0;

	ArrayList *pList = NULL;
	ArrayListNode *pValue = NULL;

	pList = createArrayList(6);

	if (pList != NULL) {
		ArrayListNode node;
		node.data = 1;
		addALElement(pList, 0, node);
		node.data = 3;
		addALElement(pList, 1, node);
		node.data = 5;
		addALElement(pList, 2, node);
		node.data = 4;
		addALElement(pList, 2, node);
		node.data = 6;
		addALElement(pList, 4, node);
		node.data = 2;
		addALElement(pList, 1, node);
		displayArrayList(pList);
		removeALElement(pList, 0);
		removeALElement(pList, 5);
		displayArrayList(pList);
		arrayCount = getArrayListLength(pList);
		for (i = 0; i < arrayCount; i++) {
			pValue = getALElement(pList, i);
			printf("ArrayList[%d]-%d\n", i, pValue->data);
		}
		clearArrayList(pList);
		displayArrayList(pList);
		deleteArrayList(pList);
	}
	return (0);
}
