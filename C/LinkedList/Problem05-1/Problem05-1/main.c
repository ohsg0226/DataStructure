//
//  main.c
//  Problem05-1
//
//  Created by 오승기 on 2022/08/05.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CLinkedList.h"
#include "Employ.h"

void ShowNightEmploy(Employ *employ);
Employ *WhoIsNightEmploy(List *plist, char *name, int number);

int main(int argc, const char * argv[]) {
  List list;
  Employ *pEmploy;
  
  ListInit(&list);
  
  pEmploy = (Employ *)malloc(sizeof(Employ));
  pEmploy -> number = 1111;
  strcpy(pEmploy -> name, "A");
  LInsert(&list, pEmploy);
  
  pEmploy = (Employ *)malloc(sizeof(Employ));
  pEmploy -> number = 2222;
  strcpy(pEmploy -> name, "B");
  LInsert(&list, pEmploy);
  
  pEmploy = (Employ *)malloc(sizeof(Employ));
  pEmploy -> number = 1111;
  strcpy(pEmploy -> name, "C");
  LInsert(&list, pEmploy);
  
  pEmploy = (Employ *)malloc(sizeof(Employ));
  pEmploy -> number = 1111;
  strcpy(pEmploy -> name, "D");
  LInsert(&list, pEmploy);
  
  pEmploy = WhoIsNightEmploy(&list, "A", 8);
  ShowNightEmploy(pEmploy);
  
  printf("\n\n");
  
  if(LFirst(&list, &pEmploy)) {
    free(pEmploy);
    
    for(int i=0;i<LCount(&list)-1;i++){
      if(LNext(&list, &pEmploy)) {
        free(pEmploy);
      }
    }
  }
  return 0;
}

void ShowNightEmploy(Employ *employ)
{
  printf("Empoloy is %s", employ -> name);
}

Employ *WhoIsNightEmploy(List *plist, char *name, int number)
{
  Employ *emp;
  int i;
  int listLength = LCount(plist);
  
  LFirst(plist, &emp);
  if(strcmp(emp -> name, name) != 0) {
    for(i=0; i<listLength; i++) {
      LNext(plist, &emp);
      
      if(strcmp(emp -> name, name) == 0) {
        break;
      }
    }
    if(i == listLength - 1) { return  NULL; }
  }
  
  for(i=0; i<number; i++) {
    LNext(plist, &emp);
  }
  
  return emp;
}

