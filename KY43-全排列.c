/* 问题描述：给定一个由不同的小写字母组成的字符串，输出这个字符串的所有全排列。 我们假设对于小写字母有'a' < 'b' < ... < 'y' < 'z'，而且给定的字符串中的字母已经按照从小到大的顺序排列。
 *
 * 输入描述：输入只有一行，是一个由不同的小写字母组成的字符串，已知字符串的长度在1到6之间。
 *
 * 输出描述：输出这个字符串的所有排列方式，每行一个排列。要求字母序比较小的排列在前面。字母序如下定义：
已知S = s1s2...sk , T = t1t2...tk，则S < T 等价于，存在p (1 <= p <= k)，使得
s1 = t1, s2 = t2, ..., sp - 1 = tp - 1, sp < tp成立。

每组样例输出结束后要再输出一个回车。
 */


#include <stdio.h>
#include <string.h>

void sort(char ar[10]) {
    int n = strlen(ar);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (ar[j] > ar[j+1]) {
                char tmp = ar[j];
                ar[j] = ar[j+1];
                ar[j+1] = tmp;
            }
        }
    }

    return ;
}

void full_range(char ar[10], char pr[10]) {
    int n = strlen(ar), pn = strlen(pr);
    if (n == 1) {
        printf("%s%s\n", pr, ar);
        if (pn != 0) pr[pn-1] = 0;
        return ;
    } else if (n == 2) {
        printf("%s%c%c\n", pr, ar[0], ar[1]);
        printf("%s%c%c\n", pr, ar[1], ar[0]);
        if (pn != 0) pr[pn-1] = 0;
        return ;
    }

    for (int i = 0; i < n; i++) {
        pr[pn] = ar[i];
        char tmp[10] = {0};
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if (j != i) tmp[cnt++] = ar[j];
        }
        full_range(tmp, pr);
    }
    if (pn != 0) pr[pn-1] = 0;
}

int main() {
    char ar[10] = {0}, pr[10] = {0};
    scanf("%s", ar);
    sort(ar);
    full_range(ar, pr);

    return 0;
}
