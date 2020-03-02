class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def upsideDownBinaryTree(self, root: TreeNode) -> TreeNode:
        left = root.left
        newRoot = None
        if left == None:
            return root
        else:
            newRoot = self.upsideDownBinaryTree(left)
        left.right = root
        left.left = root.right
        return newRoot

if __name__ == "__main__":
    s = Solution()
    one = TreeNode(1)
    two = TreeNode(2)
    three = TreeNode(3)
    four = TreeNode(4)
    five = TreeNode(5)
    siz = TreeNode(6)

    one.left = two
    print(s.upsideDownBinaryTree(one).right.left.val)