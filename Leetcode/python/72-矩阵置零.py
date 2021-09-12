from AutoTest import AutoTest

'''
给定一个 m x n 的矩阵，如果一个元素为 0 ，则将其所在行和列的所有元素都设为 0 。请使用 原地 算法。
'''

'''
1   2   3   4
5   0   7   8
0   10  11  12
13  14  15  0
'''


class Solution1:
    '''
    这种解法记录下需要置零的行和列，因此空间复杂度是O(m+n)，不算最好的算法，但是能用。
    32ms, 95.75%; 15.2MB, 49.65%;
    '''
    def setZeroes(self, matrix):
        """
        Do not return anything, modify matrix in-place instead.
        """
        record = [0 for i in range(len(matrix)+len(matrix[0]))]
        for i in range(len(matrix)):
            for j in range(len(matrix[i])):
                if matrix[i][j] == 0: record[i] = record[len(matrix)+j] = 0
        
        for i in range(len(matrix)):
            if record[i] == 0: 
                for j in range(len(matrix[0])):
                    matrix[i][j] = 0
        for i in range(len(matrix), len(record)):
            if record[i] == 0:
                for j in range(len(matrix)):
                    matrix[j][i-len(matrix)] = 0
        
        return 

class Solution2:
    def setZeroes(self, matrix):
        """
        Do not return anything, modify matrix in-place instead.
        """
        m, n = len(matrix), len(matrix[0])
        i, j = 0, 0
        while i <= m-i-1 and j <= n-j-1:
            flag = [0 for i in range(4)]
            for p in range(j, n-j):
                if matrix[i][p] == 0: 
                    flag[0] = 1
                    for ii in range(0, i): matrix[ii][p] = 0
                    for ii in range(m-i, m): matrix[ii][p] = 0
                if matrix[m-i-1][p] == 0: 
                    flag[2] = 0
                    for ii in range(0, i): matrix[ii][p] = 0
                    for ii in range(m-i, m): matrix[ii][p] = 0
            for q in range(i, m-i):
                if matrix[q][j] == 0: 
                    flag[3] = 0
                    for jj in range(0, j): matrix[q][jj] = 0
                    for jj in range(n-j, n): matrix[q][jj] = 0
                if matrix[q][n-j-1] == 0: 
                    flag[1] = 0
                    for jj in range(0, j): matrix[q][jj] = 0
                    for jj in range(n-j, n): matrix[q][jj] = 0
            
            if flag[0] == 1: 
                for q in range(n): matrix[i][q] = 0
            if flag[1] == 1:
                for p in range(m): matrix[p][n-j-1] = 0
            if flag[2] == 1: 
                for q in range(n): matrix[m-i-1][q] = 0
            if flag[3] == 1: 
                for p in range(m): matrix[p][j] = 0

            i, j = i+1, j+1
        
        '''if i < m-i-1:
            flagi = 0
            for p in range(i, m-i): 
                if matrix[p][j] == 0: 
                    flagi = 1
                    break
            if flagi == 1: 
                for p in range(0, m): matrix[p][j] = 0
            
        if i == m-i-1 and j < n-j-1:
            flagj = 0
            for q in range(j, n-j): 
                if matrix[i][q] == 0: 
                    flagj = 1
                    break
            if flagj == 1: 
                for q in range(0, n): matrix[i][q] = 0
            '''
        return 

            

