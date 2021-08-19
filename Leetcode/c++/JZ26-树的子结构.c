/*
 *
 * 思路梳理：
 * 1、遍历A中的每一颗子树，让每一颗子树都和B进行比较，若B是其中某一颗子树的子结构（前提是B和该子树的根节点必须相同，那么B就是A的一个子结构；
 * 2、在判断B和A的子树结构是否相同时，就是简单的递归，一个点一个点对比；
 *
 * 评测结果：
 * 40ms，56.80%；18.8MB，6.39%；
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

int compare(TreeNode *a, TreeNode *b) {
    if (a == NULL && b == NULL) return 1;
    else if (b == NULL) return 1;
    else if (a == NULL) return 0;

    if (a->val == b->val) {
        return (compare(a->left, b->left) && compare(a->right, b->right));
    } else return 0;
}

bool isSubStructure(struct TreeNode* A, struct TreeNode* B){
    if (B == NULL) return 0;

    TreeNode *q[10005];
    int top = -1, ans = 0;

    q[++top] = A;
    while (top > -1) {
        TreeNode *root = q[top--];
        ans = compare(root, B);
        if (ans == 1) break;
        if (root->left != NULL) q[++top] = root->left;
        if (root->right != NULL) q[++top] = root->right;
    }

    return ans;
}
