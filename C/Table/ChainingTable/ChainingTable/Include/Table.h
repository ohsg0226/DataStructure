//
//  Table.h
//  ChainingTable
//
//  Created by 오승기 on 2022/08/10.
//

#ifndef Table_h
#define Table_h

#include "Slot.h"
#include "DLinkedList.h"

#define MAX_TABLE 100

typedef int HashFunc(Key k);

typedef struct _table
{
  List table[MAX_TABLE];
  HashFunc *hf;
} Table;

void TBLInit(Table * pt, HashFunc * f);
void TBLInsert(Table * pt, Key k, Value v);
Value TBLDelete(Table * pt, Key k);
Value TBLSearch(Table * pt, Key k);

#endif /* Table_h */
