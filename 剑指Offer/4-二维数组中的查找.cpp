/*
在一个 n * m 的二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
 */

// 根据二维数组的特点，从左下角或者右上角开始，就转变成排序二叉树寻找某个特定节点的问题了。
// 56ms, 39.27%; 13.2MB, 100%;

class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if (matrix.empty()) return false;
        int n = matrix.size(), m = matrix[0].size();
        int i = 0, j = m-1;
        while (i < n && j >= 0 ) {
            if (matrix[i][j] > target) j--;
            else if (matrix[i][j] < target) i++;
            else return true;
        }
        return false;
    }
};