#include "stdbool.h"
#include "stdio.h"
#include "stdlib.h"

// 对链表进行简单选择排序

typedef struct LinkNode {
    int data;
    struct LinkNode *next;
} LinkNode, *LinkList;

void InitLinkNode(LinkNode *node) {
    node->next = NULL;
}

void SetLinkListVal(LinkList L) {
    L->data = 5;

    LinkNode *node1 = (LinkNode *) malloc(sizeof(LinkNode));
    InitLinkNode(node1);
    LinkNode *node2 = (LinkNode *) malloc(sizeof(LinkNode));
    InitLinkNode(node2);
    LinkNode *node3 = (LinkNode *) malloc(sizeof(LinkNode));
    InitLinkNode(node3);
    LinkNode *node4 = (LinkNode *) malloc(sizeof(LinkNode));
    InitLinkNode(node4);
    LinkNode *node5 = (LinkNode *) malloc(sizeof(LinkNode));
    InitLinkNode(node5);
    LinkNode *node6 = (LinkNode *) malloc(sizeof(LinkNode));
    InitLinkNode(node6);
    LinkNode *node7 = (LinkNode *) malloc(sizeof(LinkNode));
    InitLinkNode(node7);

    node1->data = 4;
    node2->data = 6;
    node3->data = 3;
    node4->data = 7;
    node5->data = 2;
    node6->data = 8;
    node7->data = 0;

    L->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    node6->next = node7;
}

void SelectSort(LinkList L) {
    LinkNode *curNodePointer = L;
    LinkNode *minPointer;
    while (curNodePointer->next) {
        int minData = curNodePointer->data;
        LinkNode *iterPointer = curNodePointer->next;
        while (iterPointer != NULL) {
            if (iterPointer->data < minData) {
                minData = iterPointer->data;
                minPointer = iterPointer;
            }
            iterPointer = iterPointer->next;
        }
        int temp = minPointer->data;
        minPointer->data = curNodePointer->data;
        curNodePointer->data = temp;
        curNodePointer = curNodePointer->next;
    }
}

void PrintVal(LinkList L) {
    LinkNode *l = L;
    while (l) {
        printf("%d\t", l->data);
        l = l->next;
    }
}

int main() {
    LinkList L = (LinkNode *) malloc(sizeof(LinkNode));
    InitLinkNode(L);
    SetLinkListVal(L);
    SelectSort(L);
    PrintVal(L);
}