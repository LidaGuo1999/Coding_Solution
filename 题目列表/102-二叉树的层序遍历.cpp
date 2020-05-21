/*
给你一个二叉树，请你返回其按 层序遍历 得到的节点值。 （即逐层地，从左到右访问所有节点）。

思路梳理：
1、经典的方法应该是使用队列，每一次队列里的值应该是第i层从左到右的所有节点，更新的时候利用第i层的节点按顺序找到i+1层的所有节点；
2、我第一印象的方法就是使用一般的递归，只需要一个变量记录下当前的层数，然后不断递归即可。

评测结果：
0ms, 100%; 11.7MB, 100%;
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int> > matrix;
        int cur_level = 1;                  // 此处默认传进来的树至少有一个根节点；
        if (root == NULL) return matrix;    // 需要进行特判，即树不存在的情况；
        gothrough(matrix, cur_level, root);

        return matrix;
    }

    void gothrough(vector<vector<int> >& matrix, int cur_level, TreeNode* root) {
        if (matrix.size() < cur_level) matrix.resize(cur_level);                // 将矩阵matrix扩充到至少cur_level行；
        matrix[cur_level-1].push_back(root->val);
        if (root->left != NULL) gothrough(matrix, cur_level+1, root->left);     // 这里我用的是前序遍历；
        if (root->right != NULL) gothrough(matrix, cur_level+1, root->right);
    }
};