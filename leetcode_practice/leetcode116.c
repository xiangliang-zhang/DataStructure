#include "stdlib.h"
#include "stdbool.h"
#include "stdio.h"

// 满二叉树每层的结点前后相连

struct Node {
    int val;
    struct Node *left;
    struct Node *right;
    struct Node *next;
};

#define MaxSize (10000)

typedef struct Queue {
    struct Node *data[MaxSize];
    int head, tail;
} Queue;

void initQueue(Queue *q) {
    q->head = 0;
    q->tail = -1;
}

void enQueue(Queue *q, struct Node *node) {
    if (q->tail < MaxSize) {
        q->tail++;
        q->data[q->tail] = node;
    }
}

struct Node *deQueue(Queue *q) {
    if (q->head <= q->tail) {
        struct Node *res = q->data[q->head];
        q->head++;
        return res;
    } else {
        return NULL;
    }
}

bool emptyQueue(Queue *q) {
    if (q->head <= q->tail) {
        return false;
    } else {
        return true;
    }
}

struct Node *connect(struct Node *root) {
    if (root == NULL) {
        return root;
    }
    Queue *q1 = (Queue *) malloc(sizeof(Queue));
    initQueue(q1);
    Queue *q2 = (Queue *) malloc(sizeof(Queue));
    initQueue(q2);
    struct Node *temp = root;
    enQueue(q1, temp);
    struct Node *visit = NULL;
    while (!emptyQueue(q1)) {
        while (!emptyQueue(q1)) {
            temp = deQueue(q1);
            if (visit == NULL) {
                visit = temp;
            } else {
                visit->next = temp;
                visit = temp;
            }
            if (emptyQueue(q1)) {
                visit = NULL;
            }
            if (temp->left != NULL) enQueue(q2, temp->left);
            if (temp->right != NULL) enQueue(q2, temp->right);
        }
        while (!emptyQueue(q2)) {
            temp = deQueue(q2);
            if (visit == NULL) {
                visit = temp;
            } else {
                visit->next = temp;
                visit = temp;
            }
            if (emptyQueue(q2)) {
                visit = NULL;
            }
            if (temp->left != NULL) enQueue(q1, temp->left);
            if (temp->right != NULL) enQueue(q1, temp->right);
        }
    }
    return root;
}

struct Node *setValue() {
    struct Node *root = malloc(sizeof(typeof(struct Node)));
    root->val = 0;
    root->left = NULL;
    root->right = NULL;
    root->next = NULL;


    struct Node *node1 = malloc(sizeof(typeof(struct Node)));
    node1->val = 1;
    node1->left = NULL;
    node1->right = NULL;
    node1->next = NULL;

    struct Node *node2 = malloc(sizeof(typeof(struct Node)));
    node2->val = 2;
    node2->left = NULL;
    node2->right = NULL;
    node2->next = NULL;

    struct Node *node3 = malloc(sizeof(typeof(struct Node)));
    node3->val = 3;
    node3->left = NULL;
    node3->right = NULL;
    node3->next = NULL;

    struct Node *node4 = malloc(sizeof(typeof(struct Node)));
    node4->val = 4;
    node4->left = NULL;
    node4->right = NULL;
    node4->next = NULL;

    struct Node *node5 = malloc(sizeof(typeof(struct Node)));
    node5->val = 5;
    node5->left = NULL;
    node5->right = NULL;
    node5->next = NULL;

    struct Node *node6 = malloc(sizeof(typeof(struct Node)));
    node6->val = 6;
    node6->left = NULL;
    node6->right = NULL;
    node6->next = NULL;

    root->left = node1;
    node1->left = node2;
    node1->right = node3;
    root->right = node4;
    node4->left = node5;
    node4->right = node6;

    return root;
}

int main() {
    struct Node *tree = setValue();
    tree = connect(tree);
    printf("");
}