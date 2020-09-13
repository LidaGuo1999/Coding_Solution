/* 问题描述：
 * 输入一个链表，反转链表后，输出新链表的表头。
 */

/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        if (pHead == NULL) return NULL;
        if (pHead->next == NULL) return pHead;
        ListNode* first = pHead, *second = pHead->next, *third = pHead->next->next;
        while (second != NULL) {
            if (first->next == second) first->next = NULL;
            second->next = first;
            first = second, second = third, third = third->next;
        }
        
        return first;
    }
};
