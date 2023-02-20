#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

// 提高顺序检索的效率，查找到指定结点时，将该结点和前驱节点进行交换

// 顺序结构 + 顺序查找

void FindEle(int data[], int length, int val) {
    for (int i = 1; i <= length; i++) {
        if (i == val && i != 1) {
            int temp = data[i - 1];
            data[i - 1] = data[i];
            data[i] = temp;
        }
    }
}

// 链式结构
typedef struct LNode {
    int data;
    struct LNode *next;
} LNode, *LinkList;


LinkList SetValue(const int data[], int length) {
    LinkList list = (LNode *) malloc(sizeof(LNode));
    list->data = data[0];
    LNode *temp = list;
    for (int i = 1; i < length; i++) {
        LNode *node = (LNode *) malloc(sizeof(LNode));
        node->next = NULL;
        node->data = data[i];
        temp->next = node;
        temp = node;
    }
    return list;
}

void FindEleList(LinkList list, int val) {
    LNode *temp = list->next->next;
    LNode *pre = list;
    while (temp) {
        if (temp->data == val) {
            LNode *cur = pre->next;
            pre->next = pre->next->next;
            cur->next = temp->next;
            temp->next = cur;
            break;
        } else {
            temp = temp->next;
            pre = pre->next;
        }
    }
}

void PrintVal(LinkList list) {
    LNode *temp = list->next;
    while (temp) {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
}

int main() {
    int data[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int length = sizeof(data) / sizeof(data[0]);
    int val = 9;
    FindEle(data, length, val);
    for (int i = 1; i < length; i++) {
        printf("%d\t", data[i]);
    }
    printf("\n");
    LinkList list = SetValue(data, length);
    FindEleList(list, val);
    PrintVal(list);
}
