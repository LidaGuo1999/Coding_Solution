from typing import List

# 方法1就是利用了我们归并排序中“合并”步骤的技巧，遍历一次即可。缺点是需要使用多余的空间来存储。

class Solution1:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        temp = []
        i = 0
        j = 0
        while i < m or j < n:
            if i >= m:
                temp.append(nums2[j])
                j += 1
            elif j >= n:
                temp.append(nums1[i])
                i += 1
            elif nums1[i] <= nums2[j]:
                temp.append(nums1[i])
                i += 1
            else:
                temp.append(nums2[j])
                j += 1
        for i in range(m+n):
            nums1[i] = temp[i]

# 方法2跟方法1的思想是基本一样的，只不过其利用了nums1数组后面的多余部分，从后往前进行遍历，这样就节省了一个temp数组的空间，同时也加快了速度
# 40ms, 69.91%; 13.6MB, 31.23%

class Solution2:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        end = m+n-1
        i = m-1
        j = n-1
        while i >= 0 or j >= 0:
            if i < 0:
                nums1[end] = nums2[j]
                j -= 1
            elif j < 0:
                nums1[end] = nums1[i]
                i -= 1
            elif nums1[i] <= nums2[j]:
                nums1[end] = nums2[j]
                j -= 1
            else:
                nums1[end] = nums1[i]
                i -= 1
            end -= 1

if __name__ == "__main__":
    solution = Solution2()
    nums1 = [1,2,3,0,0,0]
    nums2 = [2,5,6]
    solution.merge(nums1, 3, nums2, 3)
    print(nums1)