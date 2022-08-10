//
//  Slot.h
//  ChainingTable
//
//  Created by 오승기 on 2022/08/10.
//

#ifndef Slot_h
#define Slot_h

#include "Person.h"

typedef int Key;
typedef Person *Value;

typedef struct _slot
{
  Key key;
  Value value;
} Slot;

#endif /* Slot_h */
