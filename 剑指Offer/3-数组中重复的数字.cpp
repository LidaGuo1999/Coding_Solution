/*
找出数组中重复的数字。


在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。

 */

// 使用一个长度为n的标记数组，记录当前数字是否出现过了即可。
// 76ms, 60.42%; 23.9MB, 100%;

#include <map>

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        vector<int> flag(nums.size(), 0);
        for (int i = 0; i < nums.size(); i++) {
            if (flag[nums[i]] == 1) return nums[i];
            else flag[nums[i]] = 1;
        }

        return -1;
    }
};