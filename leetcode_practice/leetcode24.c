#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

// 两两交换链表中的节点


struct ListNode {
    int val;
    struct ListNode *next;
};

void SetValue(struct ListNode *head){
    head->val = 1;
    head->next = NULL;

    struct ListNode *node1 = malloc(sizeof(struct ListNode));
    node1->val = 2;
    node1->next = NULL;

    struct ListNode *node2 = malloc(sizeof(struct ListNode));
    node2->val = 3;
    node2->next = NULL;

    struct ListNode *node3 = malloc(sizeof(struct ListNode));
    node3->val = 4;
    node3->next = NULL;

    struct ListNode *node4 = malloc(sizeof(struct ListNode));
    node4->val = 5;
    node4->next = NULL;

    struct ListNode *node5 = malloc(sizeof(struct ListNode));
    node5->val = 6;
    node5->next = NULL;

    struct ListNode *node6 = malloc(sizeof(struct ListNode));
    node6->val = 7;
    node6->next = NULL;

    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
//    node5->next = node6;
}

struct ListNode *swapPairs(struct ListNode *head) {
    if(head == NULL || head->next == NULL){
        return head;
    }else{
        struct ListNode *preHead = malloc(sizeof(struct ListNode));
        preHead->next = head;
        struct ListNode *first = preHead;
        struct ListNode *second = head->next;
        while(first->next != NULL && second != NULL) {
            first->next->next = second->next;
            second->next = first->next;
            first->next = second;
            first = second->next;
            if(first->next != NULL) {
                second = first->next->next;
            }else{
                break;
            }
        }
        return preHead->next;
    }
}

void PrintVal(struct ListNode *head){
    while(head != NULL){
        printf("%d\t", head->val);
        head = head->next;
    }
}

int main() {
    struct ListNode *head = malloc(sizeof(struct ListNode));
    SetValue(head);
    head = swapPairs(head);
    PrintVal(head);
}