/*
 *
 * 思路梳理：
 * 1、设整数为n时不同的二叉搜索树有dp[n]个，当根节点为i时，有dp[i-1]*dp[n-i]种情况，因为左子树有i-1个节点，右子树有n-i个节点；
 * 2、故根据上述分析，这就是一道动态规划题，两层循环即可搞定。
 *
 * 评测结果：
 * 0ms，100%；5.4MB，5.62%；
 */


int numTrees(int n){
    int dp[100005] = {0};
    dp[0] = 1;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            dp[i] += dp[j]*dp[i-1-j];
        }
    }

    return dp[n];
}
