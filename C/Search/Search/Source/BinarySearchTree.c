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

BinaryTreeNode *BSTRemove(BinaryTreeNode **pRoot, BinarySearchTreeData target)
{
  BinaryTreeNode *parentVirtualRoot = MakeBinaryTreeNode();
  BinaryTreeNode *parentNode = parentVirtualRoot;
  BinaryTreeNode *currentNode = *pRoot;
  BinaryTreeNode *deleteNode;
  
  ChangeRightSubTree(parentVirtualRoot, *pRoot);
  
  while (currentNode != NULL && GetData(currentNode) != target) {
    parentNode = currentNode;
    
    if(target < GetData(currentNode)) {
      currentNode = GetLeftSubTree(currentNode);
    } else {
      currentNode = GetRightSubTree(currentNode);
    }
  }
  
  if(currentNode == NULL) { return NULL; }
  
  deleteNode = currentNode;
  
  if(GetLeftSubTree(deleteNode) == NULL && GetRightSubTree(deleteNode) == NULL) {
    if(GetLeftSubTree(parentNode) == deleteNode) {
      RemoveLeftSubTree(parentNode);
    } else {
      RemoveRightSubTree(parentNode);
    }
  } else if(GetLeftSubTree(deleteNode) == NULL || GetRightSubTree(NULL)) {
    BinaryTreeNode *deleteChildNode;
    
    if(GetLeftSubTree(deleteNode) != NULL) {
      deleteChildNode = RemoveLeftSubTree(deleteNode);
    } else {
      deleteChildNode = RemoveRightSubTree(deleteNode);
    }
    
    if(GetLeftSubTree(parentNode) == deleteNode) {
      ChangeLeftSubTree(parentNode, deleteChildNode);
    } else {
      ChangeRightSubTree(parentNode, deleteChildNode);
    }
  } else {
    BinaryTreeNode *mNode = GetRightSubTree(deleteNode);
    BinaryTreeNode *mpNode = deleteNode;
    int deleteData;
    
    while(GetLeftSubTree(mNode) != NULL) {
      mpNode = mNode;
      mNode = GetLeftSubTree(mNode);
    }
    
    deleteData = GetData(deleteNode);
    SetData(deleteNode, GetData(mNode));
    
    if(GetLeftSubTree(mpNode) == mNode) {
      ChangeLeftSubTree(mpNode, GetRightSubTree(mNode));
    } else {
      ChangeRightSubTree(mpNode, GetRightSubTree(mNode));
    }
    
    deleteNode = mNode;
    SetData(deleteNode, deleteData);
  }
  
  if(GetRightSubTree(parentVirtualRoot) != *pRoot) {
    *pRoot = GetRightSubTree(parentVirtualRoot);
  }
  
  free(parentVirtualRoot);
  
  return deleteNode;
}

void ShowIntData(int data) {
  printf("%d ", data);
}

void BSTShowAll(BinaryTreeNode *bst)
{
  InorderTraverse(bst, ShowIntData);
}
