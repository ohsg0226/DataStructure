//
//  ListBaseQueue.c
//  Queue
//
//  Created by 오승기 on 2022/07/22.
//

#include "ListBaseQueue.h"
#include <stdio.h>
#include <stdlib.h>

void QueueInit(LQueue *pq)
{
  pq -> front = NULL;
  pq -> rear = NULL;
}

int QIsEmpty(LQueue *pq)
{
  if(pq->front == NULL) { return TRUE; }
  else { return FALSE; }
}

void Enqueue(LQueue *pq, Data data)
{
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode -> next = NULL;
  newNode -> data = data;
  
  if(QIsEmpty(pq)) {
    pq -> front = newNode;
    pq -> rear = newNode;
  } else {
    pq -> rear -> next = newNode;
    pq -> rear = newNode;
  }
}

Data Dequeue(LQueue *pq)
{
  Node *deleteNode;
  Data returnData;
  
  if(QIsEmpty(pq)) {
    printf("QUEUE MEMORY ERROR");
    exit(-1);
  }
  
  deleteNode = pq -> front;
  returnData = deleteNode -> data;
  pq -> front = pq -> front -> next;
  
  free(deleteNode);
  
  return returnData;
}

Data QPeek(LQueue *pq)
{
  if(QIsEmpty(pq)) {
    printf("QUEUE MEMORY ERROR");
    exit(-1);
  }
  
  return pq -> front -> data;
}
