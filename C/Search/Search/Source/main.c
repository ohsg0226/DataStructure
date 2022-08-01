//
//  main.c
//  Search
//
//  Created by 오승기 on 2022/07/31.
//

#include <stdio.h>
#include "BinarySearchTree.h"

int main(int argc, const char * argv[]) {
  BinaryTreeNode *bstRoot;
  BinaryTreeNode *sNode;
  
  BSTMakeAndInit(&bstRoot);
  
  BSTInsert(&bstRoot, 9);
  BSTInsert(&bstRoot, 1);
  BSTInsert(&bstRoot, 4);
  BSTInsert(&bstRoot, 6);
  BSTInsert(&bstRoot, 2);
  BSTInsert(&bstRoot, 8);
  BSTInsert(&bstRoot, 3);
  
  sNode = BSTSearch(bstRoot, 1);
  if(sNode == NULL) {
    printf("탐색 실패 \n");
  } else {
    printf("키 값: %d \n", BSTGetNodeData(sNode));
  }
  
  sNode = BSTSearch(bstRoot, 11);
  if(sNode == NULL) {
    printf("탐색 실패 \n");
  } else {
    printf("키 값: %d \n", BSTGetNodeData(sNode));
  }
  
  sNode = BSTSearch(bstRoot, 3);
  if(sNode == NULL) {
    printf("탐색 실패 \n");
  } else {
    printf("키 값: %d \n", BSTGetNodeData(sNode));
  }
  return 0;
}
