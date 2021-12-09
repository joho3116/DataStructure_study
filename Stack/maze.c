#include "linkedstack.h"
#include <stdio.h>
#include <stdlib.h>

#define HEIGHT 8
#define WIDTH 8

#define ROAD 0
#define WALL 1
#define VISITED 2

int	dir[4][2] = {
	{1, 0},
	{0, 1},
	{0, -1},
	{-1, 0}
};

int	mazeArray[HEIGHT][WIDTH] = {
	{0, 0, 1, 1, 1, 1 ,1 ,1},
	{1, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 1, 0, 1, 1, 1, 1},
	{1, 1, 1, 0, 1, 1, 1, 1},
	{1, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 0, 0, 0, 0},
	{1, 1, 1, 1, 1, 1, 1, 0}
};


int	findPath(int mazeArray[HEIGHT][WIDTH], MapPosition startPos, MapPosition endPos, LinkedStack *pStack)
{
	MapPosition currentPos;
	int	i;

	i = 0;
	pushLSMapPosition(pStack, startPos);
	currentPos = startPos;
	mazeArray[currentPos.y][currentPos.x] = VISITED;
	while (i < 4)
	{
		currentPos.x = startPos.x + dir[i][0];
		currentPos.y = startPos.y + dir[i][1];
		if ((currentPos.x >= 0 && currentPos.x < HEIGHT) && (currentPos.y >= 0 && currentPos.y < WIDTH))
		{
			if (mazeArray[currentPos.y][currentPos.x] == ROAD)
				if (findPath(mazeArray, currentPos, endPos, pStack))
					return (TRUE);
		}
		i++;
	}
	if (!(startPos.x == endPos.x && startPos.y == endPos.y))
	{
		free(popLS(pStack));
		return (FALSE);
	}
	return (TRUE);
}

int	pushLSMapPosition(LinkedStack *pStack, MapPosition pos)
{
	int	ret;
	StackNode *node;

	ret = FALSE;
	if (pStack == NULL)
		return (ret);
	if (!(node = malloc(sizeof(StackNode))))
		return (ret);
	node->pos.x = pos.x;
	node->pos.y = pos.y;
	node->pLink = pStack->pTopElement->pLink;
	pStack->pTopElement->pLink = node;
	pStack->currentElementCount++;
	ret = TRUE;
	return (ret);
}

void	showPath(LinkedStack *pStack, int mazeArray[HEIGHT][WIDTH])
{
	StackNode *node;

	node = NULL;
	if (pStack == NULL)
		return ;
	if (pStack->currentElementCount == 0)
		return ;
	node = pStack->pTopElement->pLink;
	printf("=======Stack========\n\n");
	printf("Element count is == %d\n\n", pStack->currentElementCount);
	while (node != NULL)
	{
		printf("{%d, %d}\n", node->pos.x, node->pos.y);
		node = node->pLink;
	}
	printf("===================\n\n");
}

void	printMaze(int mazeArray[HEIGHT][WIDTH])
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	printf("==========MAP==========\n\n");
	while (i < HEIGHT)
	{
		while (j < WIDTH)
		{
			if (mazeArray[i][j] == WALL)
				printf(" ◼︎ ");
			else if (mazeArray[i][j] == VISITED)
				printf(" 2 ");
			else if (mazeArray[i][j] == ROAD)
				printf(" 1 ");
			j++;
		}
		j = 0;
		i++;
		printf("\n");
	}
	printf("========================\n\n");
}

void	init_info(LinkedStack *pStack, MapPosition startPos, MapPosition endPos)
{
	pStack = createLinkedStack();
	startPos.x = 0;
	startPos.y = 0;
	endPos.x = 7;
	endPos.y = 7;
}

int	main()
{
	LinkedStack *pStack;
	MapPosition startPos;
	MapPosition endPos;

	pStack = createLinkedStack();
	startPos.x = 0;
	startPos.y = 0;
	endPos.x = 7;
	endPos.y = 7;
	printMaze(mazeArray);
	findPath(mazeArray, startPos, endPos, pStack);
	showPath(pStack, mazeArray);
	printMaze(mazeArray);

	return (0);
}
