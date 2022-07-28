//
//  main.c
//  Tree
//
//  Created by 오승기 on 2022/07/23.
//

#include <stdio.h>
#include "BinaryTree.h"

void ShowIntData(int data);

int main(int argc, const char * argv[]) {
  BinaryTreeNode *bt1 = MakeBinaryTreeNode();
  BinaryTreeNode *bt2 = MakeBinaryTreeNode();
  BinaryTreeNode *bt3 = MakeBinaryTreeNode();
  BinaryTreeNode *bt4 = MakeBinaryTreeNode();
  BinaryTreeNode *bt5 = MakeBinaryTreeNode();
  BinaryTreeNode *bt6 = MakeBinaryTreeNode();

  SetData(bt1, 1);
  SetData(bt2, 2);
  SetData(bt3, 3);
  SetData(bt4, 4);
  SetData(bt5, 5);
  SetData(bt6, 6);
  
  MakeLeftSubTree(bt1, bt2);
  MakeRightSubTree(bt1, bt3);
  MakeLeftSubTree(bt2, bt4);
  MakeRightSubTree(bt2, bt5);
  MakeRightSubTree(bt3, bt6);
  
  PreorderTraverse(bt1, ShowIntData);
  printf("\n");
  InorderTraverse(bt1, ShowIntData);
  printf("\n");
  PostorderTraverse(bt1, ShowIntData);
  printf("\n");
  
  DeleteTree(bt1);
  return 0;
}

void ShowIntData(int data)
{
  printf("%d ", data);
}