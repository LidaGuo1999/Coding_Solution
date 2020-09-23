/*
编写一个算法来判断一个数 n 是不是快乐数。

「快乐数」定义为：对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和，然后重复这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到 1。如果 可以变为  1，那么这个数就是快乐数。

如果 n 是快乐数就返回 True ；不是，则返回 False 。
 */


// 经过观察，int类型的正整数各个位数平方和不会超过1000，所以我们设置一个常为1000的标记数组，将出现过的数字标记为1即可
// 接下来只需要使用模拟法求解即可。当然也可以使用快慢指针法。
// 4ms, 67.79%; 5.9MB, 100%;
#include <math.h>

class Solution {
public:
    bool isHappy(int n) {
        int flag[1000] = {0};
        int sum = 0;
        int cur = n;
        if (n < 1000) flag[n] = 1;

        while (1) {
            sum = 0;
            while (cur >= 10) {
                sum += pow(cur%10, 2);
                cur = cur/10;
            }
            sum += pow(cur, 2);
            if (sum == 1) return true;
            if (flag[sum] == 1) return false;
            flag[sum] = 1;
            cur = sum;
        }
    }
};