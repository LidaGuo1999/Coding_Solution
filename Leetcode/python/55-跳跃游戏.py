from AutoTest import AutoTest

'''
给定一个非负整数数组 nums ，你最初位于数组的 第一个下标 。
数组中的每个元素代表你在该位置可以跳跃的最大长度。
判断你是否能够到达最后一个下标。
'''

class Solution:
    '''
    只需要遍历一次，记录下到目前为止能够到达的最大下标即可。
    108ms, 34.78%; 15.5MB, 14.66%;
    '''
    def canJump(self, nums):
        reach = [0 for i in range(len(nums))]
        for i in range(len(nums)):
            if i != 0:
                if reach[i-1] >= i: 
                    reach[i] = max(reach[i-1], nums[i]+i)
                    if reach[i] >= len(nums)-1: return True
                else: return False
            else: reach[i] = nums[i]
        
        return True

if __name__ == '__main__':
    funcName = 'canJump'
    paramNum = 1
    cases = [
        {'param1': [2,3,1,1,4]},
        {'param1': [3,2,1,0,4]},
        {'param1': [0]}
    ]
    answers = [
        {'rtn': True},
        {'rtn': False},
        {'rtn': True}
    ]
    keyNames = [['param'+str(i+1) for i in range(paramNum)], 'rtn']

    s1 = Solution()
    autotest = AutoTest(s1, funcName, paramNum)
    autotest.test({'cases': cases, 'answers': answers}, keyNames)