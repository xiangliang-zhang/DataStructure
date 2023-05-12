#include "stdbool.h"
#include "stdlib.h"
#include "stdio.h"

//  将链表中小于x的结点移动到大于或等于x的结点左边

struct ListNode {
    int val;
    struct ListNode *next;
};


struct ListNode *partition(struct ListNode *head, int x) {
    if (head == NULL) {
        return head;
    }
    struct ListNode *preHead = malloc(sizeof(struct ListNode));
    preHead->next = head;
    struct ListNode *preRes = malloc(sizeof(struct ListNode));
    struct ListNode *tempHead = preHead;
    struct ListNode *tempRes = preRes;
    while (tempHead->next != NULL) {
        if (tempHead->next->val < x) {
            tempRes->next = tempHead->next;
            tempHead->next = tempHead->next->next;
            tempRes = tempRes->next;
            tempRes->next = NULL;
        } else {
            tempHead = tempHead->next;
        }
    }
    if (preHead->next != NULL) {
        tempRes->next = preHead->next;
    }
    return preRes->next;
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

void printVal(struct ListNode *head) {
    while (head != NULL) {
        printf("%d\t", head->val);
        head = head->next;
    }
}

int main() {
    int nums[] = {2, 1};
    int length = sizeof(nums) / sizeof(nums[0]);
    struct ListNode *head = malloc(sizeof(struct ListNode));
    setValue(head, nums, length);
    head = partition(head, 2);
    printVal(head);
}