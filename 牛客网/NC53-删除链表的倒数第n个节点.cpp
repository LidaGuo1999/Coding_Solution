// 给定一个链表，删除链表的倒数第n个节点并返回链表的头指针

/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */

class Solution {
public:
    /**
     * 
     * @param head ListNode类 
     * @param n int整型 
     * @return ListNode类
     */
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // write code here
        ListNode *tra = (ListNode*)malloc(sizeof(ListNode));
        tra->next = head;
        ListNode *fast = tra, *slow = tra;
        
        for (int i = 0; i < n+1; i++) fast = fast->next;
        
        while (fast != NULL) {
            fast = fast->next;
            slow = slow->next;
        }
        
        slow->next = slow->next->next;
        
        return tra->next;
    }
};
