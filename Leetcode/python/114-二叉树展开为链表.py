# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def flatten(self, root: TreeNode) -> None:
        # 利用前序遍历，同时利用一个栈来储存右子节点的信息
        """
        Do not return anything, modify root in-place instead.
        """
        stack = []
        cur = root
        head = TreeNode
        last = head
        while cur != None:
            last.right = cur
            if cur.right != None: 
                stack.append(cur.right)
            last = cur
            if cur.left != None: 
                cur = cur.left
                last.left = None
            elif len(stack) > 0:
                cur = stack.pop()
            else: break
        return 
                


