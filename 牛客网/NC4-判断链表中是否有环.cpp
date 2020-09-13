// 判断给定的链表中是否有环


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
    bool hasCycle(ListNode *head) {
        ListNode *one = head, *two = head;
        while (one != NULL && two != NULL) {
            one = one->next;
            if (two->next == NULL) {
                two = NULL;
                break;
            }
            two = two->next->next;
            if (one == two) break;
        }
        
        if (one == NULL || two == NULL) return false;
        else return true;
    }
};
