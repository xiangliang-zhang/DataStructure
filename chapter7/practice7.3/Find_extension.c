#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

// 查找出现次数超过两次的数字

int FindEle(const int *data, int length) {
    int num = data[0];
    int cnt = 1;
    for (int i = 1; i < length; i++) {
        if (data[i] == num) {
            cnt++;
        } else {
            cnt--;
            if (cnt == 0) {
                num = data[i];
                cnt = 1;
            }
        }
    }
    cnt = 0;
    for (int i = 0; i < length; i++) {
        if (data[i] == num) {
            cnt++;
        }
    }
    if (cnt >= length / 2) {
        return num;
    } else {
        return -1;
    }
}

int main() {
    int data[] = {0, 6, 1, 6, 2, 6, 3, 6, 4, 6, 5, 6, 6};
    int length = sizeof(data) / sizeof(data[0]);
    int res = FindEle(data, length);
    printf("%d\n", res);
}