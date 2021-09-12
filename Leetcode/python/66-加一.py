from AutoTest import AutoTest  
  
'''
给定一个由 整数 组成的 非空 数组所表示的非负整数，在该数的基础上加一。
最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。
你可以假设除了整数 0 之外，这个整数不会以零开头。
'''

class Solution:
    def plusOne(self, digits):
        '''
        简单的模拟加法器算法。 
        28ms, 90.37%; 14.8MB, 86.60%;
        '''
        carry = 1
        for i in range(len(digits)-1, -1, -1):
            tmp = (digits[i]+carry)
            carry = tmp // 10
            digits[i] = tmp % 10

        return [1]+digits if carry > 0 else digits

if __name__ == '__main__':
    funcName = 'plusOne'
    paramNum = 1
    cases = [
        {'param1': [1,2,3]},
        {'param1': [4,3,2,1]},
        {'param1': [0]},
        {'param1': [9,9,9,9]}
    ]
    answers = [
        {'rtn': [1,2,4]},
        {'rtn': [4,3,2,2]},
        {'rtn': [1]},
        {'rtn': [1,0,0,0,0]}
    ]
    keyNames = [['param'+str(i+1) for i in range(paramNum)], 'rtn']

    s1 = Solution()
    autotest = AutoTest(s1, funcName, paramNum)
    autotest.test({'cases': cases, 'answers': answers}, keyNames)