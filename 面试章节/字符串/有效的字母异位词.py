# 这道题的思想十分的简单，就是构建一个字典，然后判断一下两个字符串中的字符种类和数量是不是相同即可
# 64ms, 39.60%; 13.7MB, 21.98%
class Solution1:
    def isAnagram(self, s: str, t: str) -> bool:
        m = {}
        for i in s:
            m.setdefault(i, 0)
            m[i] += 1
        for i in t:
            if i not in m:
                return False
            m[i] -= 1
        for i in m:
            if m[i] != 0:
                return False
        return True

# 第二种方法就是利用collections容器来处理，算是取巧吧
# 44ms, 88.69%; 13.7MB, 22.08%
class Solution2:
    def isAnagram(self, s: str, t: str) -> bool:
        return collections.Counter(s) == collections.Counter(t)