//
//  main.c
//  Deque
//
//  Created by 오승기 on 2022/08/07.
//

#include <stdio.h>
#include "Deque.h"

int main(int argc, const char * argv[]) {
  Deque deq;
  DequeInit(&deq);

  DQAddFirst(&deq, 3);
  DQAddFirst(&deq, 2);
  DQAddFirst(&deq, 1);

  DQAddLast(&deq, 4);
  DQAddLast(&deq, 5);
  DQAddLast(&deq, 6);

  while(!DQIsEmpty(&deq))
    printf("%d ", DQRemoveFirst(&deq));

  printf("\n");

  DQAddFirst(&deq, 3);
  DQAddFirst(&deq, 2);
  DQAddFirst(&deq, 1);
  
  DQAddLast(&deq, 4);
  DQAddLast(&deq, 5);
  DQAddLast(&deq, 6);
  
  while(!DQIsEmpty(&deq))
    printf("%d ", DQRemoveLast(&deq));
  
  printf("\n");
  return 0;
}
