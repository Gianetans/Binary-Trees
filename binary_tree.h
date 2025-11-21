# Binary Tree Header File

#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <stdio.h>
#include <stdlib.h>

// Definition of the tree node
struct TreeNode {
    int value;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function prototypes
struct TreeNode* createNode(int value);
void insert(struct TreeNode** root, int value);
void deleteNode(struct TreeNode** root, int value);
struct TreeNode* search(struct TreeNode* root, int value);
void inorderTraversal(struct TreeNode* root);
void preorderTraversal(struct TreeNode* root);
void postorderTraversal(struct TreeNode* root);

#endif // BINARY_TREE_H
