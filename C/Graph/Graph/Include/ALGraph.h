//
//  ALGraph.h
//  Graph
//
//  Created by 오승기 on 2022/08/03.
//

#ifndef ALGraph_h
#define ALGraph_h

#include "ALGraph.h"
#include "DLinkedList.h"

enum {A,B,C,D,E,F,G,H,I,J};

typedef struct _ual
{
  int numV;
  int numE;
  List *adjList;
} ALGraph;

void GraphInit(ALGraph *pg, int nv);
void GraphDestroy(ALGraph *pg);
void AddEdge(ALGraph *pg, int fromV, int toV);
void ShowGraphEdgeInfo(ALGraph *pg);

#endif /* ALGraph_h */
