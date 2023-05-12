#include "stdlib.h"
#include "stdio.h"
#include "stdbool.h"
#include "string.h"

int next[5];

void getNext(const char *s, int length) {
    for (int i = 0; i < length; i++) {
        next[i] = 0;
    }
    int i = 0, j = 1;
    while (j < length) {
        if (s[i] == s[j]) {
            next[j] = i + 1;
            i++;
            j++;
        } else {
            if (i == 0) {
                next[j] = 0;
                j++;
            } else {
                i = next[i];
            }
        }
    }
    for (int k = length - 1; k > 1; k--) {
        next[k] = next[k - 1];
    }
    for (int k = 1; k < length; k++) {
        if (s[k] == s[next[k]]) {
            next[k] = next[next[k]];
        }
    }
}

int kmp(const char *s1, int length1, const char *s2, int length2) {
    int i = 0, j = 0;
    int cnt = 0;
    while (i < length1) {
        if (s1[i] == s2[j]) {
            i++;
            j++;
        } else {
            if (j == 0) i++;
            else j = next[j];
        }
        if (j == length2) {
            cnt++;
            i = i - j + 1;
            j = 0;
        }
    }
    return cnt;
}

int main() {
    char s1[] = "aabaacaabaac";
    char s2[] = "aabaac";
    int length1 = 12;
    int length2 = 6;
    int res = kmp(s1, length1, s2, length2);
    printf("%d\t", res);
}