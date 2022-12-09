#include <string.h>
#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"


// 判断出栈进栈序列是否合法
#define MaxSize 100

// 顺序栈存储结构
typedef struct SqStack{
    int data[MaxSize];
    int head;
} SqStack;

bool IsLegal(const char *s, int length){
    int input_num = 0;
    int output_num = 0;
    for(int i = 0; i < length; i++){
        if(s[i] == 'I'){
            input_num++;
        }else if(s[i] == 'O'){
            output_num++;
        }
        if(output_num > input_num){
            return false;
        }
    }
    if(input_num == output_num){
        return true;
    }else{
        return false;
    }
}

int main(){
    char t[] = "IIIOOIOO";
    int length = strlen(t);
    int res = IsLegal(t, length);
    printf("%d\n", res);
}

