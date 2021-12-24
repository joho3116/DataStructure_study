#include "arraygraph.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 크루스칼 알고리즘

그래프 내 모든 정점들을 가장 적은 비용으로 연결하기 위해 사용 (최소신장트리)

1. 그래프 내의 모든 정점을 포함하고
2. 사이클이 없는 간선을 그렸을 때,
3. 가중치의 합이 최소가 되는 상황

최소신장트리는 정점의 갯수가 n개일 때, 간선이 n-1개


크루스칼 알고리즘 Process

1. 간선들을 가중치의 오름차순으로 정렬
2. 사이클을 형성하지 않는 선에서 정렬된 순서대로 간선을 선택

사이클은 어떻게 판단? <Union & Find>

간선으로 연결했을 때, 각 정점 집합의 루트노드를 확인하고, 루트 노드가 다른 경우 합친다.
이 때, 집합 내에 제일 작은 숫자를 그 집합에서의 루트노드가 되게끔 가정

*/

int    *initParent(ArrayGraph *pGraph)
{
    int *parent;

    parent = malloc(sizeof(int) * pGraph->currentVertexCount);
    for (int i = 0; i < pGraph->currentVertexCount; i++)
        parent[i] = pGraph->pVertex[i];
    return (parent);
}

int getParent(int *parent, int x)
{
    if (parent[x] == x)
        return (x);
    return (parent[x] = getParent(parent, parent[x]));
}

void    unionParent(int *parent, int a, int b)
{
    a = getParent(parent, a);
    b = getParent(parent, b);

    if (a < b)
        parent[b] = a;
    else
        parent[a] = b;
}

int findParent(int *parent, int a, int b)
{
    int ret;

    ret = FALSE;
    a = getParent(parent, a);
    b = getParent(parent, b);
    if (a == b)
        ret = TRUE;
    return (ret);
}

void    deleteParent(int *parent)
{
    free(parent);
}


int    *initEdges(ArrayGraph *pGraph)
{
    int cnt;
    int *edges;
    int k;

    cnt = 0;
    edges = malloc(sizeof(int) * pGraph->EdgeCnt);
    memset(edges, 0, sizeof(int) * pGraph->EdgeCnt);
    for (int i = 0; i < pGraph->maxVertexCount; i++)
    {
        for (int j = 0; j < pGraph->maxVertexCount; j++)
        {
            if (pGraph->ppAdjEdge[i][j] != 0)
            {
                if (edges[cnt] != pGraph->ppAdjEdge[i][j])
                        edges[cnt++] = pGraph->ppAdjEdge[i][j];
            }
            if (j == i)
                break ;
        }
    }
    return (edges);
}

void    ascendingSortEdges(int *edges, int n)
{   
    int tmp;

    for (int i = n-1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (edges[j] > edges[j+1])
            {
                tmp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = tmp;
            }
        }
    }

}

int main() 
{
    int Vertexcount;
    int *parent;
    int *Edges;
    int EdgeCnt;
    int sum;
    ArrayGraph *Graph;

    Vertexcount = 7;
    EdgeCnt = 0;
    sum = 0;
    printf("==============================\n\n");
    printf("KRUSKAL START\n\n");
    printf("==============================\n\n");
    Graph = createArrayGraph(Vertexcount);
    addVertexAG(Graph, 0);
    addVertexAG(Graph, 1);
    addVertexAG(Graph, 2);
    addVertexAG(Graph, 3);
    addVertexAG(Graph, 4);
    addVertexAG(Graph, 5);
    addVertexAG(Graph, 6);
    for(int j = 0; j < Graph->currentVertexCount; j++)
        printf("index [%d] is == %d\n", j, Graph->pVertex[j]);
    addEdgewithWeightAG(Graph, 0, 1, 67);
    addEdgewithWeightAG(Graph, 0, 3, 28);
    addEdgewithWeightAG(Graph, 0, 4, 17);
    addEdgewithWeightAG(Graph, 0, 6, 12);
    addEdgewithWeightAG(Graph, 1, 3, 24);
    addEdgewithWeightAG(Graph, 1, 4, 62);
    addEdgewithWeightAG(Graph, 2, 4, 20);
    addEdgewithWeightAG(Graph, 2, 5, 37);
    addEdgewithWeightAG(Graph, 3, 6, 13);
    addEdgewithWeightAG(Graph, 4, 5, 45);
    addEdgewithWeightAG(Graph, 4, 6, 73);
    displayArrayGraph(Graph);

    
    parent = initParent(Graph);
    printf("===========================\n");
    printf("current Edge cnt is == %d\n", Graph->EdgeCnt);
    for (int i = 0; i < Graph->currentVertexCount; i++)
        printf("parent[%d] is == %d\n", i, parent[i]);    
    displayArrayGraph(Graph);
    Edges = initEdges(Graph);
    for (int i = 0; i < Graph->EdgeCnt; i++)
        printf("edges[%d] is %d\n", i, Edges[i]);
    ascendingSortEdges(Edges, Graph->EdgeCnt);
    printf("=======after sort============\n");
    for (int i = 0; i < Graph->EdgeCnt; i++)
        printf("edges[%d] is %d\n", i, Edges[i]);
    for (int k = 0; k < 11; k++)
    {
        for (int i = 0; i < Graph->currentVertexCount; i++)
        {
            for (int j = 0; j < Graph->currentVertexCount; j++)
            {
                if (i == j)
                    break;
                if (Graph->ppAdjEdge[i][j] == Edges[EdgeCnt])
                {
                    if (!findParent(parent, i, j))
                    {
                        printf("i is == %d, j is == %d, Edge is == %d\n", i, j, Edges[EdgeCnt]);
                        for (int i = 0; i < Graph->currentVertexCount; i++)
                            printf("parent[%d] is == %d\n", i, parent[i]);
                        unionParent(parent, i, j);
                        printf("==========after union===========\n");
                        for (int i = 0; i < Graph->currentVertexCount; i++)
                            printf("parent[%d] is == %d\n", i, parent[i]);
                        sum += Edges[EdgeCnt];
                    }
                    else
                        removeEdgeAG(Graph, i, j);
                }
            }
        }
        EdgeCnt++;
    }
    displayArrayGraph(Graph);
    for (int i = 0; i < Graph->currentVertexCount; i++)
        printf("parent[%d] is == %d\n", i, parent[i]);
    printf("sum is == %d\n", sum);
    deleteParent(parent);
    deleteParent(Edges);
    deleteArrayGraph(Graph);
    return (0);
}
