# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

# 使用哈希表（集合）当然能够快速解决，但是我们选择使用空间复杂度更低的快慢指针。快指针每次走两个节点，慢指针每次走一个节点，
# 如果有环，那快慢指针总会有相等的时候，如果没环，那么二者不会相遇，直到链表尾部。
# 72ms, 34.62%; 16.8MB, 0%
class Solution:
    def hasCycle(self, head: ListNode) -> bool:
        if head == None or head.next == None:
            return False
        slow = head
        fast = head.next
        while slow != fast:
            if fast == None or fast.next == None:
                return False
            slow = slow.next
            fast = fast.next.next
        return True