from typing import List, Set
# 显然这道题需要使用回溯的方法，但是我们可以使用前缀树来简化回溯，使回溯提前停止。我们先将words中的所有单词都存入一棵前缀树中，
# 然后再通过dfs来遍历board中可能出现的单词，在这个过程中，我们用当前的字符串与前缀树比较，如果不在前缀树中，那么显然该路径不会构成有效单词，直接跳出。
class Trie:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.val = []
        self.children = []
        self.end = 0


    def insert(self, word: str) -> None:
        """
        Inserts a word into the trie.
        """
        if len(word) != 0:
            if word[0] not in self.val:
                self.val.append(word[0])
                node = Trie()
                self.children.append(node)
                if len(word) > 1:
                    self.children[-1].insert(word[1:])
                else:
                    self.children[-1].insert('')
            else:
                pos = self.val.index(word[0])
                if len(word) > 1:
                    self.children[pos].insert(word[1:])
                else:
                    self.children[pos].insert('')
        else:
            self.end = 1
        


    def search(self, word: str) -> bool:
        """
        Returns if the word is in the trie.
        """
        if len(word) == 0:
            return True if self.end == 1 else False
        if word[0] in self.val:
            if len(word) > 1:
                return self.children[self.val.index(word[0])].search(word[1:])
            else:
                return self.children[self.val.index(word[0])].search('')
        else:
            return False
                


    def startsWith(self, prefix: str) -> bool:
        """
        Returns if there is any word in the trie that starts with the given prefix.
        """
        if len(prefix) == 0:
            return True
        if prefix[0] in self.val:
            if len(prefix) > 1:
                return self.children[self.val.index(prefix[0])].startsWith(prefix[1:])
            else:
                return self.children[self.val.index(prefix[0])].startsWith('')
        else:
            return False

class Solution:
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        trie = Trie()
        for word in words:
            trie.insert(word)
        height = len(board)
        width = len(board[0]) if height > 0 else 0
        flag = [[0 for j in range(width)] for i in range(height)]
        result = set()
        for i in range(height):
            for j in range(width):
                self.clear(flag)
                self.dfs(i, j, board, flag, trie, '', result)
        return list(result)

    def clear(self, flag) -> None:
        for i in range(len(flag)):
            for j in range(len(flag[0])):
                flag[i][j] = 0

    def dfs(self, i: int, j: int, board: List[List[int]], flag: List[List[str]], trie, current: str, result) -> None:
        update = current+board[i][j]
        flag[i][j] = 1
        if not trie.startsWith(update):
            return 
        if trie.search(update):
            result.add(update)
        if j > 0 and flag[i][j-1] == 0:
            self.dfs(i, j-1, board, flag, trie, update, result)
        if j < len(board[0])-1 and flag[i][j+1] == 0:
            self.dfs(i, j+1, board, flag, trie, update, result)
        if i > 0 and flag[i-1][j] == 0:
            self.dfs(i-1, j, board, flag, trie, update, result)
        if i < len(board)-1 and flag[i+1][j] == 0:
            self.dfs(i+1, j, board, flag, trie, update, result)
        return 

if __name__ == "__main__":
    solution = Solution()
    board = [["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]]   
    words = ["oath","pea","eat","rain"]
    print(solution.findWords(board, words))