from typing import List

#104ms, faster than 27.55%; 13MB, less than 100%
class Solution1:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        i = 0
        j = 0
        flag = 1 if (len(nums1)+len(nums2))%2 == 0 else 0
        mid = (len(nums1)+len(nums2))//2
        count = 0
        temp1 = 0
        temp2 = 0
        while count < len(nums1)+len(nums2):
            temp2 = temp1
            if i < len(nums1) and j < len(nums2):
                if nums1[i] <= nums2[j]:
                    temp1 = nums1[i]
                    i = i+1
                else:
                    temp1 = nums2[j]
                    j = j+1
            elif i < len(nums1):
                temp1 = nums1[i]
                i = i+1
            else:
                temp1 = nums2[j]
                j = j+1
            count = count+1
            if count > mid:
                break
        return (temp1+temp2)/2 if flag == 1 else float(temp1)
        

if __name__ == "__main__":
    nums1 = [1, 3]
    nums2 = [2]
    solution = Solution1()
    print(solution.findMedianSortedArrays(nums1, nums2))