from copy import deepcopy
class SortAlgorithm():
    # 默认升序排列
    def __init__(self):
        pass
    
    # 冒泡排序，是稳定排序
    def bubbleSort(self, nums):
        ans = deepcopy(nums)
        for i in range(0, len(ans)-1):
            for j in range(len(ans)-1, i, -1):
                if ans[j] < ans[j-1]:
                    ans[j], ans[j-1] = ans[j-1], ans[j]
        return ans

    # 选择排序，不是稳定排序
    def selectSort(self, nums):
        ans = deepcopy(nums)
        for i in range(0, len(ans)-1):
            minIndex = i
            for j in range(i+1, len(ans)):
                if ans[j] < ans[minIndex]:
                    minIndex = j
            ans[i], ans[minIndex] = ans[minIndex], ans[i]
        return ans

    # 插入排序，是稳定排序
    def insertSort(self, nums):
        ans = deepcopy(nums)
        for i in range(0, len(ans)-1):
            for j in range(i+1, 0, -1):
                if ans[j] < ans[j-1]:
                    ans[j], ans[j-1] = ans[j-1], ans[j]
        return ans

    # 快速排序，不是稳定排序
    def quickSort(self, nums):
        ans = deepcopy(nums)

        def quickSortRecursiveUnit(nums, left, right):
            if left >= right:
                return 
            key, i, j = nums[left], left, right
            while i < j:
                while i < j and nums[j] > key:
                    j -= 1
                if i < j:
                    nums[i] = nums[j]
                    i += 1
                
                while i < j and nums[i] <= key:
                    i += 1
                if i < j:
                    nums[j] = nums[i]
                    j -= 1
            nums[i] = key
            quickSortRecursiveUnit(nums, left, i-1)
            quickSortRecursiveUnit(nums, i+1, right)

        quickSortRecursiveUnit(ans, 0, len(ans)-1)
        return ans

    # 归并排序，是稳定排序
    def mergeSort(self, nums):
        ans = deepcopy(nums)

        def mergeSortRecursiveUnit(nums, left, right):
            if left >= right:
                return
            mid = (left+right) // 2
            mergeSortRecursiveUnit(nums, left, mid)
            mergeSortRecursiveUnit(nums, mid+1, right)

            i, j, tmpNums = left, mid+1, list()
            while i <= mid and j <= right:
                if nums[i] < nums[j]:
                    tmpNums.append(nums[i])
                    i += 1
                else:
                    tmpNums.append(nums[j])
                    j += 1
            while i <= mid:
                tmpNums.append(nums[i])
                i += 1
            while j <= right:
                tmpNums.append(nums[j])
                j += 1
            for offset, num in enumerate(tmpNums):
                ans[left+offset] = num
        
        mergeSortRecursiveUnit(ans, 0, len(ans)-1)
        return ans



if __name__ == '__main__':
    unsorted = [8, 5, -3, 90, 22, 1, 0]
    s = SortAlgorithm()
    print(s.bubbleSort(unsorted))
    print(s.selectSort(unsorted))
    print(s.insertSort(unsorted))
    print(s.quickSort(unsorted))
    print(s.mergeSort(unsorted))