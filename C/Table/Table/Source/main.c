//
//  main.c
//  Table
//
//  Created by 오승기 on 2022/08/02.
//

#include <stdio.h>
#include <stdlib.h>
#include "Person.h"
#include "Table.h"

int MyHashFunc(int k)
{
  return k % 100;    // ≈∞∏¶ ∫Œ∫–¿˚¿∏∑Œ∏∏ ªÁøÎ«— ∫∞∑Œ ¡¡¡ˆ æ ¿∫ «ÿΩ¨¿« øπ!!!
}

int main(void)
{
  Table myTbl;
  Person * np;
  Person * sp;
  Person * rp;

  TableInit(&myTbl, MyHashFunc);

  np = MakePersonData(20120003, "Lee", "Seoul");
  TableInsert(&myTbl, GetSSN(np), np);

  np = MakePersonData(20130012, "KIM", "Jeju");
  TableInsert(&myTbl, GetSSN(np), np);

  np = MakePersonData(20170049, "HAN", "Kangwon");
  TableInsert(&myTbl, GetSSN(np), np);

  sp = TableSearch(&myTbl, 20120003);
  if(sp != NULL)
    ShowPersonInfo(sp);

  sp = TableSearch(&myTbl, 20130012);
  if(sp != NULL)
    ShowPersonInfo(sp);

  sp = TableSearch(&myTbl, 20170049);
  if(sp != NULL)
    ShowPersonInfo(sp);

  rp = TableDelete(&myTbl, 20120003);
  if(rp != NULL)
    free(rp);

  rp = TableDelete(&myTbl, 20130012);
  if(rp != NULL)
    free(rp);

  rp = TableDelete(&myTbl, 20170049);
  if(rp != NULL)
    free(rp);

  return 0;
}
