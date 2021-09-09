from AutoTest import AutoTest

'''
给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素。
'''

class Solution:
    '''
    这道题主要就是弄清楚是按照顺时针顺序进行遍历的即可，注意边界条件的判定。
    36ms, 47.35%; 14.9MB, 57.51%;
    '''
    def spiralOrder(self, matrix):
        curDirection = 1
        i, j, l, w = 0, 0, len(matrix), len(matrix[0])
        cnt, rtn = 0, []
        while cnt < l*w:
            rtn.append(matrix[i][j])
            matrix[i][j] = -200
            if curDirection == 1:
                if j+1 >= w or matrix[i][j+1] == -200:
                    curDirection = 2
                    i += 1
                else: j += 1
            elif curDirection == 2:
                if i+1 >= l or matrix[i+1][j] == -200:
                    curDirection = 3
                    j -= 1
                else: i += 1
            elif curDirection == 3:
                if j-1 < 0 or matrix[i][j-1] == -200:
                    curDirection = 4
                    i -= 1
                else: j -= 1
            elif curDirection == 4:
                if i-1 < 0 or matrix[i-1][j] == -200:
                    curDirection = 1
                    j += 1
                else: i -= 1
            cnt += 1

        return rtn

if __name__ == '__main__':
    funcName = 'spiralOrder'
    paramNum = 1
    cases = [
        {'param1': [[1,2,3],[4,5,6],[7,8,9]]},
        {'param1': [[1,2,3,4],[5,6,7,8],[9,10,11,12]]}
    ]
    answers = [
        {'rtn': [1,2,3,6,9,8,7,4,5]},
        {'rtn': [1,2,3,4,8,12,11,10,9,5,6,7]}
    ]
    keyNames = [['param'+str(i+1) for i in range(paramNum)], 'rtn']

    s1 = Solution()
    autotest = AutoTest(s1, funcName, paramNum)
    autotest.test({'cases': cases, 'answers': answers}, keyNames)
