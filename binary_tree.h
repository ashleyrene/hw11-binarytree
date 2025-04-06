#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <string.h>

typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

TreeNode* createNode(int data);
TreeNode* createTree(int* arr, int size);
void inorderTraversal(TreeNode* root);
void preorderTraversal(TreeNode* root);
void freeTree(TreeNode* root);
TreeNode* trimTree(TreeNode* root, int low, int high);
TreeNode* toBST(TreeNode* root);

#endif // BINARY_TREE_H

