# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

# 这道题重点在于理解二叉排序树的概念，其中序遍历必定是从小到大的递增序列，利用深度优先遍历即可解决，Solution2是更好的不使用递归的深度优先遍历
# 72ms, 38.02; 17.6MB, 0
class Solution1:
    def kthSmallest(self, root: TreeNode, k: int) -> int:
        _, ans = self.depthFirst(root, k)
        return ans
        
    def depthFirst(self, root: TreeNode, k: int):
        print('{} {}'.format(root.val, k))
        _k = k
        if root.left != None:
            flag, _k = self.depthFirst(root.left, _k)
            if flag == 1:
                return 1, _k
        if _k == 1:
            return 1, root.val
        _k -= 1
        if root.right != None:
            flag, _k = self.depthFirst(root.right, _k)
            if flag == 1:
                return 1, _k
        return 0, _k
        
class Solution2:
    def kthSmallest(self, root: TreeNode, k: int) -> int:
        # def inorder(root):
        #     if root:
        #         return inorder(root.left) + [root.val] + inorder(root.right)
        #     else:
        #         return []
        # return inorder(root)[k-1]
        stack = []
        while True:
            while root:
                stack.append(root)
                root = root.left
            root = stack.pop()
            k -= 1
            if k == 0:
                return root.val
            root = root.right