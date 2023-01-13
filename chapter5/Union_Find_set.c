#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

// 并查集

#define MaxSize 100

void InitUFSets(int UFSets[], int size) {
    for (int i = 0; i < size; i++) {
        UFSets[i] = -1;
    }
}

int Find_UFSets(const int UFSets[], int x) {
    while (UFSets[x] >= 0) {
        x = UFSets[x];
    }
    return x;
}

void Merge(int UFSets[], int root1, int root2) {
    if (root1 != root2) {
        UFSets[root2] = root1;
    }
}

int main() {
    int size = 9;
    int UFSets[MaxSize];
    InitUFSets(UFSets, size);
    int res1 = Find_UFSets(UFSets, 8);
    printf("%d\n", res1);
    Merge(UFSets, 7, 8);
    int res2 = Find_UFSets(UFSets, 7);
    printf("%d\n", res2);
    int res3 = Find_UFSets(UFSets, 8);
    printf("%d\n", res3);
}