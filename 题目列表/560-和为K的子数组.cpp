/*
给定一个整数数组和一个整数 k，你需要找到该数组中和为 k 的连续的子数组的个数。

思路梳理：
1、从头遍历一次数组，将从第0个元素到第i个元素的前i+1项和存在一个map中；
2、在遍历到第i个元素时，我们在将第i个元素的值加到total中之后，需要判断map中是否有total-k，如果有，则证明从第j（j<i）个元素到第i个元素的和为k；

评测结果：
152ms, 32.26%; 22.6MB, 6.67%;
 */

#include <map>
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int, int> appear;
        int total = 0, ans = 0;
        appear[0] = 1;
        for (int i = 0; i < nums.size(); i++) {
            total += nums[i];
            if (appear.find(total-k) != appear.end()) {
                ans += appear[total-k];
            }
            if (appear.find(total) == appear.end()) appear[total] = 1;
            else appear[total]++;
        }

        return ans;
    }
};