class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        # 常规动态规划
        m, n = len(grid), len(grid[0])
        dp = [[0 for i in range(n)] for j in range(m)]

        # Initialize the last row
        dp[m-1][n-1] = grid[m-1][n-1]
        for col in range(n-2, -1, -1):
            dp[m-1][col] = grid[m-1][col]+dp[m-1][col+1]

        # Begin DP
        for row in range(m-2, -1, -1):
            for col in range(n-1, -1, -1):
                right, down = 1000, 1000
                if row < m-1: down = grid[row][col]+dp[row+1][col]
                if col < n-1: right = grid[row][col]+dp[row][col+1]
                dp[row][col] = min(right, down)
        
        return dp[0][0]