/*
给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。

思路梳理：
1、这是一道比较经典的区间动态规划算法题；
2、可以发现，如果我们想知道[i,j]是不是回文串，我们只需要提前知道[i+1,j-1]是不是回文串即可，所以我们按照子串长度由小到大进行动态规划即可。

评测结果：
288ms, 30.87%; 184.7MB, 26.19%;
 */

class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0, len = 0;
        vector<vector<int> > matrix(s.length(), vector<int>(s.length(), 0));
        if (s.length() == 0 || s.length() == 1) return s;

        for (int i = 0; i < s.length(); i++) {
            matrix[0][i] = 1;
        }
        for (int i = 1; i < s.length(); i++) {
            for (int j = 0; j < s.length()-i; j++) {
                if (s[j] == s[i+j]) {
                    int flag = 0;
                    if (i == 1) {
                        if (i > len) {
                            start = j;
                            len = i;
                        }
                        
                        flag = 1;
                    } else if (i > 1) {
                        if (matrix[i-2][j+1] == 1) {
                            if (i > len) {
                                start = j;
                                len = i;
                            }
                            
                            flag = 1;
                        }
                    }
                    if (flag == 1) matrix[i][j] = 1;
                }
            }
        }

        return s.substr(start, len+1);
    }
};