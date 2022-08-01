//
//  BinarySearchTree.c
//  Search
//
//  Created by 오승기 on 2022/07/31.
//

#include "BinarySearchTree.h"
#include <stdio.h>
#include <stdlib.h>

void BSTMakeAndInit(BinaryTreeNode **pRoot)
{
  *pRoot = NULL;
}

BinarySearchTreeData BSTGetNodeData(BinaryTreeNode *bst)
{
  return GetData(bst);
}

void BSTInsert(BinaryTreeNode **pRoot, BinarySearchTreeData data)
{
  BinaryTreeNode *parentNode = NULL;
  BinaryTreeNode *currentNode = *pRoot;
  BinaryTreeNode *newNode = NULL;
  
  while(currentNode != NULL) {
    if(data == GetData(currentNode)) { return; }

    parentNode = currentNode;

    if(GetData(currentNode) > data) {
      currentNode = GetLeftSubTree(currentNode);
    } else {
      currentNode = GetRightSubTree(currentNode);
    }
  }
  
  newNode = MakeBinaryTreeNode();
  SetData(newNode, data);
  
  if(parentNode != NULL) {
    if(data < GetData(parentNode)) {
      MakeLeftSubTree(parentNode, newNode);
    } else {
      MakeRightSubTree(parentNode, newNode);
    }
  } else {
    *pRoot = newNode;
  }
}

BinaryTreeNode *BSTSearch(BinaryTreeNode *bst, BinarySearchTreeData target)
{
  BinaryTreeNode *currentNode= bst;
  BinarySearchTreeData currentData;
  
  while(currentNode != NULL) {
    currentData = GetData(currentNode);
    
    if(target == currentData) {
      return currentNode;
    } else if(target < currentData) {
      currentNode = GetLeftSubTree(currentNode);
    } else {
      currentNode = GetRightSubTree(currentNode);
    }
  }
  
  return NULL;
}
