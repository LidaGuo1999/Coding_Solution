/* 将两个有序的链表合并为一个新链表，要求新的链表是通过拼接两个链表的节点来生成的。（默认是单调增排列）
 */

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
     * @param l1 ListNode类 
     * @param l2 ListNode类 
     * @return ListNode类
     */
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // write code here
        ListNode *head = (ListNode *)malloc(sizeof(ListNode));
        ListNode *tra1 = l1, *tra2 = l2, *tra = head;
        while (tra1 != NULL || tra2 != NULL) {
            if (tra1 == NULL || (tra2 != NULL && tra2->val <= tra1->val)) {
                tra->next = tra2;
                tra2 = tra2->next;
                tra = tra->next;
            } else {
                tra->next = tra1;
                tra1 = tra1->next;
                tra = tra->next;
            }
        }
        
        return head->next;
    }
};
