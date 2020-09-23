/*
给你一个整数数组 nums ，请你找出数组中乘积最大的连续子数组（该子数组中至少包含一个数字），并返回该子数组所对应的乘积。

思路梳理：
1、想到类似最长连续子数组的经典算法题，所不同的是这里是乘法，而原题是加法；
2、但是同样可以使用分治的思想来解决，只不过需要注意我们要记录最小值和最大值，因为最小值和最大值有可能因为一个负号而直接翻转；
3、对于每一次combine，我们比较左半部分的最大值，右半部分的最大值，和跨中间的最大值，取三者的最大值return即可。

评测结果：
16ms, 12.22%; 11.5MB, 6.25%;
 */

#include <algorithm>
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        return recursion(nums, 0, nums.size()-1);
    }

    int recursion(vector<int>& nums, int start, int end) {
        if (end-start < 1) return nums[start];
        int middle = start+(end-start)/2;
        int left = recursion(nums, start, middle);
        int right = recursion(nums, middle+1, end);
        int left_min = nums[middle], left_max = nums[middle], cur_left = nums[middle];
        int right_min = nums[middle+1], right_max = nums[middle+1], cur_right = nums[middle+1];

        for (int i = middle-1; i >= start; i--) {
            cur_left *= nums[i];
            left_min = min(left_min, cur_left);
            left_max = max(left_max, cur_left);
        }

        for (int i = middle+2; i <= end; i++) {
            cur_right *= nums[i];
            right_min = min(right_min, cur_right);
            right_max = max(right_max, cur_right);
        }

        int combine = max(left_min*right_min, left_max*right_max);

        return max(max(left, right), combine);
    }
};