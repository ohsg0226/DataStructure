//
//  SimpleHeap.c
//  PriorityQueue
//
//  Created by 오승기 on 2022/07/25.
//

#include "SimpleHeap.h"

void HeapInit(Heap *ph)
{
  ph -> numOfData = 0;
}

int HIsEmpty(Heap *ph)
{
  if(ph -> numOfData == 0) { return TRUE; }
  else { return FALSE; }
}

int GetParentIndex(int idx)
{
  return idx / 2;
}

int GetLeftChildIndex(int idx)
{
  return idx * 2;
}

int GetRightChildIndex(int idx)
{
  return GetLeftChildIndex(idx) + 1;
}

int GetHighPriorChildIndex(Heap *ph, int idx)
{
  if(GetLeftChildIndex(idx) > ph -> numOfData) {
    return 0;
  } else if(GetLeftChildIndex(idx) == ph -> numOfData) {
    return GetLeftChildIndex(idx);
  } else {
    if(ph -> heapArr[GetLeftChildIndex(idx)].prior >
       ph -> heapArr[GetRightChildIndex(idx)].prior) {
      return GetRightChildIndex(idx);
    } else {
      return GetLeftChildIndex(idx);
    }
  }
}

void HInsert(Heap *ph, HData data, Priority prior)
{
  int idx = ph -> numOfData+1;
  HeapElement newElement = {prior, data};
  
  while (idx != 1) {
    if(prior < (ph -> heapArr[GetParentIndex(idx)].prior)) {
      ph -> heapArr[idx] = ph -> heapArr[GetParentIndex(idx)];
      idx = GetParentIndex(idx);
    } else {
      break;
    }
  }
  
  ph -> heapArr[idx] = newElement;
  ph -> numOfData += 1;
}

HData HDelete(Heap *ph)
{
  HData retData = (ph -> heapArr[1]).data;
  HeapElement lastElement = ph -> heapArr[ph -> numOfData];
  
  int parentIndex = 1;
  int childIndex;
  
  while (1) {
    childIndex = GetHighPriorChildIndex(ph, parentIndex);
    if(lastElement.prior <= ph -> heapArr[childIndex].prior) {
      break;
    }
    
    ph -> heapArr[parentIndex] = ph -> heapArr[childIndex];
    parentIndex = childIndex;
  }
  
  ph -> heapArr[parentIndex] = lastElement;
  ph -> numOfData -= 1;
  return retData;
}
