//
//  SimpleHeap.h
//  PriorityQueue
//
//  Created by 오승기 on 2022/07/25.
//

#ifndef SimpleHeap_h
#define SimpleHeap_h

#define TRUE 1
#define FALSE 0

#define HEAP_LEN 100

typedef char HData;
typedef int Priority;

typedef struct _heapElement
{
  Priority prior;
  HData data;
} HeapElement;

typedef struct _heap
{
  int numOfData;
  HeapElement heapArr[HEAP_LEN];
} Heap;

void HeapInit(Heap *ph);
int HIsEmpty(Heap *ph);

void HInsert(Heap *ph, HData data, Priority prior);
HData HDelete(Heap *ph);

#endif /* SimpleHeap_h */
