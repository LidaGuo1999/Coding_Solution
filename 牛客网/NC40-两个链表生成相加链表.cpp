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
     * @param head1 ListNode类 
     * @param head2 ListNode类 
     * @return ListNode类
     */
    ListNode* reverse(ListNode* head) {
        ListNode *first, *second, *third;
        if (head->next == NULL) return head;
        first = head, second = head->next, third = head->next->next;
        while (true) {
            if (first->next == second) first->next = NULL;
            second->next = first;
            if (third == NULL) break;
            first = second, second = third, third = third->next;
        }
        
        return second;
    }
    
    ListNode* addInList(ListNode* head1, ListNode* head2) {
        // write code here
        ListNode *tra1 = reverse(head1), *tra2 = reverse(head2);
        //if (head1->next == NULL) printf("Empty!\n");
        //printf("%d %d\n", tra1->val, tra1->next->val);
        int carry = 0;
        vector<int> nums;
        while (tra1 != NULL || tra2 != NULL) {
            //printf("%d\n", tra1->val);
            int sum = carry;
            if (tra1 == NULL) sum += tra2->val;
            else if (tra2 == NULL) sum += tra1->val;
            else sum += tra1->val+tra2->val;
            
            if (sum >= 10) {
                sum -= 10;
                carry = 1;
            } else carry = 0;
            nums.push_back(sum);
            
            if (tra1 != NULL) tra1 = tra1->next;
            if (tra2 != NULL) tra2 = tra2->next;
        }
        if (carry == 1) nums.push_back(1);
        
        ListNode *ans = (ListNode*)malloc(sizeof(ListNode)), *tra = ans;
        for (int i = nums.size()-1; i >= 0; i--) {
            ListNode *tmp = (ListNode*)malloc(sizeof(ListNode));
            tmp->val = nums[i];
            tmp->next = NULL;
            tra->next = tmp;
            tra = tra->next;
        }
        
        return ans->next;
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

void show(ListNode* head) {
    ListNode *tmp = head;
    while (tmp != NULL) {
        printf("%d ", tmp->val);
        tmp = tmp->next;
    }
    printf("\n");
}

int main() {
    Solution s;
    vector<int> vals = {1, 2, 3, 4, 5, 6, 7, 8}, vals2 = {5, 6, 7, 8, 9};
    ListNode* ori = generate(vals);

    show(ori);
    ListNode *rev = s.reverse(ori);
    show(rev);
    //if (ori->next == NULL) printf("Really!\n");
    ListNode *ori1 = generate(vals);
    ListNode *ori2 = generate(vals2);
    ListNode *add = s.addInList(ori1, ori2);
    show(add);

    return 0;
}
