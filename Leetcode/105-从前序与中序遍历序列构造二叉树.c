/*
 *
 * 思路梳理：
 * 1、首先观察两种遍历的特点，前序遍历结构为[root,[left tree],[right tree]]，中序遍历结构为[[left tree],root,[right tree]]；
 * 2、因此我们可以从前序遍历中得到根节点（即第一个），然后在中序遍历中找到该根节点，那么中序遍历中在该节点左边的所有数为左子树，右边的所有数为右子树；
 * 3、根据这一思想，逐步往下递归即可；
 * 4、出口条件就是代表子树的数组中已经没有元素了，此时返回NULL即可；
 *
 * 评测结果：
 * 16ms，83.90%；11.1MB，37.03%；
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
int pos = 0;

TreeNode* insertNode(int* preorder, int* inorder, int start, int end) {
    if (start > end) return NULL;
    int cur = preorder[pos++];

    int inde;
    for (inde = start; inde <= end; inde++) {
        if (inorder[inde] == cur) break;
    }
    TreeNode *nnode = (TreeNode*)calloc(1, sizeof(TreeNode));
    nnode->val = cur;
    nnode->left = insertNode(preorder, inorder, start, inde-1);
    nnode->right = insertNode(preorder, inorder, inde+1, end);

    return nnode;
}

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize){
    pos = 0;
    TreeNode *root = insertNode(preorder, inorder, 0, inorderSize-1);
    return root;
}
