/*
给你一个字符串 s ，请你返回满足以下条件的最长子字符串的长度：每个元音字母，即 'a'，'e'，'i'，'o'，'u' ，在子字符串中都恰好出现了偶数次。

思路梳理：
1、使用前缀和的思想，需要记录下前i个字符组成的字串中aeiou分别出现的次数；
2、进一步精简，我们只需要储存aeiou各种奇偶组合最早出现的位置，当后续再出现一样的奇偶组合时，二者相减即为最大长度；
3、储存奇偶状态只需要使用二进制的0和1即可，因为共有5个元音，所以只需要长度为32的数组即可表示，数组中的元素代表该情况出现的最早位置；

评测结果：
112ms, 54.50%; 16.2MB, 100%;
 */

class Solution {
public:
    int findTheLongestSubstring(string s) {
        vector<int> first(32, -2);
        first[0] = -1;
        int ans = 0, status = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'a') status ^= 1 << 0;
            else if (s[i] == 'e') status ^= 1 << 1;
            else if (s[i] == 'i') status ^= 1 << 2;
            else if (s[i] == 'o') status ^= 1 << 3;
            else if (s[i] == 'u') status ^= 1 << 4;

            if (first[status] == -2) {
                first[status] = i;
            } else {
                ans = max(ans, i-first[status]);
            }
        }

        return ans;
    }
};