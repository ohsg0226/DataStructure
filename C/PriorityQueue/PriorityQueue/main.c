//
//  main.c
//  PriorityQueue
//
//  Created by 오승기 on 2022/07/25.
//

#include <stdio.h>
#include "SimpleHeap.h"

int DataPriorityComp(char ch1, char ch2)
{
  return ch2 - ch1;
}

int main(int argc, const char * argv[]) {
  Heap heap;
  HeapInit(&heap, DataPriorityComp);
  
  HInsert(&heap, 'A');
  HInsert(&heap, 'B');
  HInsert(&heap, 'C');
  printf("%c \n", HDelete(&heap));
  
  HInsert(&heap, 'A');
  HInsert(&heap, 'B');
  HInsert(&heap, 'C');
  printf("%c \n", HDelete(&heap));
  
  while (!HIsEmpty(&heap)) {
    printf("%c \n", HDelete(&heap));
  }
  printf("HEllo");
  return 0;
}
