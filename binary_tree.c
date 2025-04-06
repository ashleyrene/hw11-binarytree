#include "binary_tree.h"

// Helper function to create a new tree node
TreeNode* createNode(int data) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    if (!node) {
        return NULL;
    }
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Helper to build the tree recursively using array index
TreeNode* buildTree(int* arr, int size, int index) {
    if (index >= size || arr[index] == -1) {
        return NULL;
    }

    TreeNode* root = createNode(arr[index]);
    root->left = buildTree(arr, size, 2 * index + 1);
    root->right = buildTree(arr, size, 2 * index + 2);

    return root;
}

// Creates a binary tree from a level-order array representation
TreeNode* createTree(int* arr, int size) {
    return buildTree(arr, size, 0);
}

// In-order traversal: left, node, right
void inorderTraversal(TreeNode* root) {
    if (!root) return;
    inorderTraversal(root->left);
    printf("%d\n", root->data);
    inorderTraversal(root->right);
}

// Pre-order traversal: node, left, right
void preorderTraversal(TreeNode* root) {
    if (!root) return;
    printf("%d\n", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// Frees all nodes in the tree
void freeTree(TreeNode* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

// Helper for trimTree: recursively trims based on path sum
TreeNode* trimHelper(TreeNode* root, int low, int high, int sum) {
    if (!root) return NULL;

    sum += root->data;
    root->left = trimHelper(root->left, low, high, sum);
    root->right = trimHelper(root->right, low, high, sum);

    if (!root->left && !root->right) {
        if (sum < low || sum > high) {
            free(root);
            return NULL;
        }
    }

    return root;
}

// Trims the tree to keep only root-to-leaf paths in range [low, high]
TreeNode* trimTree(TreeNode* root, int low, int high) {
    return trimHelper(root, low, high, 0);
}

// Helper for toBST: recursively prunes to maintain BST properties
TreeNode* bstHelper(TreeNode* root, int min, int max) {
    if (!root) return NULL;

    if (root->data <= min || root->data >= max) {
        freeTree(root);
        return NULL;
    }

    root->left = bstHelper(root->left, min, root->data);
    root->right = bstHelper(root->right, root->data, max);
    return root;
}

// Prunes the tree to make it a valid BST, preserving the root
TreeNode* toBST(TreeNode* root) {
    if (!root) return NULL;
    root->left = bstHelper(root->left, INT_MIN, root->data);
    root->right = bstHelper(root->right, root->data, INT_MAX);
    return root;
}

