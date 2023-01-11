#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

// 树的双亲表示法

#define MaxSize 100
typedef struct PTNode {
    int data;
    int parent;
} PTNode;

typedef struct PTree {
    PTNode nodes[MaxSize];
    int n;
} PTree;

