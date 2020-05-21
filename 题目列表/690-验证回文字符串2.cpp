/*
给定一个非空字符串 s，最多删除一个字符。判断是否能成为回文字符串。

思路梳理：
1、回文串的判断当然想到双指针法，一个从头遍历，一个从尾遍历；
2、有点变化的地方是可以删除一个字符，所以在遇到第一次不相等的情况时，可以选择检查[i,j-1]或者[i+1,j]是否为回文串；
3、二者只要有一个为回文串，则返回true即可。

评测结果：
92ms, 42.32%; 23.4MB, 42.86%;
 */

class Solution {
public:
    bool validPalindrome(string s) {
        int i = 0, j = s.size()-1;
        while (i < j) {
            if (s[i] != s[j]) {
                if (palin(s.substr(i+1, j-i))) return true;
                else if (palin(s.substr(i, j-i))) return true;
                else return false;
            }
            i++;
            j--;
        }
        return true;
    }

    bool palin(string s) {
        if (s.length() == 1) return true;
        int i = 0, j = s.length()-1;
        while (i < j) {
            if (s[i] != s[j]) return false;
            i++;
            j--;
        }

        return true;
    }
};