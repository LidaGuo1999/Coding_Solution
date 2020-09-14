#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
};


class Solution {
public:
    /**
     * 
     * @param head ListNode类 
     * @param k int整型 
     * @return ListNode类
     */
    ListNode* reverseKGroup(ListNode* head, int k) {
        // write code here
        if (head == NULL) return head;
        if (k == 1 || head->next == NULL) return head;
        ListNode *nhead = (ListNode*)malloc(sizeof(ListNode));
        nhead->next = head;
        ListNode *prev = NULL, *cur = head, *next = head->next, *tail1 = nhead, *tail2 = NULL;
        while (next != NULL) {
            //printf("%d\n", cur->val);
            ListNode *check = cur;
            int remain = 1;
            for (int i = 0; i < k-1; i++) {
                check = check->next;
                if (check == NULL) {
                    remain = 0;
                    break;
                }
            }
            if (remain == 0) {
                tail1->next = cur;
                break;
            }
            
            tail2 = cur;
            for (int i = 0; i < k-1; i++) {
                cur->next = prev;
                prev = cur, cur = next;
                next = next->next;
            }
            cur->next = prev;
            tail1->next = cur;
            tail1 = tail2;

            prev = NULL, cur = next;
            if (next != NULL) next = next->next;
        }

        if (cur != NULL && next == NULL) {
            tail1->next = cur;
        }
        
        return nhead->next;
    }
};

ListNode* generate(vector<int> vals) {
    ListNode *head = (ListNode*)malloc(sizeof(ListNode)), *tra = head;
    for (int i: vals) {
        ListNode *tmp = (ListNode*)malloc(sizeof(ListNode));
        tmp->val = i;
        tmp->next = NULL;
        tra->next = tmp;
        tra = tra->next;
    }

    return head->next;
}

void show(ListNode *head) {
    ListNode *tmp = head;
    while (tmp != NULL) {
        printf("%d ", tmp->val);
        tmp = tmp->next;
    }
    printf("\n");

    return ;
}

int main() {
    vector<int> vals = {};
    ListNode *ori = generate(vals);
    show(ori);

    Solution s;
    ListNode *change = s.reverseKGroup(ori, 3);
    show(change);

    return 0;
}
