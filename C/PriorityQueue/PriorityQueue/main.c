//
//  main.c
//  PriorityQueue
//
//  Created by 오승기 on 2022/07/25.
//

#include <stdio.h>
#include "SimpleHeap.h"

int main(int argc, const char * argv[]) {
  Heap heap;
  HeapInit(&heap);
  
  HInsert(&heap, 'A', 1);
  HInsert(&heap, 'B', 2);
  HInsert(&heap, 'C', 3);
  printf("%c \n", HDelete(&heap));
  
  HInsert(&heap, 'A', 1);
  HInsert(&heap, 'B', 2);
  HInsert(&heap, 'C', 3);
  printf("%c \n", HDelete(&heap));
  
  while (!HIsEmpty(&heap)) {
    printf("%c \n", HDelete(&heap));
  }
  printf("HEllo");
  return 0;
}
