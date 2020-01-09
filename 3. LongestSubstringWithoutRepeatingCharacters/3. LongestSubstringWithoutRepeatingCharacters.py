# 72ms, faster than 43.15%; 12.9MB, less than 100%
class Solution1:
    def lengthOfLongestSubstring(self, s: str) -> int:
        length = 0
        i = 0
        for j in range(len(s)):
            flag = 0
            new_i = i
            for k in range(i, j):
                if s[k] == s[j]:
                    flag = 1
                    new_i = k + 1
                    break
            if flag == 0:
                continue
            length = max(length, j-i)
            i = new_i
        length = max(length, len(s)-i)
        return length

# 60ms, faster than 66.81%; 12.9MB, less than 100%
class Solution2:
    def lengthOfLongestSubstring(self, s: str) -> int:
        length = 0
        re = {}
        i = 0
        for j in range(len(s)):
            if s[j] in re:
                temp_i = re[s[j]]
                for k in range(i, temp_i + 1):
                    del re[s[k]]
                length = max(length, j-i)
                i = temp_i + 1

            re[s[j]] = j
        length = max(length, len(s)-i)
        return length

# 48ms, faster than 92.78%; 12.8MB, less than 100%
class Solution3:
    def lengthOfLongestSubstring(self, s: str) -> int:
        length = 0
        re = {}
        i = 0
        for j, letter in enumerate(s):
            if letter in re and re[letter] >= i:
                length = max(length, j-i)
                i = re[letter] + 1
            re[letter] = j

        length = max(length, len(s)-i)
        return length
        
if __name__ == "__main__":
    test = 'aaabcabcbb'
    solution = Solution3()
    print(solution.lengthOfLongestSubstring(test))