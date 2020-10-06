#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

typedef struct node {
    int id;
    struct node *next;
} node;

node *init(int n) {
    node *nhead = (node*)calloc(1, sizeof(node)), *tail = nhead;
    for (int i = 1; i <= n; i++) {
        node *tmp = (node*)calloc(1, sizeof(node));
        tmp->id = i;
        tail->next = tmp;
        tail = tail->next;
    }
    tail->next = nhead->next;

    return nhead->next;
}

node *find_tail(node *head) {
    node *tra = head, *start = head;
    while (tra->next != start) {
        tra = tra->next;
    }
    return tra;
}

int main() {
    int n, m, q;
    scanf("%d %d %d", &n, &m, &q);
    node *head = init(n);
    node *cur = head, *pre = find_tail(head);
    for (int i = 1; i < q; i++) {
        pre = cur;
        cur = cur->next;
    }
    
    while (cur->next != cur) {
        for (int i = 1; i < m; i++) {
            pre = cur;
            cur = cur->next;
        }
        pre->next = cur->next;
        cur = cur->next;
    }

    printf("%d\n", cur->id);

    return 0;
}
