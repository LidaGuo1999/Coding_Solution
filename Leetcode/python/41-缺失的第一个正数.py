from AutoTest import AutoTest

'''
给你一个未排序的整数数组 nums ，请你找出其中没有出现的最小的正整数。

请你实现时间复杂度为 O(n) 并且只使用常数级别额外空间的解决方案。
'''

class Solution:
    '''
    这道题关键有两点。第一，最小正整数一定在[1, N+1]这个区间内；第二，可以利用原数组进行原地哈希，将数字n放到下标为n-1的地方。最后再遍历一次数组就能得到答案。原地哈希经典例题。
    196ms, 46.58%; 45.8MB, 63.28%;
    '''
    def firstMissingPositive(self, nums):
        for i in range(len(nums)):
            while 1 <= nums[i] <= len(nums) and nums[i] != nums[nums[i]-1]:
                self.__swap(nums, i, nums[i]-1)
        
        for i in range(len(nums)):
            if nums[i] != i+1:
                return i+1
        
        return len(nums)+1
        
    
    def __swap(self, nums, index1, index2):
        nums[index1], nums[index2] = nums[index2], nums[index1]

if __name__ == '__main__':
    funcName = 'firstMissingPositive'
    paramNum = 1
    cases = [
        {'nums': [1,2,0]},
        {'nums': [3,4,-1,1]},
        {'nums': [7,8,9,11,12]},
        {'nums': [1,2,3,4,5]},
        {'nums': [6,5,4,3,2,1]}
    ]
    answers = [
        {'rtn': 3},
        {'rtn': 2},
        {'rtn': 1},
        {'rtn': 6},
        {'rtn': 7}
    ]
    keyNames = [['nums'], 'rtn']

    s1 = Solution()
    autotest = AutoTest(s1, funcName, paramNum)
    autotest.test({'cases': cases, 'answers': answers}, keyNames)