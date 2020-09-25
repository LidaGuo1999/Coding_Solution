/*
 *
 * 思路梳理：
 * 1、通过递归确定每一个节点所允许的上界和下界。
 * 2、左子节点的最大值为根结点的值，左子节点的最小值为根结点的最小值；
 * 3、右子节点的最大值为根结点的最大值，右子节点的最小值为根结点的值；
 *
 * 评测结果：
 * 12ms，46.54%；8.2MB，45.41%；
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

int judge(TreeNode *root, long top, long bottom) {
    if (root == NULL) return 1;
    
    if (root->val < top && root->val > bottom) {
        int flag = judge(root->left, root->val, bottom) && judge(root->right, top, root->val);
        return flag;
    } else {
        return 0;
    }
}

bool isValidBST(struct TreeNode* root){
    int flag = judge(root, LONG_MAX, LONG_MIN);
    return flag;
}
