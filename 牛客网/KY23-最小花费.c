/* 问题描述：在某条线路上有N个火车站，有三种距离的路程，L1，L2，L3,对应的价格为C1,C2,C3.其对应关系如下: 距离s           票价 0<S<=L1         C1 L1<S<=L2        C2 L2<S<=L3        C3 输入保证0<L1<L2<L3<10^9,0<C1<C2<C3<10^9。 每两个站之间的距离不超过L3。 当乘客要移动的两个站的距离大于L3的时候，可以选择从中间一个站下车，然后买票再上车，所以乘客整个过程中至少会买两张票。 现在给你一个 L1，L2，L3，C1，C2,C3。然后是A B的值，其分别为乘客旅程的起始站和终点站。 然后输入N，N为该线路上的总的火车站数目，然后输入N-1个整数，分别代表从该线路上的第一个站，到第2个站，第3个站，……，第N个站的距离。 根据输入，输出乘客从A到B站的最小花费。
 *
 * 输入描述：以如下格式输入数据：
L1  L2  L3  C1  C2  C3
A  B
N
a[2]
a[3]
……
a[N]
 * 
 * 输出描述：可能有多组测试数据，对于每一组数据，
根据输入，输出乘客从A到B站的最小花费。
 */


#include <stdio.h>
#include <string.h>

int main() {
    int l1, l2, l3, c1, c2, c3, a, b, n;
    int dis[100005] = {0}, dp[100005] = {0};
    while (scanf("%d %d %d %d %d %d %d %d %d", &l1, &l2, &l3, &c1, &c2, &c3, &a, &b, &n) != EOF) {
        memset(dis, 0, sizeof(dis));
        memset(dp, 0, sizeof(dp));
        for (int i = 2; i <= n; i++) {
            scanf("%d", &dis[i]);
        }
        if (a > b) {
            int tmp = a;
            a = b;
            b = tmp;
        }

        for (int i = 1; i <= b-a; i++) {
            int cur_min = 1000000000;
            for (int j = 1; j <= i; j++) {
                int gap = dis[i+a]-dis[i-j+a];
                if (gap > l3) break;
                if (gap == 0) cur_min = dp[i-j]<cur_min ? dp[i-j] : cur_min;
                else if (gap > 0 && gap <= l1) cur_min = (dp[i-j]+c1)<cur_min ? dp[i-j]+c1 : cur_min;
                else if (gap > l1 && gap <= l2) cur_min = (dp[i-j]+c2)<cur_min ? dp[i-j]+c2 : cur_min;
                else if (gap > l2 && gap <= l3) cur_min = (dp[i-j]+c3)<cur_min ? dp[i-j]+c3 : cur_min;
            }
            dp[i] = cur_min;
        }
        printf("%d\n", dp[b-a]);
    }

    return 0;
}
