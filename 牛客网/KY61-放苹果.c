/* 问题描述：把 M 个同样的苹果放在 N 个同样的盘子里，允许有的盘子空着不放，问共有多少种不同的分法？
注意：5、1、1 和 1、5、1 是同一种分法，即顺序无关。
 *
 * 输入描述：输入包含多组数据。

每组数据包含两个正整数 m和n（1≤m, n≤20）。
 *
 * 输出描述：对应每组数据，输出一个整数k，表示有k种不同的分法。
 */


#include <stdio.h>
#include <string.h>

int main() {
    int m, n, dp[25][25][25];
    while (scanf("%d %d", &m, &n) != EOF) {
        memset(dp, 0, sizeof(dp));
        for (int j = 1; j <= m; j++) {
            dp[1][j][j] = 1;
        }

        for (int i = 2; i <= n; i++) {
            for (int j = i; j <= m; j++) {
                /*int top = j-i+1, bottom = (j-i+2)/2+1;
                if ((j-i+2)%2 == 0) bottom--;
                for (int k = j-top; k <= j-bottom; k++) dp[i][j] += dp[i-1][k];
                if (j%i == 0 && j/i < bottom) dp[i][j]++;*/

                for (int k = 1; k <= j; k++) {
                    for (int p = 1; p <= k; p++) dp[i][j][k] += dp[i-1][j-k][p];
                }
            }
        }

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int k = 1; k <= m; k++) {
                ans += dp[i][m][k];
            }
        }

        printf("%d\n", ans);
    }

    return 0;
}
