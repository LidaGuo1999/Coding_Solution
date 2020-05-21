'''
给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
'''

if __name__ == '__main__' :
    max_length = 0
    s = input().strip()
    dp = [0]*len(s)
    dp[0] = 1
    if len(s) <= 1:
        print(len(s))
    else:
        for i in range(1, len(s)):
            if s[i] not in s[i-dp[i-1]: i]:
                dp[i] = dp[i-1]+1
                max_length = max(max_length, dp[i])
            else:
                for j in range(i-1, i-dp[i-1]-1, -1):
                    if s[i] == s[j]:
                        dp[i] = i-j
                        max_length = max(max_length, dp[i])
                        break
        print(max_length)