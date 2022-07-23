//
//  ListBaseQueue.h
//  Queue
//
//  Created by 오승기 on 2022/07/22.
//

#ifndef ListBaseQueue_h
#define ListBaseQueue_h

#define TRUE 1
#define FALSE 0

typedef int Data;

typedef struct _node
{
  Data data;
  struct _node *next;
} Node;

typedef struct _lQueue
{
  Node *front;
  Node *rear;
} LQueue;

void QueueInit(LQueue *pq);
int QIsEmpty(LQueue *pq);

void Enqueue(LQueue *pq, Data data);
Data Dequeue(LQueue *pq);
Data QPeek(LQueue *pq);


#endif /* ListBaseQueue_h */
