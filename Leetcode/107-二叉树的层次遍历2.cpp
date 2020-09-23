/* 题目描述：给定一个二叉树，返回其节点值自底向上的层次遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）
 *
 * 思路梳理：
 * 1、看到树的层次遍历，想到使用BFS遍历整棵树，使用队列来存储某一层的所有节点；
 * 2、由于最终输出的是自底向上的遍历，所以要将BFS的结果翻转过来即可；
 *
 * 评测结果：
 * 8ms，55.76%；11.7MB，69.34%；
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<TreeNode*> > nh;
        vector<vector<int> > ans;

        if (!root) return ans;
        
        nh.push_back(vector<TreeNode*>());
        nh[0].push_back(root);

        int cnt = 1, level = 0;
        while (cnt) {
            cnt = 0;
            nh.push_back(vector<TreeNode*>());
            
            for (TreeNode* x: nh[level]) {
                if (x->left) {
                    nh[level+1].push_back(x->left);
                    cnt++;
                }
                if (x->right) {
                    nh[level+1].push_back(x->right);
                    cnt++;
                }
            }

            level++;
        }

        for (auto i = nh.end()-2; i >= nh.begin(); i--) {
            vector<int> temp;
            for (auto x: *i) {
                temp.push_back(x->val);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
