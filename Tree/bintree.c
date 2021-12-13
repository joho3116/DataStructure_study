#include "bintree.h"
#include "stdlib.h"
#include "stdio.h"

/* Binary Tree

이진탐색 (binary search)와 연결리스트를 결합한 자료구조의 일종
효율적인 탐색능력과 자료입력, 삭제가 가능한 형태

속성
1. 임의의 노드에서 다른 노드로 가는 경로는 유일하다.
2. 회로가 존재하지 않는다.
3. 모든 노드는 서로 연결되어있다.
4. 엣지를 하나 자르면 트리가 두개로 분리된다.


이진 탐색의 시간복잡도 Olog(n), 자료의 입력과 삭제가 불가
연결리스트의 자료입력, 삭제 시간복잡도 O(1), 탐색하는 데에는 O(n)의 시간복잡도

Searching

in-order(중위 순회) : 왼쪽 자식노드(L), 내 노드(P), 오른쪽 자식노드(R) 순서로 방문한다.
pre-order(전위 순회) : 내 노드(P), 왼쪽 자식노드(L), 오른쪽 자식노드(R) 순서로 방문한다.
post-order(후위 순회) : 왼쪽 자식노드(L), 오른쪽 자식노드(R), 내 노드(P) 순서로 방문한다.

*/

BinTree* makeBinTree(BinTreeNode rootNode)
{
    BinTree *pTree;
    BinTreeNode *pRoot;

    pTree = (BinTree *)malloc(sizeof(BinTree));
    if (pTree == NULL)
        return (NULL);
    pRoot = (BinTreeNode *)malloc(sizeof(BinTreeNode));
    if (pTree == NULL)
    {
        free(pTree);
        return (NULL);
    }
    pTree->pRootNode = pRoot;
    pTree->pRootNode->data = rootNode.data;
    pTree->pRootNode->pLeftChild = NULL;
    pTree->pRootNode->pRightChild = NULL;
    pTree->pRootNode->visited = 0;
    return (pTree);
}
BinTreeNode* getRootNodeBT(BinTree* pBinTree)
{
    if (pBinTree == NULL)
        return (NULL);
    return (pBinTree->pRootNode);
}
BinTreeNode* insertLeftChildNodeBT(BinTreeNode* pParentNode, BinTreeNode element)
{
    BinTreeNode *node;

    if (pParentNode == NULL || pParentNode->pLeftChild != NULL)
        return (NULL);
    node = malloc(sizeof(BinTreeNode));
    if (node == NULL)
        return (NULL);
    node->data = element.data;
    node->pLeftChild = NULL;
    node->pRightChild = NULL;
    node->visited = 0;
    pParentNode->pLeftChild = node;
    return (pParentNode);
}
BinTreeNode* insertRightChildNodeBT(BinTreeNode* pParentNode, BinTreeNode element)
{
    BinTreeNode *node;

    if (pParentNode == NULL || pParentNode->pRightChild != NULL)
        return (NULL);
    node = malloc(sizeof(BinTreeNode));
    if (node == NULL)
        return (NULL);
    node->data = element.data;
    node->pLeftChild = NULL;
    node->pRightChild = NULL;
    node->visited = 0;
    pParentNode->pRightChild = node;
    return (pParentNode);
}

BinTreeNode* getLeftChildNodeBT(BinTreeNode* pNode)
{
    if (pNode == NULL || pNode->pLeftChild == NULL)
        return (NULL);
    return (pNode->pLeftChild);
}

BinTreeNode* getRightChildNodeBT(BinTreeNode* pNode)
{
    if (pNode == NULL || pNode->pRightChild == NULL)
        return (NULL);
    return (pNode->pRightChild); 
}

void deleteBinTree(BinTree* pBinTree)
{
    
}

void deleteBinTreeNode(BinTreeNode* pNode)
{
    if(pNode->pLeftChild != NULL || pNode->pRightChild != NULL)
        return ;
    return (free(pNode));
}

void    PreOrderSearch(BinTreeNode *pParentNode)
{
    if (pParentNode == NULL)
        return ;
    pParentNode->visited++;
    printf("data is == %c, visited is == %d\n", pParentNode->data, pParentNode->visited);
    PostOrderSearch(getLeftChildNodeBT(pParentNode));
    PostOrderSearch(getRightChildNodeBT(pParentNode));
}

void    InOrderSearch(BinTreeNode *pParentNode)
{
    if (pParentNode == NULL)
        return ;
    InOrderSearch(getLeftChildNodeBT(pParentNode));
    pParentNode->visited++;
    printf("data is == %c, visited is == %d\n", pParentNode->data, pParentNode->visited);
    InOrderSearch(getRightChildNodeBT(pParentNode));
}

void    PostOrderSearch(BinTreeNode *pParentNode)
{
    if (pParentNode == NULL)
        return ;
    PostOrderSearch(getLeftChildNodeBT(pParentNode));
    PostOrderSearch(getRightChildNodeBT(pParentNode));
    pParentNode->visited++;
    printf("data is == %c, visited is == %d\n", pParentNode->data, pParentNode->visited);
}