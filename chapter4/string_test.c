#include <string.h>
#include <stdbool.h>
#include "stdio.h"
#include "stdlib.h"

// ���������Ѵ�����ֵ����ʼ����
#define MaxSize 50
typedef struct {
    char ch[MaxSize];
    int length;
} SString;

// �Ѵ�
typedef struct {
    char *ch;
    int length;
} HString;

// �ַ�����ֵ���Ѵ�T��ֵ��chars���ch
int StrAssign(char T[], SString *chars) {
    unsigned long long len_char = strlen(T);
    for (int i = 0; i < len_char; i++) {
        chars->ch[i] = T[i];
        chars->length++;
    }
    return 0;
}

// ��ʼ����
bool InitSString(SString *s) {
    s->length = 0;
    return true;
}

bool InitHString(HString *h) {
    h->length = 0;
    h->ch = (char *) malloc(sizeof(char) * 5);
    return true;
}

// �д���
bool StrEmpty(SString *s) {
    if (s->length == 0) {
        return true;
    } else {
        return false;
    }
}

// ��մ�
bool ClearString(SString *s) {
    s->length = 0;
    return true;
}

// ���ٴ�
bool DestroyString(SString *s) {
    s->length = 0;
    free(s);
    return true;
}

// ��ȡ���ĳ���
int StrLength(SString *s) {
    return s->length;
}

// ���ƴ�
SString *StrCopy(SString *s) {
    SString *t = NULL;
    for (int i = 0; i < s->length; i++) {
        t->ch[i] = s->ch[i];
    }
    t->length = s->length;
    return t;
}

// �Ƚϴ���s <= tʱ����0�����򷵻�1
int StrCompare(SString s, SString t) {
    if (s.length > 0 && t.length > 0) {
        int len_short;
        if (s.length <= t.length) {
            len_short = s.length;
        } else {
            len_short = t.length;
        }
        for (int i = 0; i < len_short; i++) {
            if (s.ch[i] < t.ch[i]) {
                return 1;
            } else if (s.ch[i] == t.ch[i]) {
                continue;
            }
        }
        if (s.length == t.length) {
            return 0;
        } else if (s.length > t.length) {
            return 1;
        } else if (s.length < t.length) {
            return 0;
        }
    }
    return 0;  // Ĭ������·���0
}

// ���Ӵ�
char* SubString(SString s1, int pos, int len) {
    if (pos < 0 || pos > s1.length - 1) {
        return NULL;
    }
    char *res = (char *) malloc(sizeof(char) * len + 1);
    int j = 0;
    for (int i = pos; i < pos + len; i++, j++) {
        res[j] = s1.ch[i];
    }
    res[j] = '\0';  // �ַ����Ľ���
    return res;
}

// �ַ�������
char *ConcatString(SString s1, SString s2) {
    char *res = (char *) malloc(sizeof(char) * (s1.length + s2.length + 1));
    for (int i = 0; i < s1.length; i++) {
        res[i] = s1.ch[i];
    }
    for (int i = s1.length; i < (s1.length + s2.length); i++) {
        res[i] = s2.ch[i - s1.length];
    }
    res[s1.length + s2.length] = '\0';
    return res;
}

// �����ַ���ƥ��
int Index(SString s1, SString s2) {
    if (s2.length <= s1.length) {
        for (int i = 0; i <= (s1.length - s2.length); i++) {
            if (s2.ch[0] == s1.ch[i]) {
                int flag = 0;
                for (int j = i, i2 = 0; i2 < s2.length; j++, i2++) {
                    if (s2.ch[i2] == s1.ch[j]) {
                        flag = 1;
                    } else {
                        flag = 0;
                    }
                    if (flag == 0) {
                        break;
                    } else if (i2 + 1 == s2.length) {
                        return i;
                    }
                }
            }
        }
    }
    return -1;
}

int main() {
    SString s1;
    SString s2;

    // ��ʼ��
    InitSString(&s1);
    InitSString(&s2);

    // ��ֵ
    char t[] = "abc";
    char t2[] = "c";
    StrAssign(t, &s1);
    StrAssign(t2, &s2);

    // �Ƚ�
    int res = StrCompare(s1, s2);
    printf("��s1�봮s2���бȽ�: %d (1: ���ڣ� 0: С�ڵ���)\n", res);

    // ���Ӵ�
    int pos = 1;
    int len = 2;
    char *res_sub = SubString(s1, pos, len);
    printf("�Ӵ�:%s \n", res_sub);

    // ����
    char *concat = ConcatString(s1, s2);
    printf("�����ִ��Ľ��: %s \n", concat);

    // �ִ�λ��
    int index = Index(s1, s2);
    printf("s2��s1����ʼλ��Index: %d\n", index);
    return 0;
}