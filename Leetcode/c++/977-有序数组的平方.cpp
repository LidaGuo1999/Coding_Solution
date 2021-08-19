/*
 *
 * 思路梳理：
 * 1、将每个数字平方，再按照从小到大排列即可；
 *
 * 评测结果：
 * 116ms，42.50%；24.4MB，57.06%；
 */

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        for (int i = 0; i < A.size(); i++) {
            A[i] = A[i]*A[i];
        }
        sort(A.begin(), A.end());

        return
    }
};
