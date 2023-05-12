#include "stdlib.h"
#include "stdio.h"
#include "stdbool.h"
#include "string.h"

// 判断链表是否是回文链表
struct ListNode {
    int val;
    struct ListNode *next;
};

bool isPalindrome(struct ListNode *head) {
    int length = 0;
    struct ListNode *temp = head;
    while (temp != NULL) {
        length++;
        temp = temp->next;
    }
    struct ListNode *preHead = malloc(sizeof(struct ListNode));
    struct ListNode *nextTemp;
    preHead->next = head;
    temp = preHead;
    struct ListNode *newList = malloc(sizeof(struct ListNode));
    newList->next = NULL;
    for (int i = 0; i < length / 2; i++) {
        nextTemp = temp->next;
        temp->next = nextTemp->next;
        nextTemp->next = newList->next;
        newList->next = nextTemp;
    }
    nextTemp = newList->next;
    temp = preHead->next;
    if (length % 2 != 0) {
        temp = temp->next;
    }
    while (temp != NULL && nextTemp != NULL && temp->val == nextTemp->val) {
        temp = temp->next;
        nextTemp = nextTemp->next;
    }
    if(temp == NULL && nextTemp == NULL){
        return true;
    }else{
        return false;
    }
}