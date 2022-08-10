//
//  main.c
//  ChainingTable
//
//  Created by 오승기 on 2022/08/10.
//

#include <stdio.h>
#include <stdlib.h>
#include "Person.h"
#include "Table.h"

int MyHashFunc(int k)
{
  return k % 100;
}

int main(int argc, const char * argv[]) {
  Table myTbl;
  Person * np;
  Person * sp;
  Person * rp;

  TBLInit(&myTbl, MyHashFunc);

  np = MakePersonData(900254, "Lee", "Seoul");
  TBLInsert(&myTbl, GetSSN(np), np);

  np = MakePersonData(900139, "KIM", "Jeju");
  TBLInsert(&myTbl, GetSSN(np), np);

  np = MakePersonData(900827, "HAN", "Kangwon");
  TBLInsert(&myTbl, GetSSN(np), np);

  sp = TBLSearch(&myTbl, 900254);
  if(sp != NULL)
    ShowPerInfo(sp);

  sp = TBLSearch(&myTbl, 900139);
  if(sp != NULL)
    ShowPerInfo(sp);

  sp = TBLSearch(&myTbl, 900827);
  if(sp != NULL)
    ShowPerInfo(sp);

  rp = TBLDelete(&myTbl, 900254);
  if(rp != NULL)
    free(rp);

  rp = TBLDelete(&myTbl, 900139);
  if(rp != NULL)
    free(rp);

  rp = TBLDelete(&myTbl, 900827);
  if(rp != NULL)
    free(rp);

  return 0;
}
