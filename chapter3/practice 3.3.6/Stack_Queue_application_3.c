#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

// 实现函数的非递归计算

int Recursion(int n, int x) {
    if (n == 0) {
        return 1;
    } else if (n == 1) {
        return x * 2;
    } else {
        return 2 * x * Recursion(n - 1, x) - 2 * (n - 1) * Recursion(n - 2, x);
    }
}

#define MaxSize 100

typedef struct SqStack {
    int data[MaxSize];
    int head;
} SqStack;

void InitStack(SqStack *s) {
    s->head = -1;
}

void EnQueue(SqStack *s, int x) {
    s->head++;
    s->data[s->head] = x;
}

int DeQueue(SqStack *s) {
    int t = s->data[s->head];
    s->head--;
    return t;
}

int NonRecursion(SqStack *s, int x, int n) {
    if (n == 0) {
        return 1;
    } else if (n == 1) {
        return 2 * x;
    } else {
        EnQueue(s, 1);
        EnQueue(s, 2 * x);
        int temp;
        int cnt = 2;
        while (cnt <= n) {
            int t1 = DeQueue(s);
            int t2 = DeQueue(s);
            temp = (2 * x * t1) - (2 * (cnt - 1) * t2);
            EnQueue(s, t1);
            EnQueue(s, temp);
            cnt++;
        }
        return temp;
    }
}

int main() {

    SqStack *s = (SqStack *) malloc(sizeof(SqStack));
    InitStack(s);

    int res1 = Recursion(5, 4);
    int res2 = NonRecursion(s, 4, 5);

    printf("%d\n", res1);
    printf("%d\n", res2);
}