/*
给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

示例:

输入: [-2,1,-3,4,-1,2,1,-5,4],
输出: 6
解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。

思维梳理：
这是一道经典的分治题目，将当前数组二分，分别得到左半部分的最大子序列和以及右半部分的最大子序列和，同时计算出横跨分割线的最大子序列和，三者中取最大值即可。
8ms, 74.51%; 7MB, 100%;
*/


#include <algorithm>
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        return recursion(nums, 0, nums.size()-1);
    }

    int recursion(vector<int>& nums, int start, int end) {
        if (start == end) return nums[start];
        else {
            int mid = start + (end - start) / 2;
            int left = recursion(nums, start, mid);
            int right = recursion(nums, mid+1, end);
            int left_sum = nums[mid], right_sum = nums[mid+1];
            int left_max = nums[mid], right_max = nums[mid+1];
            for (int i = mid-1; i >= start; i--) {
                left_sum += nums[i];
                left_max = max(left_max, left_sum);
            }
            for (int i = mid+2; i <= end; i++) {
                right_sum += nums[i];
                right_max = max(right_max, right_sum);
            }
            int separate = max(left, right);
            //cout << start << " " << end << " " << left << " " << right << " " << left_max+right_max << endl;
            return max(separate, left_max+right_max);
        }
    }
};