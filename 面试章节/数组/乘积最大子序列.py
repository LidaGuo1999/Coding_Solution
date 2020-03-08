from typing import List
# 第一种方法就是暴力双循环法，二次方的复杂度
# 结果当然不出意料的TLE了
class Solution1:
    def maxProduct(self, nums: List[int]) -> int:
        multiply_max = nums[0]
        for i in range(len(nums)):
            consecutive = 1
            for j in range(i, len(nums)):
                consecutive *= nums[j]
                multiply_max = max(multiply_max, consecutive)
        return multiply_max

# 第二种方法是使用动态规划，可是很难想到。因为乘法中会出现负负得正和正负得负的情况，所以我们实际上需要维护一个以第i个元素结尾的子数组的最大值和最小值，
# 利用动态规划的方法遍历一遍数组。
# 52ms, 89.45%; 13.7MB, 32.99%
class Solution2:
    def maxProduct(self, nums: List[int]) -> int:
        maxP = nums[0]
        minP = nums[0]
        result = nums[0]
        if len(nums) == 1:
            return nums[0]
        for i in range(1, len(nums)):
            t = maxP
            maxP = max(maxP*nums[i], nums[i], minP*nums[i])
            minP = min(t*nums[i], nums[i], minP*nums[i])
            result = max(result, maxP)
        return result