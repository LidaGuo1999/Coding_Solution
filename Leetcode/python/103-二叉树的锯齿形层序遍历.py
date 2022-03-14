# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def zigzagLevelOrder(self, root: TreeNode) -> List[List[int]]:
        # 和层序遍历很像，唯一主要注意的是从左到右和从右到左的交替。可以通过两个数组来回交换（比如我写的），或者也可以通过双端队列完成。
        if root == None: return []

        cur, nex, ret = [root], [], []
        level = 0
        while cur:
            ret.append(list())
            for c in cur:
                ret[-1].append(c.val)
            cur.reverse()
            if level%2 == 0:
                for c in cur:
                    if c.right != None: nex.append(c.right)
                    if c.left != None: nex.append(c.left)
            else: 
                for c in cur:
                    if c.left != None: nex.append(c.left)
                    if c.right != None: nex.append(c.right)
            cur = nex.copy()
            nex.clear()
            level += 1
        return ret
                