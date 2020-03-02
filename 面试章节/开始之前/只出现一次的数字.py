class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        once = 0
        for i in range(len(nums)):
            once = once^nums[i]
        return once


# 根据题目要求，只有一个元素出现了奇数次，其他的元素都出现偶数次，由此想到使用位运算中的异或操作，这样出现偶数次的元素都会被相互抵消掉