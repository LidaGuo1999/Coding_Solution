# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

# 这道题稍稍有些难度，从非叶节点入手，若路径里包含该非叶节点，有两种情况，第一种就是该节点与其左子树中或右子树中的节点构成最大路径；
# 第二种就是该节点与其左子树和右子树中的节点构成最大路径。若是第一种情况，则可以继续向上递归，若是第二种情况，则不能够再向上递归，
# 更新最大值即可。
# 108ms, 58.12%; 20.3MB, 0%
class Solution:
    def maxPathSum(self, root: TreeNode) -> int:
        maxCombine = [-100000000]
        return max(self.recursion(root, maxCombine), maxCombine[-1])
        
        
    def recursion(self, root, maxCombine):
        left = -10000000
        right = -10000000
        if root.left:
            left = self.recursion(root.left, maxCombine)
        if root.right:
            right = self.recursion(root.right, maxCombine)
        
        straight = max(left+root.val, right+root.val, root.val)
        combine = max(left+right, left, right, 0) + root.val
        maxCombine[-1] = max(combine, maxCombine[-1])
        return straight
        
        