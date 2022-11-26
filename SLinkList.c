#define MaxSize 50
typedef struct {
    int data;
    int next;
} SLinkList[MaxSize];

//静态链表的初始化
void InitSList(SLinkList space) {
    for (int i = 0; i < MaxSize - 1; i++) {
        space[i].next = i;
    }
    space[MaxSize - 1].next = 0;
}


int main() {
    SLinkList s1;
    InitSList(s1);
//    s1[0].data = 0;
//    s1[0].next = 0;
//
//    s1[1].data = 1;
//    s1[1].next = 1;
    return 0;
}