//
//  Table.c
//  Table
//
//  Created by 오승기 on 2022/08/02.
//

#include "Table.h"
#include <stdio.h>
#include <stdlib.h>

void TableInit(Table *pt, HashFunc *func)
{
  int i;
  
  for(i = 0; i<MAX_TABLE; i++) {
    (pt -> table[i]).status = EMPTY;
  }
  
  pt -> hf = func;
}

void TableInsert(Table *pt, Key key, Value value)
{
  int hv = pt -> hf(key);
  pt -> table[hv].value = value;
  pt -> table[hv].key = key;
  pt -> table[hv].status = INUSE;
}

Value TableDelete(Table *pt, Key key)
{
  int hv = pt -> hf(key);
  
  if((pt -> table[hv]).status != INUSE) { return  NULL; }
  else {
    (pt -> table[hv]).status = DELETED;
    return (pt -> table[hv]).value;
  }
}

Value TableSearch(Table *pt, Key key)
{
  int hv = pt -> hf(key);
  
  
  if((pt -> table[hv]).status != INUSE) { return  NULL; }
  else {
    return (pt -> table[hv]).value;
  }
}
