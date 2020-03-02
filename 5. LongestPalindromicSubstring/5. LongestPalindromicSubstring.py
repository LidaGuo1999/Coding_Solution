# TLE
class Solution1:
    def longestPalindrome(self, s: str) -> str:
        start = 0  
        end = 0
        longest = 0
        for i, let  ter in enumerate(s):
            for j in range(i+1, len(s)):
                if letter == s[j] and self.isPalindrome(s[i:j+1]) and j-i > longest:
                    longest = j-i
                    start = i
                    end = j
        return s[start:end+1]


    def isPalindrome(self, s: str) -> str:
        i = 0
        j = len(s)-1
        flag = 1
        for t in range(len(s)//2):
            if s[i] != s[j]:
                flag = 0
                break
            i += 1
            j -= 1
        return flag

class Solution2:
    def longestPalindrome(self, s: str) -> str:
        length = 1
        d = list()
        d.append(1)
        



if __name__ == '__main__':
    solution = Solution1()
    s = 'babad'
    print(solution.longestPalindrome(s))
