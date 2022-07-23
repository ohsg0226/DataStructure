//
//  CircularQueue.c
//  Queue
//
//  Created by 오승기 on 2022/07/22.
//

#include "CircularQueue.h"
#include <stdio.h>
#include <stdlib.h>

void QueueInit(CQueue *pq)
{
  pq -> front = 0;
  pq -> rear = 0;
}

int QIsEmpty(CQueue *pq)
{
  if(pq->front == pq->rear) { return TRUE; }
  else { return FALSE; }
}

int NextPosIdx(int pos)
{
  if(pos == QUE_LEN - 1) { return 0; }
  else { return pos + 1; }
}

void Enqueue(CQueue *pq, Data data)
{
  if(NextPosIdx(pq->rear) == pq -> front) {
    printf("QUEUE IS MEMORY");
    exit(-1);
  }
  
  pq -> rear = NextPosIdx(pq -> rear);
  pq -> queArr[pq -> rear] = data;
}

Data Dequeue(CQueue *pq)
{
  if(QIsEmpty(pq)) {
    printf("QUEUE IS MEMORY");
    exit(-1);
  }
  
  pq -> front = NextPosIdx(pq -> front);
  return pq -> queArr[pq -> front];
}

Data QPeek(CQueue *pq)
{
  if(QIsEmpty(pq)) {
    printf("QUEUE IS MEMORY");
    exit(-1);
  }
  
  return pq -> queArr[NextPosIdx(pq -> front)];
}
