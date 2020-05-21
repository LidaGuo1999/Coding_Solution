/*
给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
 */


// 思想很简单，就是找到以第i个元素结尾的最长字串的长度，利用动态规划的思想（或者说是滑动窗口）即可遍历解决。
// 36ms, 43.50%; 12.4MB, 38.19%;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if (n == 0) return 0;
        int max_length = 1;
        vector<int> length(n, 0);
        length[0]= 1;
        for (int i = 1; i < n; i++) {
            string tmp = s.substr(i-length[i-1], length[i-1]);
            int pos = tmp.find(s[i]);
            if (pos != string::npos) {
                length[i] = length[i-1]-pos;
            } else {
                length[i] = length[i-1]+1;
            }
            //cout << length[i] << " " << pos << tmp << endl;
            max_length = length[i]>max_length ? length[i] : max_length;
        }

        return max_length;
    }
};