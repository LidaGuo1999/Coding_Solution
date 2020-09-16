/* 题目描述：求正整数N(N>1)的质因数的个数。 相同的质因数需要重复计算。如120=2*2*2*3*5，共有5个质因数。
 *
 * 输入描述：可能有多组测试数据，每组测试数据的输入是一个正整数N，(1<N<10^9)。
 *
 * 输出描述：对于每组数据，输出N的质因数的个数。
 */

#include <iostream>

using namespace std;

int cal(int n) {
    if (n < 4) return 1;
    int nn = n, i = 2, cnt = 0;
    while (i <= nn) {
        //printf("%d ", nn);
        if (nn%i == 0) {
            cnt++;
            nn /= i;
        } else {
            i++;
        }
    }
    
    return cnt;
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        int ans = cal(n);
        printf("%d\n", ans);
    }
    
    return 0;
}
