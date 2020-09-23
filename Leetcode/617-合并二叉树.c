/*
 *
 * 思路梳理：
 * 1、核心思想是需要保持新树，树1和树2的遍历同步；
 * 2、如果树1或者树2的某个节点缺失，那么直接将另一个没有缺失的子树拼接到新树上即可；
 * 3、全程使用递归建树的方法即可；
 *
 * 评测结果：
 * 44ms，19.96%；21.9MB，6.23%；
 */


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

typedef struct TreeNode TreeNode;

TreeNode* combine(TreeNode *t1, TreeNode *t2) {
    TreeNode *root = (TreeNode*)calloc(1, sizeof(TreeNode));
    if (t1 != NULL && t2 != NULL) {
        root->val = t1->val+t2->val;
        root->left = combine(t1->left, t2->left);
        root->right = combine(t1->right, t2->right);
    } else if (t1 != NULL) {
        root = t1;
    } else {
        root = t2;
    }

    return root;
}

struct TreeNode* mergeTrees(struct TreeNode* t1, struct TreeNode* t2){
    TreeNode *root = combine(t1, t2);
    return root;    
}
