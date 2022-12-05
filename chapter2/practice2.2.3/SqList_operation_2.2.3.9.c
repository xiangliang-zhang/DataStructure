#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

// 查找元素，若存在与后一元素交换，否则插入该元素
#define MaxSize 100


typedef struct {
    int data[MaxSize];
    int length;
} SqList;

bool biSearch(SqList *s, int val);

bool InitSqList(SqList *s) {
    s->data[0] = 1;
    s->data[1] = 2;
    s->data[2] = 3;
    s->data[3] = 4;
    s->data[4] = 96;
    s->data[5] = 97;
    s->data[6] = 98;
    s->data[7] = 100;
    s->length = 8;
    return true;
}

bool insertEle(SqList *s, int val, int i) {
    for (int j = s->length; j > i + 1; j--) {
        s->data[j] = s->data[j - 1];
    }
    s->data[i + 1] = val;
    return true;
}

bool FindOrInsert(SqList *s, int val) {
    for (int i = s->length - 1; i >= 0; i--) {
        if (s->data[i] > val) {
            continue;
        } else if (s->data[i] == val) {
            int temp = s->data[i];
            s->data[i] = s->data[i + 1];
            s->data[i + 1] = temp;
            break;
        } else if (s->data[i] < val) {
            insertEle(s, val, i);
            break;
        }
    }

    return true;
}

void printEle(SqList s) {
    for (int i = 0; i < s.length; i++) {
        printf("%d\n", s.data[i]);
    }
}

int main() {
    SqList s;
    s.length = 0;
    InitSqList(&s);
    int val = 99;
//    FindOrInsert(&s, val);
    biSearch(&s, val);
    printEle(s);
    return 0;
}

// 最优解应为折半查找
bool biSearch(SqList *s, int val) {
    int i = 0, j = s->length;
    while (i <= j) {
        int mid = (i + j) / 2;
        if (s->data[mid] == val) {
            int temp = s->data[mid];
            s->data[mid] = s->data[mid + 1];
            s->data[mid + 1] = temp;
            break;
        } else if (s->data[mid] < val) {
            i = mid + 1;
        } else {
            j = mid - 1;
        }
    }
    if (i > j) {
        for (int t = s->length; t > i; t--) {
            s->data[t] = s->data[t - 1];
        }
        s->data[i] = val;
        s->length++;
    }
    return true;
}
