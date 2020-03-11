from typing import List
# 首先将两个数组从小到大排序，然后设置两个指针i和j，让他们分别从两个数组的头部开始遍历，当两个指针所指的数相等时，加入最终的结果数组
# 如果不想等，则所指的数更小的那个指针向前移动一步。该方法的主要精髓是利用了数组本身排好序的特点。
# 52ms, 80.33%; 13.7MB, 8.59%
class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        nums1.sort()
        nums2.sort()
        result = []
        i = 0
        j = 0
        while i < len(nums1) and j < len(nums2):
            if nums1[i] == nums2[j]:
                result.append(nums1[i])
                i += 1
                j += 1
            elif nums1[i] < nums2[j]:
                i += 1
            else:
                j += 1
        return result