/*
实现 pow(x, n) ，即计算 x 的 n 次幂函数。

思路梳理：
1、主要使用快速幂的思想，通过移位操作不断让指数除以2；
2、需要注意的是存在负数，而负数的二进制表示是补码，所以对于负数，我们先取其绝对值，得出答案后再求个倒数即可；
3、给的测试用例中出现了int的最小值，无法直接取绝对值，所以用了long long类型；

评测结果：
4ms, 54.68%; 6MB, 100%;
 */

#include <math.h>
class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0, base = x;
        long long nn = abs(n);
        while (nn != 0) {
            cout << nn << endl;
            if (nn & 1 != 0) ans *= base;
            nn = nn >> 1;
            base *= base;
        }

        if (n < 0) return 1./ans;
        else return ans;
    }
};