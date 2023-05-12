#include "stdlib.h"
#include "stdbool.h"
#include "stdio.h"

// 相交链表

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    int lengthA = 0;
    int lengthB = 0;
    struct ListNode *temp1 = headA;
    struct ListNode *temp2 = headB;
    while (temp1 != NULL) {
        lengthA++;
        temp1 = temp1->next;
    }
    while (temp2 != NULL) {
        lengthB++;
        temp2 = temp2->next;
    }
    temp1 = headA;
    temp2 = headB;
    if (lengthA > lengthB) {
        for (int i = lengthA - lengthB; i > 0; i--) {
            temp1 = temp1->next;
        }
    } else if (lengthA < lengthB) {
        for (int i = lengthB - lengthA; i > 0; i--) {
            temp2 = temp2->next;
        }
    }
    while (temp1 != NULL && temp2 != NULL && temp1 != temp2) {
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    if (temp1 == NULL || temp2 == NULL) return NULL;
    else return temp1;
}