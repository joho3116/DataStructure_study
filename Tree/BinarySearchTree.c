#include "binsearchtree.h"

// 이진 탐색 트리의 조건
// 1. key는 유일한 값이다
// 2. root의 key는 왼쪽 서브트리의 어떠한 key보다도 크다
// 3. root의 key는 오른쪽 서브트리의 어떠한 key보다도 작다
// 4. 왼쪽과 오른쪽 서브트리도 이진 탐색 트리이다

// search, insert, delete의 시간복잡도
// General Case : O(height)
// Worst Case : O(n) (트리의 꼴이 리니어, 즉 링크드 리스트와 같은 경우)
// Best Case : O(log n) (포화 이진 트리일 경우 height는 log2 n이 됨0

BinSearchTree* createBinSearchTree(BinSearchTreeNode element)
{
	BinSearchTree *pBinSearchTree;

	pBinSearchTree = (BinSearchTree *)malloc(sizeof(BinSearchTree));
	if (!pBinSearchTree)
		return (NULL);
	pBinSearchTree->pRootNode = (BinSearchTreeNode *)malloc(sizeof(BinSearchTreeNode));
	if (!pBinSearchTree->pRootNode)
	{
		free(pBinSearchTree);
		return (NULL);
	}
	pBinSearchTree->pRootNode->key = element.key;
	pBinSearchTree->pRootNode->value = element.value;
	pBinSearchTree->pRootNode->pLeftChild = NULL;
	pBinSearchTree->pRootNode->pRightChild = NULL;
	return (pBinSearchTree);
}

BinSearchTreeNode *createNode(BinSearchTreeNode element)
{
	BinSearchTreeNode *pNode;

	pNode = (BinSearchTreeNode *)malloc(sizeof(BinSearchTreeNode));
	if (!pNode)
		return (NULL);
	pNode->key = element.key;
	pNode->value = element.value;
	pNode->pLeftChild = NULL;
	pNode->pRightChild = NULL;
	return (pNode);
}

BinSearchTreeNode *insertElementBST(BinSearchTreeNode* pRoot, BinSearchTreeNode element)
{
	if (!pRoot)
		return (createNode(element));

	if (element.key < pRoot->key)
		pRoot->pLeftChild = insertElementBST(pRoot->pLeftChild, element);
	else if (element.key > pRoot->key)
		pRoot->pRightChild = insertElementBST(pRoot->pRightChild, element);
	return (pRoot);
}

BinSearchTreeNode *getMinKeyNode(BinSearchTreeNode *pNode)
{
	BinSearchTreeNode *temp;

	temp = pNode;
	while (temp->pLeftChild)
	{
		temp = temp->pLeftChild;
	}
	return (temp);
}

BinSearchTreeNode *deleteElementBST(BinSearchTreeNode* pRoot, int key)
{
    BinSearchTreeNode *tmp;

	if (!pRoot)
		return (NULL);
	if (key < pRoot->key)
		pRoot->pLeftChild = deleteElementBST(pRoot->pLeftChild, key);
	else if (key > pRoot->key)
		pRoot->pRightChild = deleteElementBST(pRoot->pRightChild, key);
	else
	{
		if (pRoot->pLeftChild == NULL)
		{
			temp = pRoot->pRightChild;
			free(pRoot);
			return (temp);
		}
		else if (pRoot->pRightChild == NULL)
		{
			temp = pRoot->pLeftChild;
			free(pRoot);
			return (temp);
		}
		temp = getMinKeyNode(pRoot->pRightChild);
		pRoot->key = temp->key;
		pRoot->pRightChild = deleteElementBST(pRoot->pRightChild, temp->key);
	}
	return (pRoot);
}

/*
BinSearchTreeNode* searchRecursiveBST(BinSearchTree* pBinSearchTree, int key)
{
}
BinSearchTreeNode* searchInternalRecursiveBST(BinSearchTreeNode* pTreeNode, int key)
{
}
*/

BinSearchTreeNode* searchBST(BinSearchTreeNode* pRoot, int key)
{
	BinSearchTreeNode *ret;

	ret = pRoot;
	while (ret)
	{
		if (ret->key == key)
			break ;
		else if (key < ret->key)
			ret = ret->pLeftChild;
		else
			ret = ret->pRightChild;
	}
	return (ret);
}

void inorderTraversalBST(BinSearchTreeNode *pNode)
{
	if (!pNode)
		return ;
	inorderTraversalBST(pNode->pLeftChild);
	printf("%d\n", pNode->key);
	inorderTraversalBST(pNode->pRightChild);
}

// Postorder로 지워줌
void deleteBinSearchTreeNode(BinSearchTreeNode* pRoot)
{
	if (!pRoot)
		return ;
	deleteBinSearchTreeNode(pRoot->pLeftChild);
	deleteBinSearchTreeNode(pRoot->pRightChild);
	free(pRoot);
}

void deleteBinSearchTree(BinSearchTree* pBinSearchTree)
{
	if (!pBinSearchTree)
		return ;
	deleteBinSearchTreeNode(pBinSearchTree->pRootNode);
	free(pBinSearchTree);
}