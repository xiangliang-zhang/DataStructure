#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"


// 链表向右旋转K个位置
struct ListNode {
    int val;
    struct ListNode *next;
};


struct ListNode *rotateRight(struct ListNode *head, int k) {
    if (head == NULL || k == 0) {
        return head;
    }
    int cnt = 1;
    struct ListNode *temp = head;
    while (temp->next != NULL) {
        cnt++;
        temp = temp->next;
    }
    k = k % cnt;
    temp->next = head;
    temp = head;
    for (int i = 0; i < cnt - k; i++) {
        temp = temp->next;
    }
    head = temp;
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = NULL;
    return head;
}

void printVal(struct ListNode *head) {
    while (head != NULL) {
        printf("%d\t", head->val);
        head = head->next;
    }
}

void setValue(struct ListNode *head) {
    head->val = 0;

    struct ListNode *node1 = malloc(sizeof(struct ListNode));
    node1->val = 1;
    node1->next = NULL;

    struct ListNode *node2 = malloc(sizeof(struct ListNode));
    node2->val = 2;
    node2->next = NULL;

    struct ListNode *node3 = malloc(sizeof(struct ListNode));
    node3->val = 4;
    node3->next = NULL;

    struct ListNode *node4 = malloc(sizeof(struct ListNode));
    node4->val = 5;
    node4->next = NULL;

    struct ListNode *node5 = malloc(sizeof(struct ListNode));
    node5->val = 5;
    node5->next = NULL;

    struct ListNode *node6 = malloc(sizeof(struct ListNode));
    node6->val = 6;
    node6->next = NULL;

    head->next = node1;
    node1->next = node2;
//    node2->next = node3;
//    node3->next = node4;
//    node4->next = node5;
//    node5->next = node6;
}

int main() {
    struct ListNode *head = malloc(sizeof(struct ListNode));
    setValue(head);
    head = rotateRight(head, 4);
    printVal(head);
}