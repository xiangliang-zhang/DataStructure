#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

// 删除链表的倒数第 N 个结点

struct ListNode {
    int val;
    struct ListNode *next;
};

void SetValue(struct ListNode *list) {
    list->val = 0;
    list->next = NULL;

    struct ListNode *node1 = malloc(sizeof(struct ListNode));
    node1->val = 1;

    struct ListNode *node2 = malloc(sizeof(struct ListNode));
    node2->val = 2;

    struct ListNode *node3 = malloc(sizeof(struct ListNode));
    node3->val = 3;

    struct ListNode *node4 = malloc(sizeof(struct ListNode));
    node4->val = 4;

    struct ListNode *node5 = malloc(sizeof(struct ListNode));
    node5->val = 5;

    list->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = NULL;

}

struct ListNode *removeNthFromEnd(struct ListNode *head, int n) {
    if ((n < 1) || (n == 1 && head->next == NULL)) {
        return NULL;
    }else {
        struct ListNode *fast = head;
        struct ListNode *slow = head;
        for (int i = 0; i < n && fast != NULL; i++) {
            fast = fast->next;
        }
        if(fast == NULL){
            fast = slow;
            head = head->next;
            free(fast);
        }
        else {
            while (fast->next != NULL) {
                slow = slow->next;
                fast = fast->next;
            }
            fast = slow->next;
            slow->next = slow->next->next;
            free(fast);
        }
        return head;
    }
}

struct ListNode* removeNthFromEnd2(struct ListNode* head, int n) {
    struct ListNode* dummy = malloc(sizeof(struct ListNode));
    dummy->val = 0, dummy->next = head;
    struct ListNode* first = head;
    struct ListNode* second = dummy;
    for (int i = 0; i < n; ++i) {
        first = first->next;
    }
    while (first) {
        first = first->next;
        second = second->next;
    }
    second->next = second->next->next;
    struct ListNode* ans = dummy->next;
    free(dummy);
    return ans;
}


void PrintVal(struct ListNode *list) {
    while (list != NULL) {
        printf("%d\t", list->val);
        list = list->next;
    }
}

int main() {
    struct ListNode *res = malloc(sizeof(struct ListNode));
    SetValue(res);
    struct ListNode *res2 = removeNthFromEnd2(res, 6);
    PrintVal(res2);
}