/*
将两个升序链表合并为一个新的升序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 一个使用链表的归并排序中的“合并”步骤而已。人工构造一个头节点，其next指针指向返回链表的第一个节点即可。
// 8ms, 80.16%; 7.3MB, 100%;

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* total = new ListNode;

        ListNode* cur = total;
        while (l1 != NULL && l2 != NULL) {
            if (l1->val <= l2->val) {
                ListNode* tmp = new ListNode(l1->val);
                cur->next = tmp;
                l1 = l1->next;
                cur = cur->next;
            } else {
                ListNode* tmp = new ListNode(l2->val);
                cur->next = tmp;
                l2 = l2->next;
                cur = cur->next;
            }
        }
        while (l1 != NULL) {
            ListNode* tmp = new ListNode(l1->val);
            cur->next = tmp;
            l1 = l1->next;
            cur = cur->next;
        }
        while (l2 != NULL) {
            ListNode* tmp = new ListNode(l2->val);
            cur->next = tmp;
            l2 = l2->next;
            cur = cur->next;
        }

        return total->next;
    }
};