//
//  main.c
//  Queue
//
//  Created by 오승기 on 2022/07/22.
//

#include <stdio.h>
#include "CircularQueue.h"

int main(int argc, const char * argv[]) {
  Queue q;
  QueueInit(&q);
  
  Enqueue(&q, 1);
  Enqueue(&q, 2);
  Enqueue(&q, 3);
  Enqueue(&q, 4);
  Enqueue(&q, 5);
  
  while (!QIsEmpty(&q)) {
    printf("%d ", Dequeue(&q));
  }
  
  return 0;
}
