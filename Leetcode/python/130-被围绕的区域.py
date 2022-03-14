class Solution:
    def solve(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        # 从边上的O开始，利用DFS或者BFS就可以找到所有与边界都相邻的O，将他们标记为待修改即可
        m, n = len(board), len(board[0])
        visited = [[0 for col in range(n)] for row in range(m)]
        change = [[1 for col in range(n)] for row in range(m)]
        cur = [[0 for col in range(n)] for row in range(m)]
        
        for j in range(n):
            if board[0][j] == 'O' and visited[0][j] == 0: self.unchange(0, j, m, n, visited, change, board)
            if board[m-1][j] == 'O' and visited[m-1][j] == 0: self.unchange(m-1, j, m, n, visited, change, board)
        for i in range(m):
            if board[i][0] == 'O' and visited[i][0] == 0: self.unchange(i, 0, m, n, visited, change, board)
            if board[i][n-1] == 'O' and visited[i][n-1] == 0: self.unchange(i, n-1, m, n, visited, change, board)

        for i in range(m):
            for j in range(n):
                if board[i][j] == 'O' and change[i][j] == 1: board[i][j] = 'X'
        return

    def unchange(self, row, col, m, n, visited, change, board):
        visited[row][col] = 1
        change[row][col] = 0
        if row-1 >= 0 and board[row-1][col] == 'O' and visited[row-1][col] == 0: self.unchange(row-1, col, m, n, visited, change, board)
        if row+1 < m and board[row+1][col] == 'O' and visited[row+1][col] == 0: self.unchange(row+1, col, m, n, visited, change, board)
        if col-1 >= 0 and board[row][col-1] == 'O' and visited[row][col-1] == 0: self.unchange(row, col-1, m, n, visited, change, board)
        if col+1 < n and board[row][col+1] == 'O' and visited[row][col+1] == 0: self.unchange(row, col+1, m, n, visited, change, board)

        return 
