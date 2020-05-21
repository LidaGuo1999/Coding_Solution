# 本题的主要思想是使用双向队列。时刻保证双向队列的头是当前队列中的最大值，并且该值还属于滑动窗口。
# 248ms, 37.32%; 17MB, 100%
from collections import deque
class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        if k == 1:
            return nums
        d = deque()
        ans = []
        d.append(0)
        for i in range(1, k):
            while nums[i] > nums[d[-1]]:
                if len(d) == 1:
                    d.pop()
                    break
                d.pop()
            d.append(i)
        ans.append(nums[d[0]])
        for i in range(k, len(nums)):
            while len(d) > 0 and d[0] <= i-k:
                d.popleft()
            while len(d) > 0 and nums[i] > nums[d[-1]]:
                flag = 1
                if len(d) == 1:
                    d.pop()
                    break
                d.pop()
            d.append(i)
            ans.append(nums[d[0]])
        return ans
            
                
            