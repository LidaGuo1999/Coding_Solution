from typing import List
# 我们希望遍历一次数组就可以得到结论，我们只需要存储当前最小的和第二小的数，并且保证第二小的数在最小数的后面，那么当新数字比第二小的数大时，
# 就说明存在这样的递增子序列。
# 72ms, 40.51%; 14.3MB, 10.55%
class Solution:
    def increasingTriplet(self, nums: List[int]) -> bool:
        min1 = None
        min2 = None
        pos1 = 0
        pos2 = 0
        substitute = None
        if len(nums) < 3:
            return False
        if nums[0] < nums[1]:
            min1 = nums[0]
            min2 = nums[1]
            pos2 = 1
        else:
            min1 = nums[1]
            pos1 = 1
            min2 = 100000000000
        for i in range(2, len(nums)):
            if nums[i] > min2:
                return True
            elif nums[i] > min1:
                min2 = nums[i]
                pos2 = i
            else:
                if substitute == None:
                    substitute = nums[i]
                elif nums[i] <= substitute:
                    substitute = nums[i]
                else:
                    min1 = substitute
                    min2 = nums[i]