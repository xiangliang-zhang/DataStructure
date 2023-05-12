#include "stdlib.h"
#include "stdio.h"
#include "stdbool.h"

//有序链表转换二叉搜索树

struct ListNode {
    int val;
    struct ListNode *next;
};

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int getLength(struct ListNode* head) {
    int ret = 0;
    while (head != NULL) {
        ++ret, head = head->next;
    }
    return ret;
}

struct TreeNode* buildTree(struct ListNode** head, int left, int right) {
    if (left > right) {
        return NULL;
    }
    int mid = (left + right + 1) / 2;
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->left = buildTree(head, left, mid - 1);
    root->val = (*head)->val;
    (*head) = (*head)->next;
    root->right = buildTree(head, mid + 1, right);
    return root;
}

struct TreeNode* sortedListToBST(struct ListNode* head) {
    int length = getLength(head);
    return buildTree(&head, 0, length - 1);
}

void setValue(struct ListNode *head, const int *nums, int length) {
    if (length > 0) {
        head->val = nums[0];
        head->next = NULL;
    }
    struct ListNode *iter = head;
    for (int i = 1; i < length; i++) {
        struct ListNode *temp = malloc(sizeof(struct ListNode));
        temp->val = nums[i];
        temp->next = NULL;

        iter->next = temp;
        iter = temp;
    }
}

int main() {
    int nums[] = {-10, -3, 0, 5, 9};
    int length = sizeof(nums) / sizeof(nums[0]);
    struct ListNode *head = malloc(sizeof(struct ListNode));
    setValue(head, nums, length);
    sortedListToBST(head);
}