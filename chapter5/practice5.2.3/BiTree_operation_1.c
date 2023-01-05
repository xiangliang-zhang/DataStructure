#include "stdio.h"

// 求二叉树中两个结点的最近公共祖先

int GetPar(int a, int b) {
    int t_a = a;
    int t_b = b;
    while (t_a != t_b) {
        if (t_a < t_b) {
            t_b /= 2;
        } else {
            t_a /= 2;
        }
    }
    return t_a;
}

int main() {
    int a = 9;
    int b = 10;
    int res = GetPar(a, b);
    printf("最近公共祖先为:%d\n", res);
}