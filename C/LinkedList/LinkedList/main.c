//
//  main.c
//  LinkedList
//
//  Created by 오승기 on 2022/07/19.
//

#include <stdio.h>
#include "DLinkedList.h"

int WhoIsPrecede(int d1, int d2);

int main(int argc, const char * argv[]) {
  List list;
  int data;
  ListInit(&list);
  
  LInsert(&list, 11);
  LInsert(&list, 22);
  LInsert(&list, 33);
  LInsert(&list, 11);
  LInsert(&list, 22);
  
  printf("현재 데이터수 %d\n", LCount(&list));
  
  if(LFirst(&list, &data)) {
    printf("%d\n", data);
  }
  
  if(LFirst(&list, &data)) {
    if(data == 22) { LRemove(&list); }
    
    while (LNext(&list, &data)) {
      if (data == 22){ LRemove(&list); }
    }
  }
  
  printf("삭제된 후 데이터수 %d\n", LCount(&list));
  
  if(LFirst(&list, &data)) {
    printf("%d ", data);
    
    while (LNext(&list, &data)) {
      printf("%d ", data);
    }
  }
  printf("\n\n");
  return 0;
}

int WhoIsPrecede(int d1, int d2)
{
  if(d1 < d2) { return 0; }
  else { return 1; }
}
