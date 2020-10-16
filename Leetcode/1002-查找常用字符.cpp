/*
 *
 * 思路梳理：
 * 1、这是一道简单的模拟题，利用一个数组total[c]来存储字符c在所有字符串中出现次数的最小值；
 *
 * 评测结果：
 * 12ms，91.96%；9.5MB，36.34%；
 */
class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<string> ans;
        vector<int> total(26, -1);
        int len = A.size();
        for (int i = 0; i < len; i++) {
            vector<int> unit(26, 0);
            for (char c: A[i]) {
                unit[c-'a']++;
            }
            for (int j = 0; j < 26; j++) {
                if (total[j] == -1) {
                    total[j] = unit[j];
                } else {
                    if (unit[j] < total[j]) total[j] = unit[j];
                }
            }
        }
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < total[i]; j++) {
                ans.push_back(string(1, 'a'+i));
            }
        }

        return ans;
    }
};
