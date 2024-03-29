//
//  BinaryTree.c
//  Problem
//
//  Created by 오승기 on 2022/08/08.
//

#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"

BTreeNode * MakeBTreeNode(void)
{
  BTreeNode *newNode = (BTreeNode *)malloc(sizeof(BTreeNode));
  
  newNode -> left = NULL;
  newNode -> right = NULL;
  
  return newNode;
}

BTData GetData(BTreeNode * bt)
{
  return bt -> data;
}

void SetData(BTreeNode * bt, BTData data)
{
  bt -> data = data;
}

BTreeNode * GetLeftSubTree(BTreeNode * bt)
{
  return bt -> left;
}

BTreeNode * GetRightSubTree(BTreeNode * bt)
{
  return bt -> right;
}

void MakeLeftSubTree(BTreeNode * main, BTreeNode * sub)
{
  if(main -> left != NULL) {
    free(main -> left);
  }
  main -> left = sub;
}
void MakeRightSubTree(BTreeNode * main, BTreeNode * sub)
{
  if(main -> right != NULL) {
    free(main -> right);
  }
  main -> right = sub;
}

void PreorderTraverse(BTreeNode * bt, VisitFuncPtr action)
{
  if(bt == NULL) { return; }
  
  action(bt->data);
  PreorderTraverse(bt -> left, action);
  PreorderTraverse(bt -> right, action);
}

void InorderTraverse(BTreeNode * bt, VisitFuncPtr action)
{
  if(bt == NULL) { return; }
  
  InorderTraverse(bt -> left, action);
  action(bt->data);
  InorderTraverse(bt -> right, action);
}

void PostorderTraverse(BTreeNode * bt, VisitFuncPtr action)
{
  if(bt == NULL) { return; }
  
  PostorderTraverse(bt -> left, action);
  PostorderTraverse(bt -> right, action);
  action(bt->data);
}

void DeleteTree(BTreeNode * bt)
{
  if(bt == NULL) { return; }
  
  DeleteTree(bt -> left);
  DeleteTree(bt -> right);
  
  printf("Deleted Node: %d\n", bt -> data);
  free(bt);
}
