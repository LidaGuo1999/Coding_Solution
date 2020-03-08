from typing import List
# 第一种方法就是循环交换法，先将第0个元素向后移动k步，然后再移动刚刚被替换的那个元素，以此类推。
# 但是可能出现的情况就是走了若干个循环后又到了开始的那个元素，但是其实很多元素还没有处理，所以当我们发现这种情况时，
# 就要将开始位置加1，再次开始循环。
# 44ms, 92.38%; 13.9MB, 95.60%
class Solution1:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        k = k%n
        pos = 0
        start = 0
        count = 0
        if k == 0:
            return
        value = nums[pos]
        while count < n:
            temp = nums[(pos+k)%n]
            nums[(pos+k)%n] = value
            pos = (pos+k)%n
            value = temp
            count += 1
            if pos == start:
                start += 1
                pos = start
                value = nums[pos]
        

# 第二种方法是反转法，经过规律可以发现，其实整个过程就是先将整个数组进行反转，然后再反转一次前n-k个元素，反转一次后k个元素即可
# 52ms, 88.75%; 13.8MB, 98.51%
class Solution2:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        k = k%n
        if n == 0:
            return
        i = 0
        j = n-1
        while i < j:
            temp = nums[i]
            nums[i] = nums[j]
            nums[j] = temp
            i += 1
            j -= 1
        i = 0
        j = k-1
        while i < j:
            temp = nums[i]
            nums[i] = nums[j]
            nums[j] = temp
            i += 1
            j -= 1
        i = k
        j = n-1
        while i < j:
            temp = nums[i]
            nums[i] = nums[j]
            nums[j] = temp
            i += 1
            j -= 1