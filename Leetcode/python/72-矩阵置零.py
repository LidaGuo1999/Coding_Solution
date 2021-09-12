from AutoTest import AutoTest

'''
给定一个 m x n 的矩阵，如果一个元素为 0 ，则将其所在行和列的所有元素都设为 0 。请使用 原地 算法。
'''

class Solution:
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
