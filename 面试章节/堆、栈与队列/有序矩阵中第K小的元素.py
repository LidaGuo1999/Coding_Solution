# 使用了二分查找的思想。我们知道最小值在左上角，最大值在右下角，计算最小值和最大值中间的平均值mid，再从矩阵中寻找小于等于mid的元素个数，
# 如果元素个数小于k，代表我们要找的数在前半部分，对前半部分进行二分查找即可。同理，对后半部分进行二分查找。因为这个矩阵的特殊性，我们从左下角开始是最快的
# 208ms, 78.80%; 19.7%, 0%
class Solution:
    def kthSmallest(self, matrix: List[List[int]], k: int) -> int:
        n = len(matrix)
        left = matrix[0][0]
        right = matrix[n-1][n-1]
        while left < right:   
            mid = left + (right - left) // 2
            cnt = 0
            i = n-1
            j = 0
            while i >= 0 and j < n:
                if matrix[i][j] <= mid:
                    cnt += i+1
                    j += 1
                else:
                    i -= 1
            if cnt < k:
                left = mid + 1
            elif cnt >= k:
                right = mid
            
        return left
                    