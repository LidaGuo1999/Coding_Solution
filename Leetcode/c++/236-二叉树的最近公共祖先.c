/*
 *
 * 思路梳理：
 * 1、采用递归的方法，对于每个根结点，我们通过递归得到以该节点为根节点的子树中含有p，q两节点的数量；
 * 2、当数量为2时，说明p，q节点均为其子树中的节点，该根结点是一个公共祖先；
 * 3、为了完成最近公共祖先的判断，我们设置一个全局变量ancient，只有第一次数量为2时，才给其赋值；
 *
 * 评测结果：
 * 36ms，22.67%；17.7MB，94.08%；
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
TreeNode *ancient;

int nearestParent(TreeNode *root, TreeNode *p, TreeNode *q) {
    if (root == NULL) return 0;
    if (ancient != NULL) return 0;
    
    int left = 0, right = 0, total = 0;
    left = nearestParent(root->left, p, q);
    right = nearestParent(root->right, p, q);
    if (root->val == p->val || root->val == q->val) total = left+right+1;
    else total = left+right;

    if (total == 2 && ancient == NULL) ancient = root;
    return total;
}

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    ancient = NULL;
    int flag = nearestParent(root, p, q);
    if (flag == 2) return ancient;
    else return NULL;
}
