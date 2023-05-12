#include "stdlib.h"
#include "stdbool.h"
#include "stdio.h"

// 二叉树展开为链表

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


void getLength(struct TreeNode *root, int *length) {
    if (root) {
        (*length)++;
        getLength(root->left, length);
        getLength(root->right, length);
    }
}

void getTreeNodeList(struct TreeNode *root, struct TreeNode **nums, int *i) {
    if (root) {
        nums[(*i)++] = root;
        getTreeNodeList(root->left, nums, i);
        getTreeNodeList(root->right, nums, i);
    }
}

void flatten(struct TreeNode *root) {
    int length = 0;
    getLength(root, &length);
    printf("%d\n", length);
    struct TreeNode **nums = malloc(sizeof(struct TreeNode) * length);
    int index = 0;
    getTreeNodeList(root, nums, &index);
    for (int i = 0; i < length - 1; i++) {
        nums[i]->left = NULL;
        nums[i]->right = nums[i + 1];
    }
// 以下两行不用写，因为是先序的最后一个结点，肯定是左右均为空
//    nums[length - 1]->left = NULL;
//    nums[length - 1]->right = NULL;
}

struct TreeNode *buildTree(int *nums, int length) {
    struct TreeNode *root = malloc(sizeof(struct TreeNode));
    root->val = 1;
    root->left = NULL;
    root->right = NULL;

    struct TreeNode *node1 = malloc(sizeof(struct TreeNode));
    node1->val = 2;
    node1->left = NULL;
    node1->right = NULL;

    struct TreeNode *node2 = malloc(sizeof(struct TreeNode));
    node2->val = 3;
    node2->left = NULL;
    node2->right = NULL;

    struct TreeNode *node3 = malloc(sizeof(struct TreeNode));
    node3->val = 4;
    node3->left = NULL;
    node3->right = NULL;

    struct TreeNode *node4 = malloc(sizeof(struct TreeNode));
    node4->val = 5;
    node4->left = NULL;
    node4->right = NULL;

    struct TreeNode *node5 = malloc(sizeof(struct TreeNode));
    node5->val = 6;
    node5->left = NULL;
    node5->right = NULL;

    root->left = node1;
    node1->left = node2;
    node1->right = node3;
    root->right = node4;
    node4->right = node5;

    return root;
}


void printTreeVal(struct TreeNode *root) {
    if (root) {
        printf("%d\t", root->val);
        printTreeVal(root->left);
        printTreeVal(root->right);
    }
}

int main() {
    struct TreeNode *root = buildTree();
    flatten(root);
    printTreeVal(root);
}