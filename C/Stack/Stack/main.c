//
//  main.c
//  Stack
//
//  Created by 오승기 on 2022/07/15.
//

#include <stdio.h>
#define MAX 100

typedef struct Stack
{
  int arr[MAX];
  int top;
} Stack;

void push(Stack *stack, int top);
int pop(Stack *stack);
int peek(Stack *stack);
int isEmpty(Stack *stack);
int isFull(Stack *stack);
void init(Stack *stack);

int main(int argc, const char * argv[])
{
  Stack stack;
  
  init(&stack);
  
  push(&stack, 1);
  push(&stack, 2);
  push(&stack, 3);
  
  printf("peek = %d\n", peek(&stack));
  printf("pop = %d\n", pop(&stack));
  printf("peek = %d\n", peek(&stack));
  printf("pop = %d\n", pop(&stack));
  printf("peek = %d\n", peek(&stack));
  printf("pop = %d\n", pop(&stack));
  
  
  return 0;
}

void init(Stack *stack)
{
  stack->top = -1;
}
void push(Stack *stack, int value)
{
  if(isFull(stack)) {
    printf("Stack is Full");
    return;
  }
  stack->arr[++(stack->top)] = value;
}

int pop(Stack *stack)
{
  if(isEmpty(stack)) {
    printf("Stack is Empty");
    return -1;
  }
  return stack->arr[(stack->top)--];
}

int peek(Stack *stack)
{
  return stack->arr[(stack->top)];
}

int isEmpty(Stack *stack)
{
  if (stack->top == -1) { return 1; }
  else { return 0; }
}

int isFull(Stack *stack)
{
  if(stack->top == MAX -1) { return 1; }
  else { return 0; }
}
