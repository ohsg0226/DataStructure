//
//  Slot.h
//  Table
//
//  Created by 오승기 on 2022/08/02.
//

#ifndef Slot_h
#define Slot_h

#include "Person.h"

typedef int Key;
typedef Person *Value;

enum Slotstatus {EMPTY, DELETED, INUSE};

typedef struct _slot
{
  Key key;
  Value value;
  enum Slotstatus status;
} Slot;

#endif /* Slot_h */
