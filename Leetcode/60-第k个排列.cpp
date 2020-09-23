/* 问题描述：给出集合[1,2...,n]，所有元素共有n！种排列，按照大小顺序列出所有排列情况，输入一个数字k，返回第k个排列
 *
 * 思路梳理：
 * 1、首先当然直观想到全排列的算法，但是显然全排列在这里浪费了很多时间，因为我们只想知道第k个排列是什么；
 * 2、以n=4举例，最高位的值应该当前尚存数字中第（k除(n-1)!的商+1）小的值，以此类推，即可找到规律；
 * 3、需要注意的是，如果余数为0，那么要特殊考虑，将剩余数字直接倒序输出即可；
 * 4、总的来说，该题更像一个偏重数学知识的题目，不需要太多的算法技巧。
 *
 * 评测结果：0ms，95%；6.3MB，2%；
 */

class Solution {
public:
    string getPermutation(int n, int k) {
        int fac[10] = {1}, tmp = 1;
        for (int i = 1; i <= n; i++) {
            tmp *= i;
            fac[i] = tmp;
        }

        vector<string> flag(n);
        for (int i = 0; i < n; i++) {
            flag[i] = to_string(i+1);
        }
        
        string ans = "";
        for (int i = n-1; i > 0; i--) {
            int q = k / fac[i];
            k %= fac[i];
            if (k == 0) {
                ans += flag[q-1];
                flag.erase(flag.begin()+q-1);
                for (int j = i-1; j > 0; j--) ans += flag[j];
                break;
            } else {
                ans += flag[q];
                flag.erase(flag.begin()+q);
            }

        }
        ans += flag[0];

        return ans;
    }
};
