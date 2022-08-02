//
//  BinarySearchTree.h
//  AVLTree
//
//  Created by 오승기 on 2022/08/02.
//

#ifndef BinarySearchTree_h
#define BinarySearchTree_h

#include <stdio.h>
#include "BinaryTree.h"

typedef BinaryTreeData BinarySearchTreeData;

void BSTMakeAndInit(BinaryTreeNode **pRoot);
BinarySearchTreeData BSTGetNodeData(BinaryTreeNode *bst);

void BSTInsert(BinaryTreeNode **pRoot, BinarySearchTreeData data);
BinaryTreeNode *BSTSearch(BinaryTreeNode *bst, BinarySearchTreeData target);

BinaryTreeNode *BSTRemove(BinaryTreeNode **pRoot, BinarySearchTreeData target);
void BSTShowAll(BinaryTreeNode *bst);

#endif /* BinarySearchTree_h */
