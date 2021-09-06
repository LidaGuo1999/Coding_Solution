from AutoTest import AutoTest
from copy import deepcopy

'''
给定一个不含重复数字的数组nums，返回其所有可能的全排列。你可以按任意顺序返回答案。
'''

class Solution1:
    '''
    因为数组长度非常小，所以采用简单的递归就可以解决。visited数组用来记录哪些元素已经被使用过了。
    36ms, 63.44%; 15.2MB, 25.73%;
    '''
    def permute(self, nums):
        if len(nums) == 1:
            return [nums]
        def permuteUnit(nums, visited, ans, cur):
            #print(nums, visited, ans, cur)
            unused = []
            for i, v in enumerate(visited):
                if not v: unused.append(i)
            if len(unused) == 2:
                ans.append(cur+[nums[unused[0]]]+[nums[unused[1]]])
                ans.append(cur+[nums[unused[1]]]+[nums[unused[0]]])
            elif len(unused) > 2:
                for i in unused:
                    visited[i] = True
                    permuteUnit(nums, visited, ans, cur+[nums[i]])
                    visited[i] = False
            else:
                print('No Way!')

            return 

        ans = []
        visited = [False for i in range(len(nums))]
        cur = []
        permuteUnit(nums, visited, ans, cur)

        return ans

class Solution2:
    '''
    这是一种非递归全排列算法。对于一个递增的原始数字，我们不断寻找下一个全排列数。从后往前找到第一对非递增数，靠前的是替换点。将替换点数字与后面大于它的最小数交换，再将替换点后的数字翻转，即可得到。
    40ms, 41.78%; 15.1MB, 69.51%;
    '''
    def permute(self, nums):
        if len(nums) == 1:
            return [nums]
        def nextNum(li):
            li = deepcopy(li)
            change = -1
            for i in range(len(li)-1, 0, -1):
                if li[i-1] < li[i]:
                    change = i-1
                    break
            if change == -1: return []
            changeIndex = change+1
            for i in range(change, len(li)):
                if li[i] > li[change] and li[i] < li[changeIndex]:
                    changeIndex = i
            li[change], li[changeIndex] = li[changeIndex], li[change]
            tmp = li[change+1:]
            tmp.reverse()
            li = li[0:change+1]+tmp
            return li

        nums.sort()
        rtn, cur = [], nums
        while len(cur) > 0:
            rtn.append(cur)
            cur = nextNum(cur)
        
        return rtn



if __name__ == '__main__':
    funcName = 'permute'
    paramNum = 1
    cases = [
        {'param1': [1,2,3]},
        {'param1': [0,1]},
        {'param1': [1]}
    ]
    answers = [
        {'rtn': [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]},
        {'rtn': [[0,1],[1,0]]},
        {'rtn': [[1]]}
    ]
    keyNames = [['param'+str(i+1) for i in range(paramNum)], 'rtn']

    s1 = Solution1()
    autotest = AutoTest(s1, funcName, paramNum)
    #autotest.test({'cases': cases, 'answers': answers}, keyNames)

    s2 = Solution2()
    autotest2 = AutoTest(s2, funcName, paramNum)
    autotest2.test({'cases': cases, 'answers': answers}, keyNames)
    print(s2.permute([1,2,3]))