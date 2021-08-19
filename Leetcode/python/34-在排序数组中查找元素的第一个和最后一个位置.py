'''
问题描述：给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。
如果数组中不存在目标值 target，返回 [-1, -1]。
'''
from AutoTest import AutoTest
class Solution1:
    '''
    1、使用二分查找查找到任意一个与target相等的元素的索引，然后向前向后分别遍历寻找起止点；
    2、时间复杂度将会略高于O(logN)；
    44ms, 28.82%; 15.9MB, 5,09%;
    '''
    def searchRange(self, nums, target):
        if len(nums) == 0:
            return [-1, -1]

        def locate(nums, target, left, right):
            if left >= right:
                if nums[left] == target:
                    return left
                else:
                    return -1
            mid = (left+right)//2
            if nums[mid] == target:
                return mid
            else:
                return max(locate(nums, target, left, mid), locate(nums, target, mid+1, right))
            
            return -1

        oneOfTargets = locate(nums, target, 0, len(nums)-1)
        if oneOfTargets == -1:
            return [-1, -1]
        else:
            start, end = 0, 0
            for i in range(oneOfTargets, -1, -1):
                if nums[i] == target:
                    start = i
                else:
                    break
            for i in range(oneOfTargets, len(nums)):
                if nums[i] == target:
                    end = i
                else:
                    break
            return [start, end]

        return None

class Solution2:
    '''
    1、直接使用二分法找到大于（或等于）target的第一个数的索引，一步到位；
    2、时间复杂度即为二分查找的O(logN)；
    44ms, 28.82%; 15.7MB, 48.82%;
    '''
    def searchRange(self, nums, target): 
        
        def getClosestIndex(nums, target, isEqual):
            left, right = 0, len(nums)-1
            ans = -1
            while left <= right and left < len(nums) and right >= 0:
                #print(left, right)
                mid = (left+right)//2
                if nums[mid] > target or (isEqual and nums[mid] == target):
                    right = mid-1
                    ans = mid
                else:
                    left = mid+1
            return ans

        if len(nums) == 0:
            return [-1, -1]
        start = getClosestIndex(nums, target, True)
        end = getClosestIndex(nums, target, False)
        end = end-1 if end != -1 else len(nums)-1

        if (start >= 0 and start < len(nums)) and (end >= 0 and end < len(nums)) and (nums[start] == target) and (nums[end] == target):
            return [start, end]
        else:
            return [-1, -1]

        
if __name__ == '__main__':
    funcName = 'searchRange'
    paramNum = 2
    cases = [
        {'nums': [5,7,7,8,8,10], 'target': 8},
        {'nums': [5,7,7,8,8,10], 'target': 6},
        {'nums': [5,7,7,8,8,10], 'target': 5},
        {'nums': [5,7,7,8,8,10], 'target': 10},
        {'nums': [], 'target': 8},
        {'nums': [5], 'target': 5},
        {'nums': [5], 'target': 0}
    ]
    answers = [
        {'rtn': [3, 4]},
        {'rtn': [-1, -1]},
        {'rtn': [0, 0]},
        {'rtn': [5, 5]},
        {'rtn': [-1, -1]},
        {'rtn': [0, 0]},
        {'rtn': [-1, -1]},
    ]
    keyNames = [['nums', 'target'], 'rtn']

    s1 = Solution1()
    autotest1 = AutoTest(s1, funcName, paramNum)
    autotest1.test({'cases': cases, 'answers': answers}, keyNames)
    s2 = Solution1()
    autotest2 = AutoTest(s2, funcName, paramNum)
    autotest2.test({'cases': cases, 'answers': answers}, keyNames)

    
    
    


                
