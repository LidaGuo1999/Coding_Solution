/*
根据一棵树的前序遍历与中序遍历构造二叉树。

思路梳理：
1、总体采用递归的思想，根据前序遍历和中序遍历的规则，每一颗子树的所有节点在遍历中应该是紧靠在一起的，所以我们需要找到每一颗子树在遍历中的开始和结束位置；
2、前序遍历的第一个即为根节点，然后在中序遍历中寻找该根节点，中序遍历中在根节点左侧的即为根节点的左子树，右侧的即为根节点的右子树；
3、从而可以根据中序遍历算出左右子树各自的节点数目，进而在前序遍历中也就知道了左右子树各自的范围；
4、然后根据左右子树不断递归即可。

评测结果：
24ms, 79.23%; 18.1MB, 42.42%;
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> inmap;
        for (int i = 0; i < inorder.size(); i++) {
            inmap[inorder[i]] = i;
        }
        return recursion(preorder, inorder, inmap, 0, preorder.size()-1, 0, inorder.size()-1);
    }

    TreeNode* recursion(vector<int>& preorder, vector<int>& inorder, map<int, int>& inmap, int preorder_left, int preorder_right, int inorder_left, int inorder_right) {
        if (preorder_left > preorder_right) return nullptr;
        int root = preorder[preorder_left];
        int index = inmap[root];
        int size_left = index-inorder_left;
        TreeNode* ans = new TreeNode(root);
        ans->left = recursion(preorder, inorder, inmap, preorder_left+1, preorder_left+size_left, inorder_left, index-1);
        ans->right = recursion(preorder, inorder, inmap, preorder_left+size_left+1, preorder_right, index+1, inorder_right);

        return ans;
    }
};