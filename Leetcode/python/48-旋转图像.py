from AutoTest import AutoTest
from copy import deepcopy
'''
给定一个 n × n 的二维矩阵 matrix 表示一个图像。请你将图像顺时针旋转 90 度。
你必须在 原地 旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要使用另一个矩阵来旋转图像。
'''

class Solution1:
    '''
    本题的关键主要是找到翻转后每个元素的位置对应关系，[i, j]对应[j, n-i-1]。但是该方法还是需要占用O(n2)的空间，因为需要记录哪些元素被遍历过。
    32ms, 74.91%; 15MB, 21.93%;
    '''
    def rotate(self, matrix):
        """
        Do not return anything, modify matrix in-place instead.
        """
        n = len(matrix)
        appear = [[0 for i in range(n)] for i in range(n)]
        for i in range(n):
            for j in range(n):
                if appear[i][j] == 0:
                    curi, curj, tmp = i, j, matrix[i][j]
                    while appear[curi][curj] == 0:
                        matrix[curj][n-curi-1], tmp = tmp, matrix[curj][n-curi-1]
                        appear[curi][curj] = 1
                        curi, curj = curj, n-curi-1
                else: 
                    pass
        
        return matrix

class Solution2:
    '''
    在原解法的基础上优化了内存性能。因为通过观察发现，每个元素在不断旋转4次后都会回到原位，所以不需要记录元素是否旋转过的appear数组。
    32ms, 75%; 14.9MB, 73%;
    '''
    def rotate(self, matrix):
        """
        Do not return anything, modify matrix in-place instead.
        """
        n = len(matrix)
        for i in range(n//2):
            for j in range(n//2 if n%2 == 0 else n//2+1):
                curi, curj, tmp = i, j, matrix[i][j]
                for k in range(4):
                    matrix[curj][n-curi-1], tmp = tmp, matrix[curj][n-curi-1]
                    curi, curj = curj, n-curi-1
        
        return matrix

if __name__ == '__main__':
    funcName = 'rotate'
    paramNum = 1
    cases = [
        {'param1': [[1,2,3],[4,5,6],[7,8,9]]},
        {'param1': [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]},
        {'param1': [[1]]},
        {'param1': [[1,2],[3,4]]}
    ]
    answers = [
        {'rtn': [[7,4,1],[8,5,2],[9,6,3]]},
        {'rtn': [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]},
        {'rtn': [[1]]},
        {'rtn': [[3,1],[4,2]]}
    ]
    keyNames = keyNames = [['param'+str(i+1) for i in range(paramNum)], 'rtn']

    s1 = Solution1()
    autotest1 = AutoTest(s1, funcName, paramNum)
    autotest1.test({'cases': deepcopy(cases), 'answers': answers}, keyNames)

    s2 = Solution2()
    autotest2 = AutoTest(s2, funcName, paramNum)
    autotest2.test({'cases': deepcopy(cases), 'answers': answers}, keyNames)
    print(s2.rotate([[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]))