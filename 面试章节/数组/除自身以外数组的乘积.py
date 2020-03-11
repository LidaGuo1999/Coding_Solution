from typing import List
# 题目要求不能够使用除法，那么我们可以使用左边的乘积与右边的乘积相乘的方法来进行计算。第一次遍历将左边的乘积全部计算出来，
# 第二次遍历将右边的乘积全部计算出来。最后计算每个位置的结果即可。下方的方法是改进版，不需要储存右边乘积的数组。
# 72ms, 85.57%; 18.7MB, 100%
class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        L = [0]*n
        L[0] = 1
        result = [0]*n
        for i in range(1, n):
            L[i] = L[i-1]*nums[i-1]
        R = 1
        for i in reversed(range(n)):
            result[i] = L[i]*R
            R *= nums[i]
        return result
            