/*
 * 问题描述：
 * 有一棵 n 个节点的树，树上每个节点都有一个正整数权值。如果一个点被选择了，那么在树上和它相邻的点都不能被选择。求选出的点的权值和最大是多少？
 *
 * 输入格式：
 * 第一行包含一个整数 n 。
 * 接下来的一行包含 n 个正整数，第 i 个正整数代表点 i 的权值。
 * 接下来一共 n-1 行，每行描述树上的一条边。
 *
 * 输出格式：
 * 输出一个整数，代表选出的点的权值和的最大值。
 *
 * 思路梳理：
 * 1、这道题是一道“树型动态规划”题目，dp[i][0]代表不选择第i个节点的最大值，dp[i][1]代表选择第i个节点的最大值；
 * 2、那么就可以得到动态规划递推式dp[i][0] += max(dp[j][0], dp[j][1])，j为节点i的子节点，dp[i][1] += dp[j][0]；
 * 3、剩下的问题就是如何遍历这棵树，我采用DFS，因为上层的节点依赖于下层节点的结果；
 * 4、且由于树的性质，从任何一个节点开始DFS都不会影响结果（只需要将开始的节点看做是根节点即可）。
 */

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 100005;
int head[MAXN];
int dp[MAXN][2];
int M;

struct edge {
    int to, nextEdge;
} edges[2*MAXN];

void add(int from, int to) {
    edges[M].to = to;
    edges[M].nextEdge = head[from];
    head[from] = M++;
}

void dfs(int node, int preNode) {
    for (int i = head[node]; i != -1; i = edges[i].nextEdge) {
        if (edges[i].to == preNode) 
            continue;
        int toNode = edges[i].to;
        //cout << toNode << endl;
        dfs(toNode, node);
        dp[node][0] += max(dp[toNode][0], dp[toNode][1]);
        dp[node][1] += dp[toNode][0];
    }
}

int main() {
    int n;
    memset(head, -1, sizeof(head));
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &dp[i][1]);
    }

    for (int i = 0; i < n-1; i++) {
        int from, to;
        scanf("%d%d", &from, &to);
        add(from, to);
        add(to, from);
    }

    /*for (int i = 0; i < 2*n-2; i++) {
        printf("%d %d\n", edges[i].to, edges[i].nextEdge);
    }
    cout << "step1" << endl;*/
    dfs(1, 0);

    printf("%d\n", max(dp[1][0], dp[1][1]));

    return 0;
}
