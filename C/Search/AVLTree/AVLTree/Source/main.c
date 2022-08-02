//
//  main.c
//  AVLTree
//
//  Created by 오승기 on 2022/08/02.
//

#include <stdio.h>
#include "BinaryTree.h"
#include "BinarySearchTree.h"

int main(void)
{
  BinaryTreeNode * avlRoot;
  BinaryTreeNode * clNode;
  BinaryTreeNode * crNode;
  BSTMakeAndInit(&avlRoot);

  BSTInsert(&avlRoot, 1);
  BSTInsert(&avlRoot, 2);
  BSTInsert(&avlRoot, 3);
  BSTInsert(&avlRoot, 4);
  BSTInsert(&avlRoot, 5);
  BSTInsert(&avlRoot, 6);
  BSTInsert(&avlRoot, 7);
  BSTInsert(&avlRoot, 8);
  BSTInsert(&avlRoot, 9);

  printf("루트노드: %d \n", GetData(avlRoot));

  clNode = GetLeftSubTree(avlRoot);
  crNode = GetRightSubTree(avlRoot);
  printf("왼쪽 1: %d, 오른쪽 1: %d \n", GetData(clNode), GetData(crNode));

  clNode = GetLeftSubTree(clNode);
  crNode = GetRightSubTree(crNode);
  printf("왼쪽 2: %d, 오른쪽 2: %d \n", GetData(clNode), GetData(crNode));

  clNode = GetLeftSubTree(clNode);
  crNode = GetRightSubTree(crNode);
  printf("왼쪽 3: %d, 오른쪽 3: %d \n", GetData(clNode), GetData(crNode));

  clNode = GetLeftSubTree(clNode);
  crNode = GetRightSubTree(crNode);
  printf("왼쪽 4: %d, 오른쪽 4: %d \n", GetData(clNode), GetData(crNode));
  return 0;
}
