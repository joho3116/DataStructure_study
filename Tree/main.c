#include "bintree.h"
#include <stdlib.h>
#include <stdio.h>


int main()
{
    BinTree *Tree;
    BinTreeNode root;
    BinTreeNode child;

    root.data = 'A';
    Tree = makeBinTree(root);
    child.data = 'B';
    Tree->pRootNode = insertLeftChildNodeBT(&root, child);
    child.data = 'C';
    Tree->pRootNode = insertRightChildNodeBT(&root, child);
    child.data = 'D';
    Tree->pRootNode->pLeftChild = insertLeftChildNodeBT(Tree->pRootNode->pLeftChild, child);
    child.data = 'E';
    Tree->pRootNode->pLeftChild = insertRightChildNodeBT(Tree->pRootNode->pLeftChild, child);
    child.data = 'F';
    Tree->pRootNode->pRightChild = insertLeftChildNodeBT(Tree->pRootNode->pRightChild, child);
    child.data = 'G';
    Tree->pRootNode->pRightChild = insertRightChildNodeBT(Tree->pRootNode->pRightChild, child);
    child.data = 'H';
    Tree->pRootNode->pLeftChild->pLeftChild = insertLeftChildNodeBT(Tree->pRootNode->pLeftChild->pLeftChild, child);
    child.data = 'I';
    Tree->pRootNode->pLeftChild->pLeftChild = insertRightChildNodeBT(Tree->pRootNode->pLeftChild->pLeftChild, child);
    child.data = 'J';
    Tree->pRootNode->pLeftChild->pRightChild = insertLeftChildNodeBT(Tree->pRootNode->pLeftChild->pRightChild, child);
    child.data = 'K';
    Tree->pRootNode->pRightChild->pLeftChild = insertRightChildNodeBT(Tree->pRootNode->pRightChild->pLeftChild, child);
    child.data = 'L';
    Tree->pRootNode->pRightChild->pRightChild = insertLeftChildNodeBT(Tree->pRootNode->pRightChild->pRightChild, child);
    child.data = 'M';
    Tree->pRootNode->pRightChild->pRightChild = insertRightChildNodeBT(Tree->pRootNode->pRightChild->pRightChild, child);

    printf("====전위순회====\n\n");
    PreOrderSearch(Tree->pRootNode);
    printf("\n\n====중위순회====\n\n");
    InOrderSearch(Tree->pRootNode);
    printf("\n\n====후위순회====\n\n");
    PostOrderSearch(Tree->pRootNode);

}