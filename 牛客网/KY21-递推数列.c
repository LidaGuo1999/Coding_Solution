/* 问题描述：
给定a0,a1,以及an=p*a(n-1) + q*a(n-2)中的p,q。这里n >= 2。 求第k个数对10000的模。
 *
 * 输入描述：输入包括5个整数：a0、a1、p、q、k。
 *
 * 输出描述：第k个数a(k)对10000的模。
 */


#include <stdio.h>

#define MOD 10000

int main() {
    int a0, a1, p, q, k;
    int dp[100005] = {0};
    scanf("%d %d %d %d %d", &a0, &a1, &p, &q, &k);
    dp[0] = a0, dp[1] = a1;

    for (int i = 2; i <= k; i++) {
        dp[i] = ((p*dp[i-1])%MOD +q*dp[i-2]%MOD) % MOD;
    }
    printf("%d\n", dp[k]);

    return 0;
}
