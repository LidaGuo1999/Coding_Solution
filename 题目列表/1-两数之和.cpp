/*
给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。

你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。

思路梳理：
1、总体遍历一遍，利用哈希表appear将已经出现的数字存入，数字为key，下标为索引；
2、同时，对每一个元素x进行一次判断，看target-x是否在哈希表中，若在，证明二者和为target，直接返回二者的索引即可；

评测结果：
16ms, 69.73%; 8.1MB, 100%;
 */

#include <map>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> appear;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            if (appear.find(target-nums[i]) != appear.end()) {
                ans.push_back(appear[target-nums[i]]);
                ans.push_back(i);
                break;
            }
            appear[nums[i]] = i;
        }

        return ans;
    }
};