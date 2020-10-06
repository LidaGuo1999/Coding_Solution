#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

typedef struct node {
    int coe, exp;
    struct node *next;
} node;

void output(node *head) {
    node *tra = head;
    while (tra != NULL) {
        printf("%d %d ", tra->coe, tra->exp);
        tra = tra->next;
    }
    printf("\n");
    return ;
}

node* reverse(node *head) {
    if (head == NULL) return NULL;
    node *pre = NULL, *cur = head, *tmp = cur->next;
    while (cur != NULL) {
        cur->next = pre;
        pre = cur;
        cur = tmp;
        if (tmp != NULL) tmp = tmp->next;
    }

    return pre;
}

int main() {
    int n, m, coe, exp;
    node *head1 = (node*)calloc(1, sizeof(node)), *head2 = (node*)calloc(1, sizeof(node));
    head1->exp = 20000;
    scanf("%d", &n);
    node *tra1 = head1;
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &coe, &exp);
        node *tmp = (node*)calloc(1, sizeof(node));
        tmp->coe = coe, tmp->exp = exp;
        tra1->next = tmp;
        tra1 = tra1->next;
    }
    
    node *tra2 = head2;
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &coe, &exp);
        node *tmp = (node*)calloc(1, sizeof(node));
        tmp->coe = coe, tmp->exp = exp;
        tra2->next = tmp;
        tra2 = tra2->next;
    }
    //printf("here\n");
    head1->next = reverse(head1->next);
    head2->next = reverse(head2->next);

    //output(head1->next);
    //output(head2->next);
    
    tra2 = head2->next;
    for (int i = 0; i < m; i++) {
        tra1 = head1;
        while (tra1->next != NULL && tra2->exp <= tra1->next->exp) {
            tra1 = tra1->next;
        }
        //printf("%d %d\n", tra1->exp, tra2->exp);
        if (tra2->exp == tra1->exp) {
            tra1->coe += tra2->coe;
        } else {
            node *tmp = (node*)calloc(1, sizeof(node));
            tmp->coe = tra2->coe, tmp->exp = tra2->exp;
            tmp->next = tra1->next;
            tra1->next = tmp;
        }
        tra2 = tra2->next;
        //output(head1->next);
    }
    //output(head1->next);

    tra1 = head1->next;
    int cnt = 0;
    while (tra1 != NULL) {
        if (tra1->coe != 0) {
            if (cnt == 0) {
                printf("%d %d", tra1->coe, tra1->exp);
            } else {
                printf(" %d %d", tra1->coe, tra1->exp);
            }
            tra1 = tra1->next;
            cnt++;
        } else {
            tra1 = tra1->next;
            continue;
        }
    }
    printf("\n");

    return 0;
}
