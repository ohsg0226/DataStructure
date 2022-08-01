//
//  BinaryTree.h
//  Search
//
//  Created by 오승기 on 2022/07/31.
//

#ifndef BinaryTree_h
#define BinaryTree_h

#include <stdio.h>

typedef int BinaryTreeData;

typedef struct _binaryTreeNode
{
  BinaryTreeData data;
  struct _binaryTreeNode *left;
  struct _binaryTreeNode *right;
} BinaryTreeNode;

BinaryTreeNode *MakeBinaryTreeNode(void);
BinaryTreeData GetData(BinaryTreeNode *bt);
void SetData(BinaryTreeNode *bt, BinaryTreeData data);

BinaryTreeNode *GetLeftSubTree(BinaryTreeNode *bt);
BinaryTreeNode *GetRightSubTree(BinaryTreeNode *bt);

void MakeLeftSubTree(BinaryTreeNode *main, BinaryTreeNode *sub);
void MakeRightSubTree(BinaryTreeNode *main, BinaryTreeNode *sub);

typedef void (*VisitFuncPtr)(BinaryTreeData data);

void PreorderTraverse(BinaryTreeNode *bt, VisitFuncPtr action);
void InorderTraverse(BinaryTreeNode *bt, VisitFuncPtr action);
void PostorderTraverse(BinaryTreeNode *bt, VisitFuncPtr action);

BinaryTreeNode *RemoveLeftSubTree(BinaryTreeNode *bt);
BinaryTreeNode *RemoveRightSubTree(BinaryTreeNode *bt);

void ChangeLeftSubTree(BinaryTreeNode *main, BinaryTreeNode *sub);
void ChangeRightSubTree(BinaryTreeNode *main, BinaryTreeNode *sub);
#endif /* BinaryTree_h */
