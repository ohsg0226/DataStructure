//
//  main.c
//  Problem06-1
//
//  Created by 오승기 on 2022/08/07.
//

#include <stdio.h>
#include "CLLBaseStack.h"

int main(int argc, const char * argv[]) {
  Stack stack;
  StackInit(&stack);

  SPush(&stack, 1);  SPush(&stack, 2);
  SPush(&stack, 3);  SPush(&stack, 4);
  SPush(&stack, 5);

  while(!SIsEmpty(&stack))
    printf("%d ", SPop(&stack));
  return 0;
}
