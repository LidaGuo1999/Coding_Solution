from typing import List
# 第一种方法比较暴力，从头至尾遍历，一旦碰到0，就将此处的0和后面碰到的第一个非零数字进行交换，直到结尾即可。
# 272ms, 7.98%; 14.1MB, 15.43%
class Solution1:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        for i in range(len(nums)):
            if nums[i] == 0:
                for j in range(i+1, len(nums)):
                    if nums[j] != 0:
                        nums[i] = nums[j]
                        nums[j] = 0
                        break

# 第二种方法只需要遍历一次数组，利用pos记录下当前应该填充的数组位置，pos从0开始，遍历过程中每当碰到一个非零数字时，就移到nums[pos]位置上
# 同时我们还需要统计总共出现了多少个0，在遍历完整个数组后，将末尾的count_zero个元素更新为0即可。
# 48ms, 86.19%; 14.1MB, 15.16%
class Solution2:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        count_zero = 0
        pos = 0
        for i in range(len(nums)):
            if nums[i] != 0:
                nums[pos] = nums[i]
                pos += 1
            else:
                count_zero += 1
        for i in range(len(nums)-count_zero, len(nums)):
            nums[i] = 0