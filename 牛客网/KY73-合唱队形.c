/* 问题描述：N位同学站成一排，音乐老师要请其中的(N-K)位同学出列，使得剩下的K位同学不交换位置就能排成合唱队形。 合唱队形是指这样的一种队形：设K位同学从左到右依次编号为1, 2, …, K，他们的身高分别为T1, T2, …, TK， 则他们的身高满足T1 < T2 < … < Ti , Ti > Ti+1 > … > TK (1 <= i <= K)。 你的任务是，已知所有N位同学的身高，计算最少需要几位同学出列，可以使得剩下的同学排成合唱队形。
 *
 * 输入描述：输入的第一行是一个整数N（2 <= N <= 100），表示同学的总数。
第一行有n个整数，用空格分隔，第i个整数Ti（130 <= Ti <= 230）是第i位同学的身高（厘米）。
 *
 * 输出描述：可能包括多组测试数据，对于每组数据，
输出包括一行，这一行只包含一个整数，就是最少需要几位同学出列。
 */


#include <stdio.h>
#include <string.h>

int main() {
    int n, height[105] = {0}, dp[105][2] = {0};
    while (scanf("%d", &n) != EOF) {
        memset(height, 0, sizeof(height));
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; i++) scanf("%d", &height[i]);

        dp[1][0] = 1, dp[1][1] = 1;
        int remain = 1;
        for (int i = 2; i <= n; i++) {
            int max_up = 1, max_down = 1;
            for (int j = 1; j < i; j++) {
                if (height[i] > height[j]) {
                    max_up = (dp[j][0]+1)>max_up ? dp[j][0]+1 : max_up;
                } else if (height[i] < height[j]) {
                    max_down = (dp[j][0]+1)>max_down ? dp[j][0]+1 : max_down;
                    max_down = (dp[j][1]+1)>max_down ? dp[j][1]+1 : max_down;
                }
            }

            dp[i][0] = max_up, dp[i][1] = max_down;
            remain = max_up>remain ? max_up : remain;
            remain = max_down>remain ? max_down : remain;
        }

        int ans = n-remain;

        printf("%d\n", ans);
    }

    return 0;
}
