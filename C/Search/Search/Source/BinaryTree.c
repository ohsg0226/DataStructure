//
//  BinaryTree.c
//  Search
//
//  Created by 오승기 on 2022/07/31.
//

#include "BinaryTree.h"
#include <stdio.h>
#include <stdlib.h>

BinaryTreeNode *MakeBinaryTreeNode(void)
{
  BinaryTreeNode *newNode = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
  newNode -> left = NULL;
  newNode -> right = NULL;
  
  return newNode;
}

BinaryTreeData GetData(BinaryTreeNode *bt)
{
  return bt -> data;
}

void SetData(BinaryTreeNode *bt, BinaryTreeData data)
{
  bt -> data = data;
}

BinaryTreeNode *GetLeftSubTree(BinaryTreeNode *bt)
{
  return bt -> left;
}

BinaryTreeNode *GetRightSubTree(BinaryTreeNode *bt)
{
  return bt -> right;
}

void MakeLeftSubTree(BinaryTreeNode *main, BinaryTreeNode *sub)
{
  if(main -> left != NULL) {
    free(main -> left);
  }
  
  main -> left = sub;
}

void MakeRightSubTree(BinaryTreeNode *main, BinaryTreeNode *sub)
{
  if(main -> right != NULL) {
    free(main -> right);
  }
  
  main -> right = sub;
}

void PreorderTraverse(BinaryTreeNode *bt, VisitFuncPtr action)
{
  if(bt == NULL) { return; }
  
  action(bt -> data);
  PreorderTraverse(bt->left, action);
  PreorderTraverse(bt->right, action);
}

void InorderTraverse(BinaryTreeNode *bt, VisitFuncPtr action)
{
  if(bt == NULL) { return; }
  
  InorderTraverse(bt -> left, action);
  action(bt -> data);
  InorderTraverse(bt -> right, action);
}

void PostorderTraverse(BinaryTreeNode *bt, VisitFuncPtr action)
{
  if(bt == NULL) { return; }
  
  PostorderTraverse(bt -> left, action);
  PostorderTraverse(bt -> right, action);
  action(bt -> data);
}
