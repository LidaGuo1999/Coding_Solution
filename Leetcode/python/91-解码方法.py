class Solution:
    def numDecodings(self, s: str) -> int:
        # 利用动态规划，dp[i]是前i个字符能够解码的方式种类。需要注意的是数字不能有前导零或者超过26。
        if s[0] == '0': return 0

        dp = [0 for i in range(len(s)+1)]
        dp[0] = 1
        for i in range(1, len(s)+1):
        
            if i == 1:
                dp[i] = 1 if s[i-1] != '0' else 0

            else:
                two_num = int(s[i-2:i])
                if two_num == 0: return 0
                elif two_num > 26:
                    if s[i-1] == '0': return 0
                    else: dp[i] = dp[i-1]
                else:
                    if s[i-1] == '0': dp[i] = dp[i-2]
                    else: 
                        if s[i-2] == '0': dp[i] = dp[i-1]
                        else: dp[i] = dp[i-1]+dp[i-2]
            print(i, dp[i])
        return dp[len(s)]