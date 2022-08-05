//
//  DoublyLinkedList.h
//  Problem05-2
//
//  Created by 오승기 on 2022/08/05.
//

#ifndef DoublyLinkedList_h
#define DoublyLinkedList_h

#define TRUE  1
#define FALSE  0

typedef int Data;

typedef struct _node
{
  Data data;
  struct _node * next;
  struct _node * prev;
} Node;

typedef struct _dbDLinkedList
{
  Node * head;
  Node * tail;
  Node * cur;
  int numOfData;
} DBDLinkedList;

typedef DBDLinkedList List;

void ListInit(List * plist);
void LInsert(List * plist, Data data);

int LFirst(List * plist, Data * pdata);
int LNext(List * plist, Data * pdata);

Data LRemove(List * plist);
int LCount(List * plist);

#endif /* DoublyLinkedList_h */
