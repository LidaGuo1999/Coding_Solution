/* 问题描述：一个数如果恰好等于它的各因子(该数本身除外)子和，如：6=3+2+1。则称其为“完数”；若因子之和大于该数，则称其为“盈数”。 求出2到60之间所有“完数”和“盈数”。
 *
 * 输入描述：题目没有任何输入。
 * 
 * 输出描述：输出2到60之间所有“完数”和“盈数”，并以如下形式输出：
E: e1 e2 e3 ......(ei为完数)
G: g1 g2 g3 ......(gi为盈数)
其中两个数之间要有空格，行尾不加空格。
 */


#include <stdio.h>

int judge(int num) {
    int sum = 0;
    for (int i = 1; i*i <= num; i++) {
        if (num%i == 0) {
            sum += i;
            sum += num/i;
        }
        if (i*i == num) sum -= i;
    }
    sum -= num;

    if (sum == num) return 1;
    else if (sum > num) return 0;
    else return -1;
}

int main() {
    int complete[60] = {0}, wane[60] = {0}, ci = 0, wi = 0;
    for (int i = 2; i <= 60; i++) {
        if (judge(i) == 1) complete[ci++] = i;
        else if (judge(i) == 0) wane[wi++] = i;
    }

    printf("E:");
    for (int i = 0; i < ci; i++) printf(" %d", complete[i]);
    printf("\n");
    printf("G:");
    for (int i = 0; i < wi; i++) printf(" %d", wane[i]);
    printf("\n");

    return 0;
}
