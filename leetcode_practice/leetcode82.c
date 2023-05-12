#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

// 删除排序链表中的重复元素 II

struct ListNode {
    int val;
    struct ListNode *next;
};


struct ListNode *deleteDuplicates(struct ListNode *head) {
    if (head == NULL) {
        return head;
    }
    struct ListNode *preHead = malloc(sizeof(struct ListNode));
    preHead->next = head;
    struct ListNode *slow = preHead;
    struct ListNode *temp;
    int cur_flag;
    while (slow != NULL) {
        if (slow->next == NULL || slow->next->next == NULL) {
            break;
        } else if (slow->next->val != slow->next->next->val) {
            slow = slow->next;
        } else {
            cur_flag = slow->next->val;
            while (slow->next != NULL && slow->next->val == cur_flag) {
                temp = slow->next;
                slow->next = slow->next->next;
                free(temp);
            }
        }
    }
    return preHead->next;
}

void printVal(struct ListNode *head) {
    while (head != NULL) {
        printf("%d\t", head->val);
        head = head->next;
    }
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
    int nums[] = {1, 2, 3};
    int length = sizeof(nums) / sizeof(nums[0]);
    struct ListNode *head = malloc(sizeof(struct ListNode));
    setValue(head, nums, length);
    head = deleteDuplicates(head);
    printVal(head);
}