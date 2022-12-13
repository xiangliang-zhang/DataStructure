#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

// 客货车上船顺序

#define MaxSize 100

typedef struct SqQueue {
    char data[MaxSize];
    int front;
    int rear;
} SqQueue;

void InitQueue(SqQueue *q) {
    q->front = 0;
    q->rear = -1;
}

void EnQueue(SqQueue *q, char c) {
    q->rear++;
    q->data[q->rear] = c;
}

char DeQueue(SqQueue *q) {
    char t = q->data[q->front];
    q->front++;
    return t;
}

bool EmptyQueue(SqQueue *q) {
    if (q->rear + 1 == q->front) {
        return true;
    } else {
        return false;
    }
}

// 先从q1取4个，然后从q2取1个
void Order(SqQueue *s1, SqQueue *s2, SqQueue *s3) {
    int i = 0;  // 统计船上车辆数
    while (i < 10) {
        int cnt = 0;  // 统计客车数量
        while (cnt < 4) {
            if (!EmptyQueue(s2)) {
                char t = DeQueue(s2);
                EnQueue(s1, t);
                cnt++;
                i++;
            } else {
                break;
            }
        }
        if (!EmptyQueue(s3)) {
            char t = DeQueue(s3);
            EnQueue(s1, t);
            i++;
        }

        if (EmptyQueue(s2) && EmptyQueue(s3)) {
            break;
        }
    }
}

void PrintVal(SqQueue *q) {
    int t = q->front;
    while (t != q->rear) {
        printf("%c\n", q->data[t]);
        t++;
    }
    printf("%c\n", q->data[t]);
}

int main() {
    SqQueue *s1 = (SqQueue *) malloc(sizeof(SqQueue));
    SqQueue *s2 = (SqQueue *) malloc(sizeof(SqQueue));
    SqQueue *s3 = (SqQueue *) malloc(sizeof(SqQueue));
    InitQueue(s1);
    InitQueue(s2);
    InitQueue(s3);

    EnQueue(s2, 'k');
    EnQueue(s2, 'k');
    EnQueue(s2, 'k');
    EnQueue(s2, 'k');

    EnQueue(s3, 'h');
    EnQueue(s3, 'h');
    EnQueue(s3, 'h');
    EnQueue(s3, 'h');

    Order(s1, s2, s3);
    PrintVal(s1);
}