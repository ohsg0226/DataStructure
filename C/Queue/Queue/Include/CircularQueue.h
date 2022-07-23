//
//  CircularQueue.h
//  Queue
//
//  Created by 오승기 on 2022/07/22.
//

#ifndef CircularQueue_h
#define CircularQueue_h

#define TRUE 1
#define FALSE 0

#define QUE_LEN 100
typedef int Data;

typedef struct _cQueue
{
  int front;
  int rear;
  Data queArr[QUE_LEN];
} CQueue;

void QueueInit(CQueue *pq);
int QIsEmpty(CQueue *pq);

void Enqueue(CQueue *pq, Data data);
Data Dequeue(CQueue *pq);
Data QPeek(CQueue *pq);

#endif /* CircularQueue_h */
