/* 问题描述：N<k时，root(N,k) = N，否则，root(N,k) = root(N',k)。N'为N的k进制表示的各位数字之和。输入x,y,k，输出root(x^y,k)的值 (这里^为乘方，不是异或)，2=<k<=16，0<x,y<2000000000，有一半的测试点里 x^y 会溢出int的范围(>=2000000000) 
 *
 * 输入描述：每组测试数据包括一行，x(0<x<2000000000), y(0<y<2000000000), k(2<=k<=16)
 *
 * 输出描述：输入可能有多组数据，对于每一组数据，root(x^y, k)的值
 * 
 */


#include <stdio.h>

int root(int x, int k) {
    int coef = 0, num = x;
    while (num > 0) {
        coef += num%k;
        num /= k;
    }
    if (coef >= k) coef = root(coef, k);

    return coef;
}

int cal(int x, int y, int k) {
    int ex = root(x, k), rtn = 1, ny = y;
    while (y > 0) {
        if (y%2 == 1) {
            rtn = root(rtn*ex, k);
        }
        ex = root(ex*ex, k);
        y /= 2;
    }

    return rtn;
}

int main() {
    int x, y, k;
    while (scanf("%d %d %d", &x, &y, &k) != EOF) {
        int ans = cal(x, y, k);
        printf("%d\n", ans);
    }

    return 0;
}

