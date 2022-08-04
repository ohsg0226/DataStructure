//
//  main.c
//  Problem03-1
//
//  Created by 오승기 on 2022/08/04.
//

#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "NameCard.h"


int main()
{
  List list;
  NameCard *pcard;
  ListInit(&list);
  
  pcard = MakeNameCard("person1", "010-1111-1111");
  LInsert(&list, pcard);
  
  pcard = MakeNameCard("person2", "010-2222-2222");
  LInsert(&list, pcard);
  
  pcard = MakeNameCard("person3", "010-3333-3333");
  LInsert(&list, pcard);
  
  if(LFirst(&list, &pcard)) {
    if(!NameCompare(pcard, "person2")) {
      ShowNameCardInfo(pcard);
    } else {
      while (LNext(&list, &pcard)) {
        if(!NameCompare(pcard, "person2")) {
          ShowNameCardInfo(pcard);
          break;
        }
      }
    }
  }
  
  if(LFirst(&list, &pcard)) {
    if(!NameCompare(pcard, "person1")) {
      ChangePhoneNum(pcard, "AAAAA");
    } else {
      while (LNext(&list, &pcard)) {
        if(!NameCompare(pcard, "person1")) {
          ChangePhoneNum(pcard, "AAAAA");
          break;
        }
      }
    }
  }
  
  if(LFirst(&list, &pcard)) {
    if(!NameCompare(pcard, "person3")) {
      pcard = LRemove(&list);
      free(pcard);
    } else {
      while (LNext(&list, &pcard)) {
        if(!NameCompare(pcard, "person3")) {
          pcard = LRemove(&list);
          free(pcard);
          break;
        }
      }
    }
  }
  
  if(LFirst(&list, &pcard)) {
    ShowNameCardInfo(pcard);
    
    while (LNext(&list, &pcard)) {
      ShowNameCardInfo(pcard);
    }
  }
  return 0;
}

/*
 * problem03 -1 main 함수
 */
//int main(void)
//{
//  List list;
//  int data, i;
//  int sum = 0;
//
//  ListInit(&list);
//
//  for(i=1; i<10; i++) {
//    LInsert(&list, i);
//  }
//
//  while (LNext(&list, &data)) {
//    sum += data;
//
//    if((data % 2 == 0) || (data % 3 == 0)) {
//      LRemove(&list);
//    }
//  }
//
//  printf("sum = %d\n", sum);
//
//
//  if(LFirst(&list, &data)) {
//    printf("%d ", data);
//
//    while (LNext(&list, &data)) {
//      printf("%d ", data);
//    }
//  }
//
//  printf("\n");
//
//  return 0;
//}
