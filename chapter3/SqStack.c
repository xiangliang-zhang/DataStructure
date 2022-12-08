#include "stdio.h"
#include "stdbool.h"

#define MaxSize 50
typedef struct{
    int data[MaxSize];
    int top;
} SqStack;

// 初始化栈，元素均置0，top指针置为-1
void InitStack(SqStack *s){
    s->top = -1;
    for(int i = 0; i < MaxSize; i++){
        s->data[i] = 0;
    }
}

// 判断栈空
bool isEmpty(SqStack *s){
    if(s->top == -1){
        return true;
    }else{
        return false;
    }
}

// 进栈
bool Push(SqStack *s, int v){
    if (s->top + 1 < MaxSize){
        s->top++;
        s->data[s->top] = v;
        return true;
    }else{
        return false;
    }

}

// 出栈
bool Pop(SqStack *s, int *t){
    if (s->top > -1 && s->top < MaxSize){
        *t = s->data[s->top];
        s->top--;
        return true;
    }else{
        return false;
    }
}

// 读栈顶元素
bool GetTop(SqStack *s, int *top){
    if (s->top > -1 && s->top < MaxSize){
        *top = s->data[s->top];
        return true;
    }else{
        return false;
    }
}

int main(){
    int t = -1;
    int top = -1;
    SqStack s;
    InitStack(&s);
    printf("Empty or not: %d\n", isEmpty(&s));
    Push(&s, 1);
    GetTop(&s, &top);
    printf("top: %d\n", top);
    if (!isEmpty(&s))
        Pop(&s, &t);
    printf("t: %d\n", t);
    return 0;
}