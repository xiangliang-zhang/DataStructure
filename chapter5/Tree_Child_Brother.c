#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

// 孩子兄弟表示法, 左孩子、右兄弟

typedef struct Child_Brother_Node {
    int data;
    struct Child_Brother_Node *firstChild;
    struct Child_Brother_Node *nextSibling;
} Child_Brother_Node, *CBTree;



