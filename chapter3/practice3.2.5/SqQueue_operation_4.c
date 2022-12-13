#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

// 设计队列, 带头尾指针的循环单链表


typedef struct SqQueue {
    int data; // 链队列
    struct SqQueue *next;
} SqQueue;

SqQueue *front = NULL;
SqQueue *rear = NULL;

void InitSqQueue(SqQueue *q) {
    q->next = NULL;
}

void EnQueue(SqQueue *q, int v) {
    if (front == NULL && rear == NULL) {
        SqQueue *temp = (SqQueue *) malloc(sizeof(SqQueue));
        InitSqQueue(temp);
        temp->data = v;
        q->next = temp;
        temp->next = q;
        front = temp;

        SqQueue *t = (SqQueue *) malloc(sizeof(SqQueue));
        InitSqQueue(t);
        temp->next = t;
        rear = t;
        t->next = q;
    } else if (rear->next == q) {
        rear->data = v;
        SqQueue *temp = (SqQueue *) malloc(sizeof(SqQueue));
        InitSqQueue(temp);
        rear->next = temp;
        temp->next = q;
        rear = temp;
    } else {
        rear->data = v;
        if (rear->next) {
            rear = rear->next;
        } else {
            SqQueue *t = (SqQueue *) malloc(sizeof(SqQueue));
            rear->next = t;
            t->next = q;
            rear = t;
        }
    }
}

int DeQueue() {
    if ((front == NULL && rear == NULL) || (front == rear)) {
        return -1;
    } else {
        int v = front->data;
        front = front->next;
        return v;
    }
}

bool EmptyQueue() {
    if ((front == NULL && rear == NULL) || front == rear) {
        return true;
    } else {
        return false;
    }
}


bool FullQueue() {
    if ((front == NULL && rear == NULL) || rear->next->next == front) {
        return true;
    } else
        return false;
}

int main() {
    SqQueue *q = (SqQueue *) malloc(sizeof(SqQueue));
    InitSqQueue(q);
    printf("Empty or not: %d\n", EmptyQueue());
    printf("Full or not:%d\n", FullQueue());
    printf("-------------\n");
    EnQueue(q, 1);  // 进队
    printf("Empty or not: %d\n", EmptyQueue());
    printf("Full or not:%d\n", FullQueue());
    printf("-------------\n");
    EnQueue(q, 2);  // 进队
    printf("-------------\n");
    int t1 = DeQueue(); // 出队
    printf("%d\n", t1);
    printf("Empty or not: %d\n", EmptyQueue());
    printf("Full or not:%d\n", FullQueue());
    printf("-------------\n");
    int t2 = DeQueue();
    printf("%d\n", t2);
    printf("Empty or not: %d\n", EmptyQueue());
    printf("Full or not:%d\n", FullQueue());
    printf("-------------\n");
    EnQueue(q, 3);
    printf("Empty or not: %d\n", EmptyQueue());
    printf("Full or not:%d\n", FullQueue());
    printf("-------------\n");
    EnQueue(q, 4);
    printf("Empty or not: %d\n", EmptyQueue());
    printf("Full or not:%d\n", FullQueue());
}