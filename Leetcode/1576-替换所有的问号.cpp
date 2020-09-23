/* 问题描述：
 * 给你一个仅包含小写英文字母和 '?' 字符的字符串 s<var> </var>，请你将所有的 '?' 转换为若干小写字母，使最终的字符串不包含任何 连续重复的字符
 *
 * 思路梳理：
 * 1、从左到右遍历字符串，碰到'?'就从a到z遍历可能的字符，只要该字符满足题目条件即可使用，总体上没什么技术含量；
 *
 * 评测结果：
 * 4ms，100%；6.2MB，100%；
 */

class Solution {
public:
    string modifyString(string s) {
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '?') {
                for (char c = 'a'; c <= 'z'; c++) {
                    if (i < 1 || (i >= 1 && s[i-1] != c)) {
                        if (i >= s.length()-1 || (i < s.length()-1 && s[i+1] != c)) {
                            s[i] = c;
                            break;
                        }
                    }
                }
            }
        }

        return s; 
    }
};
