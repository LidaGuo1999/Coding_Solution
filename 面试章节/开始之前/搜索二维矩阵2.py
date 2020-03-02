class Solution1:
    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        if len(matrix) == 0:
            return False

        m = len(matrix[0])-1
        n = len(matrix)-1
        while m >= 1 and n >= 1:
            if matrix[n][m] >= target:
                for i in range(m+1):
                    if matrix[n][i] == target:
                        return True
                for j in range(n+1):
                    if matrix[j][m] == target:
                        return True
            
            m -= 1
            n-= 1

        if m == 0 and n > 0:
            for i in range(n+1):
                if matrix[i][0] == target:
                    return True
        elif m > 0 and n == 0:
            for i in range(m+1):
                if matrix[0][i] == target:
                    return True
        elif m == 0 and n == 0:
            if matrix[0][0] == target:
                return True
        
        return False

# 该方法主要是根据右下角的数是最大的这一特点，排除掉该数不可能出现的区域后再进行遍历

class Solution2:
    def searchMatrix(self, matrix, target):
        if len(matrix) == 0:
            return False

        m = len(matrix)-1
        n = len(matrix[0])-1
        i = m
        j = 0
        while i >= 0 and j <= n:
            if matrix[i][j] == target:
                return True
            elif matrix[i][j] > target:
                i -= 1
            else:
                j += 1
        
        return False
        
# 该方法其实是采用了贪心策略的思想，我们从矩阵的左下角开始出发，如果target比该数大，那么我们就向右寻找，反之则向上寻找。
# 选定角点的原则主要是在比较大小之后只有一个方向可走，比如选取右上也是一样的方法。

if __name__ == "__main__":
    solution = Solution2()
    matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]]
    target = 5
    print(solution.searchMatrix(matrix, target))
