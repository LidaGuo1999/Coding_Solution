from typing import List

class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        mode = None
        count = 0
        for n in nums:
            if not count:
                mode = n
                count += 1
            else:
                count += 1 if n == mode else -1
        return mode

if __name__ == "__main__":
    solution = Solution()
    nums = [2,2,1,1,1,2,2]
    print(solution.majorityElement(nums))

# 此处使用了一个新技巧，称为“摩尔投票法”，由于我们要找的是出现次数大于n/2的元素，那么我们遵从以下步骤：
# 1、选取剩余数组中第一个当作我们要找的数，同时让计数器置为1
# 2、向后读取数字，若出现的是我们设定的数，那么计数器加1，否则计数器减1
# 3、判断计数器的值，如果大于0，则重复步骤2；如果等于0，则跳转到步骤1
# 4、以此类推直到遍历完整个数组，此时我们取出的数就是我们要找的数；
# 其主要原理是，既然该元素在整个列表中出现过半，那么当计数器是0时，代表前面的该数和非该数个数刚好抵消，那么在剩余的子数组中，该元素仍然出现过半。