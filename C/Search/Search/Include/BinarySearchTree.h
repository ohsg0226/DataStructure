//
//  BinarySearchTree.h
//  Search
//
//  Created by 오승기 on 2022/07/31.
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

#endif /* BinarySearchTree_h */
