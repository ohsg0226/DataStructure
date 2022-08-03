//
//  ALGraphDFS.c
//  Graph
//
//  Created by 오승기 on 2022/08/03.
//

#include "ALGraphDFS.h"
#include "ArrayBaseStack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int WhoIsPrecede(int data1, int data2);

void GraphInit(ALGraph *pg, int nv)
{
  
  pg -> adjList = (LinkedList *)malloc(sizeof(LinkedList)*nv);
  pg -> numE = 0;
  pg -> numV = nv;
  
  for(int i=0; i<nv; i++) {
    ListInit(&(pg -> adjList[i]));
    SetSortRule(&(pg -> adjList[i]), WhoIsPrecede);
  }
  
  pg -> visitInfo = (int *)malloc(sizeof(int) * pg -> numV);
  memset(pg -> visitInfo, 0, sizeof(int) * pg -> numV);
}

void GraphDestroy(ALGraph *pg)
{
  if(pg -> adjList != NULL) {
    free(pg -> adjList);
  }
  
  if(pg -> visitInfo != NULL) {
    free(pg -> visitInfo);
  }
}

void AddEdge(ALGraph *pg, int fromV, int toV)
{
  LInsert(&(pg -> adjList[fromV]), toV);
  LInsert(&(pg -> adjList[toV]), fromV);
  pg -> numE += 1;
}

void ShowGraphEdgeInfo(ALGraph *pg)
{
  int vx;
  
  for(int i=0; i<pg->numV; i++) {
    printf("%c와 연결된 정점: ", i + 65);
    
    if(LFirst(&(pg->adjList[i]), &vx)) {
      printf("%c ", vx + 65);
      
      while (LNext(&(pg->adjList[i]), &vx)) {
        printf("%c ", vx + 65);
      }
    }
    printf("\n");
  }
}

int WhoIsPrecede(int data1, int data2)
{
  if(data1 < data2) { return 0; }
  else { return 1; }
}

void DFShowGraphVertex(ALGraph *pg, int startV)
{
  Stack stack;
  int visitV = startV;
  int nextV;
  
  StackInit(&stack);
  VisitVertex(pg, visitV);
  SPush(&stack, visitV);
  
  while (LFirst(&(pg -> adjList[visitV]), &nextV) == TRUE) {
    int visitFlag = FALSE;
    
    if(VisitVertex(pg, nextV) == TRUE) {
      SPush(&stack, nextV);
      visitV = nextV;
      visitFlag = TRUE;
    } else {
      while (LFirst(&(pg -> adjList[visitV]), &nextV) == TRUE) {
        if(VisitVertex(pg, nextV) == TRUE) {
          SPush(&stack, visitV);
          visitV = nextV;
          visitFlag = TRUE;
          break;
        }
      }
    }
    
    if(visitFlag == FALSE) {
      if(SIsEmpty(&stack) == TRUE) { break; }
      else { visitV = SPop(&stack); }
    }
  }
  
  memset(pg -> visitInfo, 0, sizeof(int) * pg -> numV);
}

int VisitVertex(ALGraph *pg, int visitV)
{
  if(pg -> visitInfo[visitV] == 0) {
    pg -> visitInfo[visitV] = 1;
    printf("%c ", visitV + 65);
    return TRUE;
  }
  return FALSE;
}
