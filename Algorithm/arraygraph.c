#include "arraygraph.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

ArrayGraph* createArrayGraph(int maxVertexCount)
{
    int i;
    ArrayGraph *pGraph;
    int *Vertex;
    int **pAdjEdge;

    i = 0;
    if (!(pGraph = malloc(sizeof(ArrayGraph))))
        return (NULL);
    if (!(Vertex = malloc(sizeof(int) * maxVertexCount)))
        return (NULL);
    if (!(pAdjEdge = malloc(sizeof(int *) * maxVertexCount)))
        return (NULL);
    while (i < maxVertexCount)
    {
        if (!(pAdjEdge[i] = malloc(sizeof(int) * maxVertexCount)))
            return (NULL);
        memset(pAdjEdge[i], 0, sizeof(int) * maxVertexCount);
        i++;
    }
    pGraph->maxVertexCount = maxVertexCount;
    pGraph->currentVertexCount = 0;
    pGraph->graphType = GRAPH_UNDIRECTED;
    pGraph->pVertex = Vertex;
    pGraph->EdgeCnt = 0;
    pGraph->ppAdjEdge = pAdjEdge;
    return (pGraph);
}

ArrayGraph* createArrayDirectedGraph(int maxVertexCount)
{
    ArrayGraph *pGraph;
    int *Vertex;
    int *pEdge;
    int **pAdjEdge;
    int i;

    i = 0;
    if (!(pGraph = malloc(sizeof(ArrayGraph))))
        return (NULL);
    if (!(Vertex = malloc(sizeof(int) * maxVertexCount)))
        return (NULL);
    if (!(pAdjEdge = malloc(sizeof(int *) * maxVertexCount)))
        return (NULL);
    while (i < maxVertexCount)
    {
        if (!(pAdjEdge[i] = malloc(sizeof(int) * maxVertexCount)))
            return (NULL);
        memset(pAdjEdge[i], 0, sizeof(int) * maxVertexCount);
        i++;
    }
    pGraph->maxVertexCount = maxVertexCount;
    pGraph->currentVertexCount = 0;
    pGraph->graphType = GRAPH_DIRECTED;
    pGraph->pVertex = Vertex;
    pGraph->ppAdjEdge = pAdjEdge;
    return (pGraph);
}
// 그래프 삭제
void deleteArrayGraph(ArrayGraph* pGraph)
{
    if (pGraph == NULL)
        return ;
    if (!pGraph->pVertex)
        free(pGraph->pVertex);
    if (!pGraph->pVertex)
        free(pGraph->pVertex);
    if (!pGraph->ppAdjEdge)
    {
        for (int i = 0; i < pGraph->maxVertexCount; i++)
            free(pGraph->ppAdjEdge[i]);
        free(pGraph->ppAdjEdge);
    }
    return ;
}
// 공백 그래프 여부 판단
int isEmptyAG(ArrayGraph* pGraph)
{
    int ret;

    ret = FALSE;
    if (pGraph == NULL)
        return (ret);
    if (pGraph->currentVertexCount == 0)
        ret = TRUE;
    return (ret);
}

// 노드 추가
int addVertexAG(ArrayGraph* pGraph, int vertexID)
{
    int ret;
    int i;

    ret = FALSE;
    if (pGraph != NULL && checkVertexValid(pGraph, vertexID))
    {
        pGraph->pVertex[vertexID] = vertexID;
        pGraph->currentVertexCount++;
        ret = TRUE;
    }
    return (ret);
}

// 간선 추가
int addEdgeAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID)
{
    int ret;

    ret = FALSE;
    if (pGraph != NULL && checkVertexValid(pGraph, fromVertexID) && checkVertexValid(pGraph, toVertexID))
    {
        pGraph->ppAdjEdge[fromVertexID][toVertexID] = 1;
        ret = TRUE;
    }
    if (pGraph->graphType == GRAPH_UNDIRECTED)
    {
        pGraph->ppAdjEdge[toVertexID][fromVertexID] = 1;
    }
    return (ret);
}
int addEdgewithWeightAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID, int weight)
{
    int ret;

    ret = FALSE;
    if (pGraph != NULL && checkVertexValid(pGraph, fromVertexID) && checkVertexValid(pGraph, toVertexID))
    {
        pGraph->ppAdjEdge[fromVertexID][toVertexID] = weight;
        ret = TRUE;
        pGraph->EdgeCnt++;
    }
    if (pGraph->graphType == GRAPH_UNDIRECTED)
        pGraph->ppAdjEdge[toVertexID][fromVertexID] = weight;
    return (ret);
}

// 노드의 유효성 점검.
int checkVertexValid(ArrayGraph* pGraph, int vertexID)
{
    int ret;

    ret = FALSE;

    if (pGraph != NULL && vertexID < pGraph->maxVertexCount && vertexID >= 0)
        ret = TRUE;
    return (ret);
}

// 노드 제거
int removeVertexAG(ArrayGraph* pGraph, int vertexID)
{
    int ret;

    ret = FALSE;
    if (pGraph != NULL && checkVertexValid(pGraph, vertexID))
    {
        for (int i = 0; i < pGraph->maxVertexCount; i++)
        {
            pGraph->ppAdjEdge[i][vertexID] = 0;
        }
        pGraph->pVertex[vertexID] = 0;
        pGraph->currentVertexCount--;
        ret = TRUE;
    }
    return (ret);
}

int removeEdgeAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID)
{
    int ret;

    ret = FALSE;
    if (pGraph != NULL && checkVertexValid(pGraph, fromVertexID) && checkVertexValid(pGraph, toVertexID))
    {
        pGraph->ppAdjEdge[fromVertexID][toVertexID] = 0;
        ret = TRUE;
    }
    if (pGraph->graphType == GRAPH_UNDIRECTED)
        pGraph->ppAdjEdge[toVertexID][fromVertexID] = 0;
    pGraph->EdgeCnt--;
    return (ret);
}

int getEdgeAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID)
{
    int ret;

    ret = -1;
    if (pGraph != NULL && checkVertexValid(pGraph, fromVertexID) && checkVertexValid(pGraph, toVertexID))
        ret = pGraph->ppAdjEdge[fromVertexID][toVertexID];
    return (ret);
}

void displayArrayGraph(ArrayGraph* pGraph)
{
    int i;
    int j;
    int cnt;

    i = 0;
    j = 0;
    cnt = 0;
    if (pGraph != NULL)
    {
        cnt = pGraph->maxVertexCount;
        for (i = 0; i < cnt; i++)
        {
            for (j = 0; j < cnt; j++)
                printf("[%d]", getEdgeAG(pGraph, i, j));
        printf("\n");
        }
    }
}

// int main() 
// {
//     int Vertexcount;
//     int *parent;
//     ArrayGraph *Graph;

//     Vertexcount = 7;
//     Graph = createArrayGraph(Vertexcount);
//     addVertexAG(Graph, 1);
//     addVertexAG(Graph, 2);
//     addVertexAG(Graph, 3);
//     addVertexAG(Graph, 4);
//     addVertexAG(Graph, 5);
//     addVertexAG(Graph, 6);
//     addVertexAG(Graph, 7);
//     addEdgewithWeightAG(Graph, 1, 2, 67);
//     addEdgewithWeightAG(Graph, 1, 5, 17);
//     addEdgewithWeightAG(Graph, 1, 4, 28);
//     addEdgewithWeightAG(Graph, 1, 7, 12);
//     addEdgewithWeightAG(Graph, 2, 4, 24);
//     addEdgewithWeightAG(Graph, 2, 5, 62);
//     addEdgewithWeightAG(Graph, 3, 5, 20);
//     addEdgewithWeightAG(Graph, 3, 6, 37);
//     addEdgewithWeightAG(Graph, 4, 7, 13);
//     addEdgewithWeightAG(Graph, 5, 7, 73);
//     addEdgewithWeightAG(Graph, 5, 6, 45);
//     displayArrayGraph(Graph);
//     deleteArrayGraph(Graph);
//         return (0);
// }