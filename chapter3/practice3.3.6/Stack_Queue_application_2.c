#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

// 调节车厢顺序

#define MaxSize 100

typedef struct SqStack {
    char data[MaxSize];
    int head;
} SqStack;

typedef struct SqQueue {
    char data[MaxSize];
    int front;
    int rear;
} SqQueue;

void InitStack(SqStack *s) {
    s->head = -1;
}

void InitQueue(SqQueue *q) {
    q->front = 0;
    q->rear = -1;
}

void Push(SqStack *s, char v) {
    s->head++;
    s->data[s->head] = v;
}

char Pop(SqStack *s) {
    char t = s->data[s->head];
    s->head--;
    return t;
}

bool EmptyStack(SqStack *s) {
    if (s->head == -1) {
        return true;
    } else {
        return false;
    }
}

void EnQueue(SqQueue *q, char v) {
    if (q->rear + 1 != MaxSize) {
        q->rear++;
        q->data[q->rear] = v;
    }
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

void Sort(SqStack *s, SqQueue *q, const char str[], int length) {
    for (int i = 0; i < length; i++) {
        if (str[i] == 'a') {
            EnQueue(q, str[i]);
        } else {
            Push(s, str[i]);
        }
    }
    while (!EmptyStack(s)) {
        EnQueue(q, Pop(s));
    }
}

void PrintVal(SqQueue *q) {
    int t = q->front;
    while (t != q->rear) {
        printf("%c\n", q->data[t]);
        t++;
    }
}

int main() {
    SqStack *s = (SqStack *) malloc(sizeof(SqStack));
    InitStack(s);

    SqQueue *q = (SqQueue *) malloc(sizeof(SqQueue));
    InitQueue(q);

    char str[] = "bbbaaa";
    int length = sizeof(str) / sizeof(str[0]) - 1;
    Sort(s, q, str, length);
    PrintVal(q);
}