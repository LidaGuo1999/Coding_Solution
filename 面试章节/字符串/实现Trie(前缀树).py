# 第一感觉就是建造一棵树，插入，查找等等都采用调用递归树的方法
# 312ms, 20.99%; 30.2MB, 19.86%
class Trie1:

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

class Trie2:

    def __init__(self):
        """
        Initialize your data structure here.
        """


    def insert(self, word: str) -> None:
        """
        Inserts a word into the trie.
        """


    def search(self, word: str) -> bool:
        """
        Returns if the word is in the trie.
        """


    def startsWith(self, prefix: str) -> bool:
        """
        Returns if there is any word in the trie that starts with the given prefix.
        """
# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)