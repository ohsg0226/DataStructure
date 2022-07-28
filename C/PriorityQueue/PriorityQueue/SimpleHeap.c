//
//  SimpleHeap.c
//  PriorityQueue
//
//  Created by 오승기 on 2022/07/25.
//

#include "SimpleHeap.h"

void HeapInit(Heap *ph, PriorityComp pc)
{
  ph -> numOfData = 0;
  ph -> comp = pc;
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
    if(ph -> comp(ph ->heapArr[GetLeftChildIndex(idx)],
                ph ->heapArr[GetRightChildIndex(idx)]) < 0) {
      return GetRightChildIndex(idx);
    } else {
      return GetLeftChildIndex(idx);
    }
  }
}

void HInsert(Heap *ph, HData data)
{
  int idx = ph -> numOfData+1;
  
  while (idx != 1) {
    if(ph -> comp(data, ph -> heapArr[GetParentIndex(idx)]) > 0) {
      ph -> heapArr[idx] = ph -> heapArr[GetParentIndex(idx)];
      idx = GetParentIndex(idx);
    } else {
      break;
    }
  }
  
  ph -> heapArr[idx] = data;
  ph -> numOfData += 1;
}

HData HDelete(Heap *ph)
{
  HData retData = ph -> heapArr[1];
  HData lastElement = ph -> heapArr[ph -> numOfData];
  
  int parentIndex = 1;
  int childIndex;
  
  while (1) {
    childIndex = GetHighPriorChildIndex(ph, parentIndex);
    if(ph -> comp(lastElement, ph -> heapArr[childIndex]) >= 0) {
      break;
    }
    
    ph -> heapArr[parentIndex] = ph -> heapArr[childIndex];
    parentIndex = childIndex;
  }
  
  ph -> heapArr[parentIndex] = lastElement;
  ph -> numOfData -= 1;
  return retData;
}
