//
//  ALGraphDFS.h
//  Graph
//
//  Created by 오승기 on 2022/08/03.
//

#ifndef ALGraphDFS_h
#define ALGraphDFS_h

#include "DLinkedList.h"

enum {A,B,C,D,E,F,G,H,I,J};

typedef struct _ual
{
  int numV;
  int numE;
  List *adjList;
  int *visitInfo;
} ALGraph;

void GraphInit(ALGraph *pg, int nv);
void GraphDestroy(ALGraph *pg);
void AddEdge(ALGraph *pg, int fromV, int toV);
void ShowGraphEdgeInfo(ALGraph *pg);
void DFShowGraphVertex(ALGraph *pg, int startV);

int VisitVertex(ALGraph *pg, int visitV);
#endif /* ALGraphDFS_h */
