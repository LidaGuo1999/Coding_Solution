from AutoTest import AutoTest
'''
请你判断一个 9x9 的数独是否有效。只需要 根据以下规则 ，验证已经填入的数字是否有效即可。

1、数字 1-9 在每一行只能出现一次。
2、数字 1-9 在每一列只能出现一次。
3、数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。（请参考示例图）
ps：数独部分空格内已填入了数字，空白格用 '.' 表示。

'''

class Solution1:
    '''
    三次迭代，分别判断行、列和九宫格是否符合标准。
    36ms, 95%; 15MB, 43%;
    '''
    def isValidSudoku(self, board):
        for i in range(9):
            appeared = set()
            for j in range(9):
                if board[i][j] != '.':
                    if board[i][j] in appeared:
                        return False
                    else: appeared.add(board[i][j])
                else: pass
            
            appeared = set()
            for j in range(9):
                if board[j][i] != '.':
                    if board[j][i] in appeared:
                        return False
                    else: appeared.add(board[j][i])
                else: pass
        
        for i in range(0, 9, 3):
            for j in range(0, 9, 3):
                appeared = set()
                for p in range(3):
                    for q in range(3):
                        if board[i+p][j+q] != '.':
                            if board[i+p][j+q] in appeared:
                                return False
                            else: appeared.add(board[i+p][j+q])
                        else: pass
        
        return True

class Solution2:
    '''
    只需要迭代一次，对每一个元素分别判断行、列和九宫格即可。
    44ms, 72.46%; 15MB, 58.30%;
    '''
    def isValidSudoku(self, board):
        appeared = []
        for i in range(3):
            tmp = []
            for j in range(9):
                tmp.append(set())
            appeared.append(tmp)

        for i in range(9):
            for j in range(9):
                if board[i][j] != '.':
                    if board[i][j] in appeared[0][i] or board[i][j] in appeared[1][j] or board[i][j] in appeared[2][3*(i//3)+j//3]:
                        return False
                    else: 
                        appeared[0][i].add(board[i][j])
                        appeared[1][j].add(board[i][j])
                        appeared[2][3*(i//3)+j//3].add(board[i][j])
                else: pass
        
        return True


if __name__ == "__main__":
    funcName = 'isValidSudoku'
    paramNum = 1
    cases = [
        {'board': [["5","3",".",".","7",".",".",".","."],
        ["6",".",".","1","9","5",".",".","."],
        [".","9","8",".",".",".",".","6","."],
        ["8",".",".",".","6",".",".",".","3"],
        ["4",".",".","8",".","3",".",".","1"],
        ["7",".",".",".","2",".",".",".","6"],
        [".","6",".",".",".",".","2","8","."],
        [".",".",".","4","1","9","8",".","5"],
        [".",".",".",".","8",".",".","7","9"]]},

        {'board': [["8","3",".",".","7",".",".",".","."],
        ["6",".",".","1","9","5",".",".","."],
        [".","9","8",".",".",".",".","6","."],
        ["8",".",".",".","6",".",".",".","3"],
        ["4",".",".","8",".","3",".",".","1"],
        ["7",".",".",".","2",".",".",".","6"],
        [".","6",".",".",".",".","2","8","."],
        [".",".",".","4","1","9",".",".","5"],
        [".",".",".",".","8",".",".","7","9"]]},

        {'board': [[".",".","4",".",".",".","6","3","."],
        [".",".",".",".",".",".",".",".","."],
        ["5",".",".",".",".",".",".","9","."],
        [".",".",".","5","6",".",".",".","."],
        ["4",".","3",".",".",".",".",".","1"],
        [".",".",".","7",".",".",".",".","."],
        [".",".",".","5",".",".",".",".","."],
        [".",".",".",".",".",".",".",".","."],
        [".",".",".",".",".",".",".",".","."]]}
    ]
    answers = [
        {'valid': False},
        {'valid': False},
        {'valid': False}
    ]
    keyNames = [['board'], 'valid']

    s1 = Solution1()
    autotest1 = AutoTest(s1, funcName, paramNum)
    autotest1.test({'cases': cases, 'answers': answers}, keyNames)

    s2 = Solution2()
    autotest2 = AutoTest(s2, funcName, paramNum)
    autotest2.test({'cases': cases, 'answers': answers}, keyNames)