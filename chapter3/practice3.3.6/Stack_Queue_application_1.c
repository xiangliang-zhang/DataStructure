#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

// 括号匹配，栈

#define MaxSize 100

typedef struct SqStack {
    char data[MaxSize];
    int head;
} SqStack;

void InitStack(SqStack *s) {
    s->head = -1;
}

void Push(SqStack *s, char v) {
    s->head++;
    s->data[s->head] = v;
}

bool EmptyStack(SqStack *s) {
    if (s->head == -1) {
        return true;
    } else {
        return false;
    }
}

char Pop(SqStack *s) {
    char t = s->data[s->head];
    s->head--;
    return t;
}

bool contain(char c) {
    char brackets[] = "([{";
    for (int i = 0; i < 3; i++) {
        if (brackets[i] == c) {
            return true;
        }
    }
    return false;
}

bool isValidBrackets(char *c, int length, SqStack *s) {
    for (int i = 0; i < length; i++) {
        int contains = contain(c[i]);
        if (contains == 1) {
            Push(s, c[i]);
        } else {
            char t = Pop(s);
            if ((t == '(' && c[i] == ')') || (t == '[' && c[i] == ']') || (t == '{' && c[i] == '}')) {
                continue;
            } else {
                return false;
            }
        }
    }
    if (EmptyStack(s)) {
        return true;
    } else {
        return false;
    }
}

int main() {
    char c[] = "{[]})";
    SqStack *s = (SqStack *) malloc(sizeof(SqStack));
    InitStack(s);
    int length2 = sizeof(c) / sizeof(c[0]) - 1;
    int res = isValidBrackets(c, length2, s);
    printf("%d\n", res);
}