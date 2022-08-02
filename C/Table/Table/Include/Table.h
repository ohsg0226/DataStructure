//
//  Table.h
//  Table
//
//  Created by 오승기 on 2022/08/02.
//

#ifndef Table_h
#define Table_h

#include "Slot.h"

#define MAX_TABLE 100

typedef int HashFunc(Key k);

typedef struct _table
{
  Slot table[MAX_TABLE];
  HashFunc *hf;
} Table;

void TableInit(Table *pt, HashFunc *func);
void TableInsert(Table *pt, Key key, Value value);

Value TableDelete(Table *pt, Key key);
Value TableSearch(Table *pt, Key key);

#endif /* Table_h */
