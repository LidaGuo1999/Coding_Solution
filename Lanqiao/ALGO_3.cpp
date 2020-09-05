/*
 * 问题描述：
 * 如果一个自然数N的K进制表示中任意的相邻的两位都不是相邻的数字，那么我们就说这个数是K好数。求L位K进制数中K好数的数目。例如K = 4，L = 2的时候，所有K好数为11、13、20、22、30、31、33 共7个。由于这个数目很大，请你输出它对1000000007取模后的值。
 *
 * 输入格式：两个正整数K和L
 *
 * 思维梳理：
 * 1、使用动态规划，dp[i][j]代表第i位上是j时的K好数的数目，则有递推式dp[i][j] += dp[i-1][p]，其中p为不与j相邻的数字；
 * 2、需要注意的是，我们最后累加时不能加入i=l-1，k=0的数目，因为这是最高位为0的情况；
 */

#include <iostream>
#include <cmath>

using namespace std;

const long long MOD=1000000007;

long long dp[105][105];

int main() {
    int k, l;
    scanf("%d%d", &k, &l);
    
    if (l == 1) {
        if (k == 1) printf("0\n");
        else printf("%d\n", k);
    } else {
        for (int i = 0; i < k; i++) {
            dp[0][i] = 1;
        }
        for (int i = 0; i < l; i++) {
            for (int j = 0; j < k; j++) {
                for (int p = 0; p < k; p++) {
                    if (abs(p-j) != 1) {
                        dp[i][j] += dp[i-1][p];
                        dp[i][j] %= MOD;
                    }
                }
            }
        }

        long long sum = 0;

        for (int i = 1; i < k; i++) {
            sum += dp[l-1][i];
            sum %= MOD;
        }

        printf("%lld\n", sum);

    }

    return 0;
}
