/*
 *
 * 思路梳理：
 * 1、利用不断移位找到数n的二进制表示；
 * 2、然后将幂次大于2的进行递归输出，幂次为0，1，2的直接输出即可；
 *
 */


#include <iostream>
#include <cstring>
#include <cstdlib>

char ans[20005];
int pos;

void output(int n) {
    int flag[20] = {0}, nn = n, spos = pos, epos = 0;
    for (int i = 0; i < 20; i++) {
        if (nn&1 != 0) {
            flag[i] = 1;
        }
        nn = nn >> 1;
    }
    /*for (int i = 0; i < 20; i++) printf("%d ", flag[i]);
    printf("\n");*/
    for (int i = 19; i > 2; i--) {
        if (flag[i] == 1) {
            ans[pos++] = '2';
            ans[pos++] = '(';
            output(i);
            ans[pos++] = ')';
            ans[pos++] = '+';
        }
    }
    if (flag[2] == 1) {
        ans[pos++] = '2';
        ans[pos++] = '(';
        ans[pos++] = '2';
        ans[pos++] = ')';
        ans[pos++] = '+';
    }
    if (flag[1] == 1) {
        ans[pos++] = '2';
        ans[pos++] = '+';
    }
    if (flag[0] == 1) {
        ans[pos++] = '2';
        ans[pos++] = '(';
        ans[pos++] = '0';
        ans[pos++] = ')';
        ans[pos++] = '+';
    }
    epos = pos;
    if (epos > spos) {
        if (ans[pos-1] == '+') {
            ans[pos-1] = '\0';
            pos--;
        }
    }
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        memset(ans, 0, sizeof(ans));
        pos = 0;
        output(n);
        ans[pos] = '\0';
        printf("%s\n", ans);
    }
    
    return 0;
}
