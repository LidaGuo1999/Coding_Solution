/*
题目描述：
实现 int sqrt(int x) 函数。

计算并返回 x 的平方根，其中 x 是非负整数。

由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。

思路梳理：
利用二分法，逐渐找到该平方根即可。

提交结果：
0ms, 100%; 5.8MB, 100%;
 */

class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1) return x;
        int cur_min = 0, cur_max = x;
        while (cur_max-cur_min>1) {
            int middle = (cur_max+cur_min)/2;
            if (x/middle<middle) cur_max = middle;
            else cur_min = middle;
        }

        return cur_min;
    }
};