#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
};

ListNode* init(vector<int> vals) {
    ListNode* head = new ListNode;
    ListNode* last = head;
    for (int i: vals) {
        ListNode* tmp = (ListNode*)malloc(sizeof(ListNode));
        tmp->val = i;
        tmp->next = NULL;
        last->next = tmp;
        last = tmp;
    }

    return head;
}

void traverse(ListNode* head) {
    ListNode* tra = head->next;
    while (tra != NULL) {
        printf("%d ", tra->val);
        tra = tra->next;
    }
    printf("\n");
}

void insert(ListNode* head, int index, int val) {
    ListNode* tra = head;
    for (int i = 0; i < index; i++) {
        tra = tra->next;
        if (tra == NULL) {
            printf("Index out of range!\n");
            return ;
        }
    }

    ListNode* tmp = (ListNode*)malloc(sizeof(ListNode));
    tmp->val = val;
    if (tra->next == NULL) {
        tra->next = tmp;
        tmp->next = NULL;
    } else {
        tmp->next = tra->next;
        tra->next = tmp;
    }

    return ;
}

int val_delete(ListNode* head, int val) {
    ListNode* tra = head;
    //printf("%d %d\n", &head, &tra);
    while (tra->next != NULL) {
        if (tra->next->val == val) {
            tra->next = tra->next->next;
        } else {
            tra = tra->next;
        }
    }

    return 0;
}

void modify(ListNode* head, int index, int nval) {
    ListNode* tra = head->next;
    for (int i = 0; i <= index; i++) {
        if (tra == NULL) {
            printf("Index out of range!\n");
            return ;
        }
        if (i == index) tra->val = nval;
        tra = tra->next;
    }
}

ListNode* search(ListNode* head, int val) {
    ListNode* tra = head->next;
    while (tra != NULL) {
        if (tra->val == val) {
            printf("Address for tra is: %d\n", &tra);
            return tra;
        }
        tra = tra->next;
    }

    return NULL;
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 8, 10};
    ListNode* head = init(nums);
    
    traverse(head);
    insert(head, 3, 666);
    traverse(head);
    insert(head, 11, -4);
    traverse(head);
    insert(head, 15, 111);
    traverse(head);

    val_delete(head, 3);
    traverse(head);
    val_delete(head, 8);
    traverse(head);
    val_delete(head, -4);
    traverse(head);

    modify(head, 0, 47);
    traverse(head);
    modify(head, 5, 48);
    traverse(head);
    modify(head, 7, -5);
    traverse(head);
    modify(head, 10, 100);
    traverse(head);
    
    //ListNode* tmp1 = search(head, 4);
    //printf("%d\n", tmp1->val);
    printf("Address for tmp1 is: %d\n", &(search(head, 4)));
    return 0;
}
