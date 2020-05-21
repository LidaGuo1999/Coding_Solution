# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

# 该题的主要思想就是把到达两个节点的路径写出来，然后进行比较即可。求路径使用深度优先算法，参考中序遍历即可
# 104ms, 37.72%: 24.1MB, 33.33% 
class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        p_order = []
        q_order = []
        self.cal_order(root, p, p_order)
        self.cal_order(root, q, q_order)
        for i in range(len(p_order)):
            if len(q_order) < i+1:
                return q_order[-1]
            if p_order[i] != q_order[i]:
                return p_order[i-1]
        return p_order[-1]
                
        
    def cal_order(self, root, k, order):
        order.append(root)
        if order[-1].val == k.val:
            return 1
        if root.left:
            flag = self.cal_order(root.left, k, order)
            if flag == 1:
                return 1
        if root.right:
            flag = self.cal_order(root.right, k, order)
            if flag == 1:
                return 1
        order.pop()
        return 0