//
//  main.c
//  Problem03-1
//
//  Created by 오승기 on 2022/08/04.
//

#include <stdio.h>
#include "ArrayList.h"

int main(void)
{
  List list;
  int data, i;
  int sum = 0;
  
  ListInit(&list);
  
  for(i=1; i<10; i++) {
    LInsert(&list, i);
  }
    
  while (LNext(&list, &data)) {
    sum += data;
    
    if((data % 2 == 0) || (data % 3 == 0)) {
      LRemove(&list);
    }
  }
  
  printf("sum = %d\n", sum);
  
  
  if(LFirst(&list, &data)) {
    printf("%d ", data);
    
    while (LNext(&list, &data)) {
      printf("%d ", data);
    }
  }
  
  printf("\n");
  
  return 0;
}
