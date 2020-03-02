# 该题的思路很简单，就是先去除掉非数字或字母的字符，然后统一转成小写，再利用双指针进行回文串的判断即可
# 60ms, 48.63%; 13.6MB, 56.12%

class Solution:
    def isPalindrome(self, s: str) -> bool:
        news = ''
        for i in s:
            if i >= 'A' and i <= 'Z' or i >= 'a' and i <= 'z' or i >= '0' and i <= '9':
                news += i
        news = news.lower()
        i = 0
        j = len(news)-1
        while i < j:
            if news[i] != news[j]:
                return False
            i += 1
            j -= 1
        return True
        

if __name__ == "__main__":
    solution = Solution()
    s = 'race a car'
    print(solution.isPalindrome(s))