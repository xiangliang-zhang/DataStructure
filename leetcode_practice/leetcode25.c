#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

// 每k个一组反转链表结点

struct ListNode {
    int val;
    struct ListNode *next;
};


struct ListNode* reverseKGroup(struct ListNode* head, int k){
    struct ListNode *preHead = malloc(sizeof(struct ListNode));
    preHead->next = head;
    if (k == 1) {
        return head;
    } else {
        struct ListNode *newHead = malloc(sizeof(struct ListNode));
        struct ListNode *newIter = newHead;
        newHead->next = NULL;
        struct ListNode *iter = preHead;
        struct ListNode *temp;

        // 计数链表结点
        int length = 0;
        struct ListNode *iterNum = head;
        while (iterNum != NULL) {
            length++;
            iterNum = iterNum->next;
        }

        int cnt = 1;
        while (cnt <= length / k) {
            for (int i = 0; i < k; i++) {
                temp = iter->next;
                iter->next = temp->next;
                temp->next = newIter->next;
                newIter->next = temp;
            }
            while (newIter->next != NULL) {
                newIter = newIter->next;
            }
            cnt++;
        }
        if (iter->next != NULL) {
            newIter->next = iter->next;
        }
        return newHead->next;
    }
}

