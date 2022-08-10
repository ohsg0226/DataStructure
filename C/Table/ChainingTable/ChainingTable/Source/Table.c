//
//  Table.c
//  ChainingTable
//
//  Created by 오승기 on 2022/08/10.
//

#include <stdio.h>
#include <stdlib.h>
#include "Table.h"
#include "DLinkedList.h"

void TBLInit(Table * pt, HashFunc * f)
{
  for(int i=0; i<MAX_TABLE; i++) {
    ListInit(&(pt ->table[i]));
  }
  
  pt -> hf = f;
}

void TBLInsert(Table * pt, Key k, Value v)
{
  int hashValue = pt -> hf(k);
  Slot ns = {k, v};
  
  if(TBLSearch(pt, k) != NULL) {
    printf("키 중복");
    return;
  } else {
    LInsert(&(pt -> table[hashValue]), ns);
  }
}

Value TBLDelete(Table * pt, Key k)
{
  int hashValue = pt -> hf(k);
  Slot cSlot;
  
  if(LFirst(&(pt -> table[hashValue]), &cSlot)) {
    if(cSlot.key == k) {
      LRemove(&(pt -> table[hashValue]));
      return cSlot.value;
    } else {
      while (LNext(&(pt -> table[hashValue]), &cSlot)) {
        if(cSlot.key == k) {
          LRemove(&(pt -> table[hashValue]));
          return cSlot.value;
        }
      }
    }
  }
  return NULL;
}

Value TBLSearch(Table * pt, Key k)
{
  int hashValue = pt->hf(k);
  Slot cSlot;

  if(LFirst(&(pt->table[hashValue]), &cSlot))
  {
    if(cSlot.key == k)
    {
      return cSlot.value;
    }
    else
    {
      while(LNext(&(pt->table[hashValue]), &cSlot))
      {
        if(cSlot.key == k)
          return cSlot.value;
      }
    }
  }

  return NULL;
}
