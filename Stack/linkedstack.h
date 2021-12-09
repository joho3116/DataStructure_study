#ifndef _LINKED_STACK_
#define _LINKED_STACK_

#define HEIGHT 8
#define WIDTH 8

#define EMPTY 0
#define WALL 1
#define VISITED 2

#include <stdlib.h>


typedef struct MapPosition
{
	int	x;
	int	y;

}	MapPosition;

typedef struct StackNodeType
{
	MapPosition pos;
	struct StackNodeType* pLink;
} StackNode;

typedef struct LinkedStackType
{
	int currentElementCount;	// ���� ������ ����
	StackNode* pTopElement;		// Top ����� ������
} LinkedStack;

LinkedStack* createLinkedStack();
int pushLS(LinkedStack* pStack, StackNode element);
StackNode* popLS(LinkedStack* pStack);
StackNode* peekLS(LinkedStack* pStack);
void deleteLinkedStack(LinkedStack* pStack);
int isLinkedStackFull(LinkedStack* pStack);
int isLinkedStackEmpty(LinkedStack* pStack);

int	findPath(int mazeArray[HEIGHT][WIDTH], MapPosition startPos, MapPosition endPos, LinkedStack *pStack);
int	pushLSMapPosition(LinkedStack *pStack, MapPosition pos);
void	showPath(LinkedStack *pStack, int mazeArray[HEIGHT][WIDTH]);
void	printMaze(int mazeArray[HEIGHT][WIDTH]);
void	init_info(LinkedStack *pStack, MapPosition startPos, MapPosition endPos);


#endif

#ifndef _COMMON_STACK_DEF_
#define _COMMON_STACK_DEF_

#define TRUE		1
#define FALSE		0

#endif
