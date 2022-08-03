//
//  ALGraph.c
//  Graph
//
//  Created by 오승기 on 2022/08/03.
//

#include "ALGraph.h"
#include <stdio.h>
#include <stdlib.h>

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
}

void GraphDestroy(ALGraph *pg)
{
  if(pg -> adjList != NULL) {
    free(pg -> adjList);
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
