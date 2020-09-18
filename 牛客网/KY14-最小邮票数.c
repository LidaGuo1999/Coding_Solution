/* 问题描述：有若干张邮票，要求从中选取最少的邮票张数凑成一个给定的总值。     如，有1分，3分，3分，3分，4分五张邮票，要求凑成10分，则使用3张邮票：3分、3分、4分即可。
 *
 * 输入描述：有多组数据，对于每组数据，首先是要求凑成的邮票总值M，M<100。然后是一个数N，N〈20，表示有N张邮票。接下来是N个正整数，分别表示这N张邮票的面值，且以升序排列。
 *
 * 输出描述：对于每组数据，能够凑成总值M的最少邮票张数。若无解，输出0。
 */

#include <stdio.h>
#include <string.h>

void dynamic(int m, int n, int piece[25], int dp[25][105]) {
    if (n < 1) return ;
    
    dp[1][piece[1]] = 1;
    for (int i = 1; i <= n; i++) dp[i][0] = 0;
    //printf("dp[4][0]: %d\n", dp[4][0]);
    //for (int i = 1; i <= m; i++) printf("%d ", dp[1][i]);
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int tmp1 = dp[i-1][j];
            int tmp2 = 1000000;
            if (piece[i] <= j) tmp2 = 1+dp[i-1][j-piece[i]];
            dp[i][j] = tmp1<tmp2 ? tmp1 : tmp2;
            //printf("%d %d: %d %d %d\n", i, j, dp[i][j], tmp1, tmp2);
        }
    }
    return ;
}

int main() {
    int m, n;
    int piece[25] = {0}, dp[25][105];
    while (scanf("%d %d", &m, &n) != EOF) {
        memset(piece, 0, sizeof(piece));
        memset(dp, 1000000, sizeof(dp));
        for (int i = 1; i <= n; i++) 
            scanf("%d", &piece[i]);
        
        dynamic(m, n, piece, dp);
        if (dp[n][m] >= 1000000) printf("0\n");
        else printf("%d\n", dp[n][m]);
    }
    
    return 0;
}
