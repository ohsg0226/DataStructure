//
//  AVLRebalance.c
//  AVLTree
//
//  Created by 오승기 on 2022/08/02.
//

#include "AVLRebalance.h"
#include <stdio.h>
#include "BinaryTree.h"

BinaryTreeNode *RotateLL(BinaryTreeNode *bst)
{
  BinaryTreeNode *parentNode;
  BinaryTreeNode *childNode;
  
  parentNode = bst;
  childNode = GetLeftSubTree(parentNode);
  
  ChangeLeftSubTree(parentNode, GetRightSubTree(childNode));
  ChangeRightSubTree(childNode, parentNode);
  
  return childNode;
}

BinaryTreeNode *RotateRR(BinaryTreeNode *bst)
{
  BinaryTreeNode *parentNode;
  BinaryTreeNode *childNode;
  
  parentNode = bst;
  childNode = GetRightSubTree(parentNode);
  
  ChangeRightSubTree(parentNode, GetLeftSubTree(childNode));
  ChangeLeftSubTree(childNode, parentNode);
  
  return childNode;
}

BinaryTreeNode *RotateLR(BinaryTreeNode *bst)
{
  BinaryTreeNode *parentNode;
  BinaryTreeNode *childNode;
  
  parentNode = bst;
  childNode = GetLeftSubTree(parentNode);
  
  ChangeLeftSubTree(parentNode, RotateRR(childNode));
  
  return RotateLL(parentNode);
}

BinaryTreeNode *RotateRL(BinaryTreeNode *bst)
{
  BinaryTreeNode *parentNode;
  BinaryTreeNode *childNode;
  
  parentNode = bst;
  childNode = GetRightSubTree(parentNode);
  
  ChangeRightSubTree(parentNode, RotateLL(childNode));
  
  return RotateRR(parentNode);
}

int GetHeight(BinaryTreeNode *bst)
{
  int leftHeight;
  int rightHeight;
  
  if(bst == NULL) { return 0; }
  
  leftHeight = GetHeight(GetLeftSubTree(bst));
  rightHeight = GetHeight(GetRightSubTree(bst));
  
  if(leftHeight > rightHeight) {
    return leftHeight + 1;
  } else {
    return rightHeight + 1;
  }
}

int GetHeightDiff(BinaryTreeNode *bst)
{
  int leftSubTreeHeight;
  int rightSubTreeHeight;
  
  if(bst == NULL) { return 0; }
  
  leftSubTreeHeight = GetHeight(GetLeftSubTree(bst));
  rightSubTreeHeight = GetHeight(GetRightSubTree(bst));
  
  return leftSubTreeHeight - rightSubTreeHeight;
}

BinaryTreeNode *Rebalance(BinaryTreeNode **pRoot)
{
  int heightDiff = GetHeightDiff(*pRoot);
  
  if(heightDiff > 1) {
    if(GetHeightDiff(GetLeftSubTree(*pRoot)) > 0) {
      *pRoot = RotateLL(*pRoot);
    } else {
      *pRoot = RotateLR(*pRoot);
    }
  }
  
  if(heightDiff < -1) {
    if(GetHeightDiff(GetRightSubTree(*pRoot)) < 0) {
      *pRoot = RotateRR(*pRoot);
    } else {
      *pRoot = RotateRL(*pRoot);
    }
  }
  
  return  *pRoot;
}
