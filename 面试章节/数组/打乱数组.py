from typing import List
# 严格来说这不算是一道算法题。我们首先默认伪随机数算法是足够随机的，然后再使用洗牌算法来进行随机化处理。
# 洗牌算法是指，从数组开头开始，在其右边的数字中随机取一个数字（包括其自己），让二者交换，然后不断向右推进。
# 这样的算法能够保证每种情况出现的次数是相同的。
# 344ms, 61.62%; 19.1MB, 0%
class Solution:

    def __init__(self, nums: List[int]):
        self.original = nums.copy()
        self.array = nums
        

    def reset(self) -> List[int]:
        """
        Resets the array to its original configuration and return it.
        """
        return self.original
        

    def shuffle(self) -> List[int]:
        """
        Returns a random shuffling of the array.
        """
        current = self.original.copy()
        answer = []
        for i in range(len(self.original)):
            pos = random.randrange(len(current))
            answer.append(current[pos])
            current.pop(pos)
        return answer
        


# Your Solution object will be instantiated and called as such:
# obj = Solution(nums)
# param_1 = obj.reset()
# param_2 = obj.shuffle()