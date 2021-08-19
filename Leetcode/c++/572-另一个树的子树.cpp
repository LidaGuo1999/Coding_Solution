/*
题目描述：
给定两个非空二叉树 s 和 t，检验 s 中是否包含和 t 具有相同结构和节点值的子树。s 的一个子树包括 s 的一个节点和这个节点的所有子孙。s 也可以看做它自身的一棵子树。

思路梳理：
1、s中是否包含t，有两种情况，第一种是s和t完全相同，第二种是t是s的左/右子树；
2、所以通过递归进行比较即可；
3、还有一种方法就是将s和t都通过前序遍历转化为数组，如果s的数组中包含t数组，那么s种一定包含t。

运行结果：
80ms, 5.99%; 41.6MB, 12.50%;
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
#include <deque>
class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        TreeNode* head = s;
        deque<TreeNode*> save;
        save.push_back(head);
        while (!save.empty()) {
            head = save.front();
            save.pop_front();
            if (head->val == t->val) {
                if (isSame(head, t)) return true;
            }
            if (head->left != NULL) save.push_back(head->left);
            if (head->right != NULL) save.push_back(head->right);
        }

        return false;
    }

    bool isSame(TreeNode* s, TreeNode* t) {
        TreeNode* shead = s;
        TreeNode* thead = t;
        deque<TreeNode*> ssave, tsave;
        ssave.push_back(shead); tsave.push_back(thead);
        while (!ssave.empty() && !tsave.empty()) {
            shead = ssave.front();
            thead = tsave.front();
            ssave.pop_front();
            tsave.pop_front();
            if (shead->val != thead->val) return false;
            if (shead->left != NULL) ssave.push_back(shead->left);
            if (shead->right != NULL) ssave.push_back(shead->right);
            if (thead->left != NULL) tsave.push_back(thead->left);
            if (thead->right != NULL) tsave.push_back(thead->right);
        }
        if (!ssave.empty() or !tsave.empty()) return false;

        return true;
    }
};