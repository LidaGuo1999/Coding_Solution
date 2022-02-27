class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        # 利用回溯+深度搜索即可
        m, n = len(board), len(board[0])
        visited = [[0 for col in range(n)] for row in range(m)]
        rtn = False
        for i in range(m):
            for j in range(n):
                if board[i][j] == word[0]: 
                    visited[i][j] = 1
                    rtn = rtn or self.dfs(board, word[1:], visited, i, j)
                    visited[i][j] = 0
        return rtn

    def dfs(self, board, word, visited, last_row, last_col):
        m, n = len(board), len(board[0])
        #print(word)
        rtn = False
        if word == '': return True
        if last_row > 0 and visited[last_row-1][last_col] == 0 and board[last_row-1][last_col] == word[0]:
            visited[last_row-1][last_col] = 1 
            rtn = rtn or self.dfs(board, word[1:], visited, last_row-1, last_col)
            visited[last_row-1][last_col] = 0
        if last_row < m-1 and visited[last_row+1][last_col] == 0 and board[last_row+1][last_col] == word[0]:
            visited[last_row+1][last_col] = 1 
            rtn = rtn or self.dfs(board, word[1:], visited, last_row+1, last_col)
            visited[last_row+1][last_col] = 0
        if last_col > 0 and visited[last_row][last_col-1] == 0 and board[last_row][last_col-1] == word[0]:
            visited[last_row][last_col-1] = 1 
            rtn = rtn or self.dfs(board, word[1:], visited, last_row, last_col-1)
            visited[last_row][last_col-1] = 0
        if last_col < n-1 and visited[last_row][last_col+1] == 0 and board[last_row][last_col+1] == word[0]:
            visited[last_row][last_col+1] = 1 
            rtn = rtn or self.dfs(board, word[1:], visited, last_row, last_col+1)
            visited[last_row][last_col+1] = 0
        
        return rtn
        