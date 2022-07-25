//
//  BinaryTree.h
//  Tree
//
//  Created by 오승기 on 2022/07/23.
//

#ifndef BinaryTree_h
#define BinaryTree_h

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

void DeleteTree(BinaryTreeNode *bt);

#endif /* BinaryTree_h */
