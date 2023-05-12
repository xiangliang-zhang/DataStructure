// 线性表的顺序存储

// 数组的静态分配
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MaxSize 50
typedef struct {
    int data[MaxSize];
    int length;
} SqList;

// 数组的动态分配
typedef struct {
    int *data;
    int MaxSize2, length;
} SeqList;

// 在数组的第i-1位置插入元素e
bool ListInsert(SqList *L, int i, int e) {
    if (i < 1 || i > L->length) {
        return false;
    }
    if (L->length > MaxSize) {
        return false;
    }
    for (int j = L->length; j >= i; j--) {
        L->data[j] = L->data[j - 1];
    }
    L->data[i - 1] = e;
    L->length++;
    return true;
}

//删除数组中i-1位置上的元素
bool ListDelete(SqList *s, int i, int e) {
    if (i < 1 || i > s->length)
        return false;
    e = s->data[i - 1];
    printf("%d\n", e);
    for (int index = i - 1; index < s->length - 1; index++) {
        s->data[index] = s->data[index + 1];
    }
    s->length--;
    return true;
}

// 寻找数组中元素的位置，返回索引
int ListFind(SqList s, int v) {
    for (int i = 0; i < s.length; i++) {
        if (s.data[i] == v) {
            return i;
        }
    }
    return -1;
}

int main() {
    SqList L;
    int a[] = {1, 2, 3, 4, 6};
    L.length = sizeof(a) / sizeof(a[0]);
    for (int i = 0; i < L.length; i++)
        L.data[i] = a[i];
    int res1 = ListInsert(&L, 5, 5);
    int res2 = ListDelete(&L, 5, 0);
    int res3 = ListFind(L, 6);
    printf("%d\n", res1);
    printf("%d\n", res2);
    printf("%d\n", res3);

    int *L2 = (int *) malloc(sizeof(int) * MaxSize);
    L2[0] = 2;
    L2[1] = 2;
    SeqList s = {L2, 2, 3};
    printf("%d", *s.data);
}