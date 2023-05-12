#include "stdlib.h"
#include "stdio.h"
#include "stdbool.h"

// 链表反转

struct ListNode {
    int val;
    struct ListNode *next;
};

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


struct ListNode *reverseBetween(struct ListNode *head, int left, int right) {
    if (left == right) {
        return head;
    }
    struct ListNode *preHead = malloc(sizeof(struct ListNode));
    struct ListNode *preRes = malloc(sizeof(struct ListNode));
    preRes->next = NULL;
    preHead->next = head;
    struct ListNode *tempHead = preHead;
    struct ListNode *tempRes = preRes;
    struct ListNode *temp;

    int cnt = 1;
    while (tempHead->next != NULL) {
        if (left <= cnt && cnt <= right) {
            temp = tempHead->next->next;
            tempHead->next->next = tempRes->next;
            tempRes->next = tempHead->next;
            tempHead->next = temp;
        } else {
            while (tempRes->next != NULL) {
                tempRes = tempRes->next;
            }
            tempRes->next = tempHead->next;
            tempHead->next = tempHead->next->next;
            tempRes = tempRes->next;
            tempRes->next = NULL;
        }
        cnt++;
    }
    return preRes->next;
}

int main() {
    int nums[] = {5};
    int length = sizeof(nums) / sizeof(nums[0]);
    struct ListNode *head = malloc(sizeof(struct ListNode));
    setValue(head, nums, length);
    int left = 1;
    int right = 1;
    head = reverseBetween(head, left, right);
    printVal(head);
}