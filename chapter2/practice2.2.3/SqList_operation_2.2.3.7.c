#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

// 合并两个有序顺序表
typedef struct {
    int *data;
    int length;
} SqList;

bool InitSqList(SqList *s) {
    s->data = (int *) malloc(sizeof(int) * s->length);
    s->data[0] = 1;
    s->data[1] = 2;
    s->data[2] = 2;
    s->data[3] = 3;
    s->data[4] = 3;
    s->data[5] = 3;
    s->data[6] = 4;
    s->data[7] = 5;
    s->data[8] = 5;
    s->length = 9;
    return true;
}

SqList *mergeSqList(SqList *s1, SqList *s2, SqList *s3) {
    s3->data = (int *) malloc(sizeof(int) * (s1->length + s2->length));
    s3->length = s1->length + s2->length;
    if (s1->length == 0 && s2->length == 0) {
        return NULL;
    } else if (s1->length == 0 && s2->length != 0) {
        return s2;
    } else if (s1->length != 0 && s2->length == 0) {
        return s1;
    } else {
        int i = 0, j = 0, k = 0;
        while (i < s1->length && j < s2->length) {
            if (s1->data[i] <= s2->data[j]) {
                s3->data[k] = s1->data[i];
                i++;
                k++;
            } else {
                s3->data[k] = s2->data[j];
                k++;
                j++;
            }
        }
        while (i < s1->length) {
            s3->data[k] = s1->data[i];
            k++;
            i++;
        }
        while (j < s2->length) {
            s3->data[k] = s2->data[j];
            k++;
            j++;
        }
    }
    return s3;
}


void printEle(SqList *s) {
    for (int i = 0; i < s->length; i++) {
        printf("%d\n", s->data[i]);
    }
}

int main() {
    SqList s1, s2, s3;
    InitSqList(&s1);
    InitSqList(&s2);
    mergeSqList(&s1, &s2, &s3);
    printEle(&s3);
    return 0;
}