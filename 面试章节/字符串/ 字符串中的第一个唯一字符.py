# 构建一个字典，存放每个字符出现的次数即可，没什么技巧。
# 228ms, 15.14%; 13.6MB, 19.74%
class Solution:
    def firstUniqChar(self, s: str) -> int:
        count = {}
        first_pos = {}
        for i in range(len(s)):
            count.setdefault(s[i], 0)
            count[s[i]] += 1
            first_pos.setdefault(s[i], i)
        for i in count:
            if count[i] == 1:
                return first_pos[i]
        return -1   