#include "arraystack.h"
#include "stdio.h"

int main()
{
    ArrayStack *stack;
    ArrayStackNode node;
    int i;

    stack = createArrayStack(5);
    i = 0;
    node.data = 'a';
    pushAS(stack, node);
    node.data = 'b';
    pushAS(stack, node);
    node.data = 'c';
    pushAS(stack, node);
    node.data = 'd';
    pushAS(stack, node);
    popAS(stack);
    node.data = 'e';
    pushAS(stack, node);
    node.data = 'f';
    pushAS(stack, node);
    printArrayStack(stack);
    printf("peek data is == %c\n", peekAS(stack)->data);
    return (0);
}