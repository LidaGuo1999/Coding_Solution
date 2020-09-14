// 对于一个给定的链表，返回环的入口节点，如果没有环，返回null

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        int cnt = 0;
        while (fast != NULL) {
            fast = fast->next;
            if (fast == NULL) return NULL;
            else fast = fast->next;
            slow = slow->next;
            cnt++;
            if (fast == slow) break;
        }
        if (fast == NULL) return NULL;
        
        slow = head, fast = head;
        for (int i = 0; i < cnt; i++) fast = fast->next;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        
        return slow;
    }
};

