/*
给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。

k 是一个正整数，它的值小于或等于链表的长度。

如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。

思路梳理：
1、首先遍历一遍链表，获得整个链表的长度，从而计算共有几组需要翻转；
2、对于每一组，我们将第i+1个节点插到第i个节点前面，并记录下相关的信息，不断向前推进即可。需要注意的是需要记录下每一组翻转完后的最后一个节点，以便与下一组的头相连；

评测结果：
20ms, 62.47%; 8.9MB, 100%;
 */

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int length = 0;
        ListNode* h = head;
        while (h != NULL) {
            length++;
            h = h->next;
        }
        if (k == 0 || k == 1) return head;
        int group = length/k;
        ListNode* tmp, *tail = head, *ans, *last_tail;
        h = head;

        for (int i = 0; i < group; i++) {
            for (int j = 0; j < k-1; j++) {
                tmp = tail->next->next;
                tail->next->next = h;
                h = tail->next;
                tail->next = tmp;
            }
            
            if (i > 0) last_tail->next = h;

            if (i == 0) {
                ans = h;
            }
            //cout << h->val << " " << tail->val << " " << tail->next->val << endl;
            last_tail = tail;
            h = tail = tail->next;

        }

        return ans;
    }
};