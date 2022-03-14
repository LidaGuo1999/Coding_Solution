"""
# Definition for a Node.
class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""

class Solution:
    def connect(self, root: 'Optional[Node]') -> 'Optional[Node]':
        # 在从左到右遍历第N-1层的时候，我们就尽量把第N层的指针设置好，属于一个父节点的直接就可以设置，如果不属于同一个父节点，那么就设计相邻第N-1层相邻两个节点之间的处理。
        if root == None: return

        level_start = root
        cur = root
        while cur.left != None:
            cur.left.next = cur.right
            if cur.next == None:
                # Reach right end.
                tmp = level_start
                while tmp.next != None:
                    tmp.right.next = tmp.next.left
                    tmp = tmp.next
                cur = level_start.left
                level_start = cur
            else: 
                cur = cur.next
        
        return root