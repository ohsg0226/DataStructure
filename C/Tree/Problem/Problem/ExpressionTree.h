//
//  ExpressionTree.h
//  Problem
//
//  Created by 오승기 on 2022/08/08.
//

#ifndef ExpressionTree_h
#define ExpressionTree_h

#include "BinaryTree.h"

BTreeNode * MakeExpTree(char exp[]);
int EvaluateExpTree(BTreeNode * bt);

void ShowPrefixTypeExp(BTreeNode * bt);
void ShowInfixTypeExp(BTreeNode * bt);
void ShowPostfixTypeExp(BTreeNode * bt);

#endif /* ExpressionTree_h */
