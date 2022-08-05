//
//  main.c
//  Problem04-1
//
//  Created by 오승기 on 2022/08/05.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
  int data;
  struct _node *next;
} Node;


int main(int argc, const char * argv[]) {
  Node *head = NULL;
  Node *tail = NULL;
  Node *cur = NULL;
  
  Node *newNode = NULL;
  int readData;
  
  while (1) {
    printf("자연수 입력 : ");
    scanf("%d ", &readData);
    
    if(readData<1) { break; }
    
    newNode = (Node *)malloc(sizeof(Node));
    newNode -> data = readData;
    newNode -> next = NULL;
    
    if(head==NULL) {
      head = newNode;
      tail = newNode;
    } else {
      newNode -> next = head;
      head = newNode;
    }
  }
  printf("\n\n");
  printf("데이터 전체 출력 \n");
  
  if(head == NULL) {
    printf("No data");
  } else {
    cur = head;
    
    printf("%d ", cur -> data);
    while (cur -> next != NULL) {
      cur = cur -> next;
      printf("%d ", cur -> data);
    }
  }
  
  printf("\n\n");
  
  return 0;
}
