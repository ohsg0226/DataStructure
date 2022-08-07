//
//  Deque.c
//  Deque
//
//  Created by 오승기 on 2022/08/07.
//

#include <stdio.h>
#include <stdlib.h>
#include "Deque.h"

void DequeInit(Deque * pdeq)
{
  pdeq -> head = NULL;
  pdeq -> tail = NULL;
}

int DQIsEmpty(Deque * pdeq)
{
  if(pdeq -> head == NULL) {
    return TRUE;
  } else {
    return FALSE;
  }
}

void DQAddFirst(Deque * pdeq, Data data)
{
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode -> data = data;
  
  newNode -> next = pdeq -> head;
  if(DQIsEmpty(pdeq)) {
    pdeq -> tail = newNode;
  } else {
    pdeq -> head -> prev = newNode;
  }
  
  newNode -> prev = NULL;
  pdeq -> head = newNode;
}

void DQAddLast(Deque * pdeq, Data data)
{
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode -> data = data;
  
  newNode -> prev = pdeq -> tail;
  
  if(DQIsEmpty(pdeq)) {
    pdeq -> head = newNode;
  } else {
    pdeq -> tail -> next = newNode;
  }
  
  newNode -> next = NULL;
  pdeq -> tail = newNode;
}

Data DQRemoveFirst(Deque * pdeq)
{
  Node *removeNode = pdeq -> head;
  Data removeData = removeNode -> data;
  
  if(DQIsEmpty(pdeq)) {
    exit(1);
  }
  
  pdeq -> head = pdeq -> head -> next;
  free(removeNode);
  
  if(pdeq -> head == NULL) {
    pdeq -> tail = NULL;
  } else {
    pdeq -> head -> prev = NULL;
  }
  
  return removeData;
}

Data DQRemoveLast(Deque * pdeq)
{
  Node *removeNode = pdeq -> tail;
  Data removeData = removeNode -> data;
  
  if(DQIsEmpty(pdeq)) {
    exit(1);
  }
  
  pdeq -> tail = pdeq -> tail -> prev;
  free(removeNode);
  
  if(pdeq -> tail == NULL) {
    pdeq -> head = NULL;
  } else {
    pdeq -> tail -> next = NULL;
  }
  
  return removeData;
}

Data DQGetFirst(Deque * pdeq)
{
  if(DQIsEmpty(pdeq)) {
    return NULL;
  }
  
  return pdeq -> head -> data;
}

Data DQGetLast(Deque * pdeq)
{
  if(DQIsEmpty(pdeq)) {
    return NULL;
  }
  
  return pdeq -> tail -> data;
}
