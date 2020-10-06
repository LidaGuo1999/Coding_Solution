#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

typedef struct node {
    long long coe, exp;
    struct node *next;
} node;

node* init() {
    node *nhead = (node*)calloc(1, sizeof(node)), *tail = nhead;
    char line[1005] = {0};
    fgets(line, 1005, stdin);
    int len = strlen(line);
    for (int i = 0; i < len; ) {
        long long num = 0, coe = 0, exp = 0;
        if (line[i] >= '0' && line[i] <= '9') {
            coe = coe*10+line[i]-'0';
            i++;
            while (i < len && line[i] >= '0' && line[i] <= '9') {
                coe = coe*10+line[i]-'0';
                i++;
            }
            while (line[i] == ' ') i++;
            while (i < len && line[i] >= '0' && line[i] <= '9') {
                exp = exp*10+line[i]-'0';
                i++;
            }

            node *tmp = (node*)calloc(1, sizeof(node));
            tmp->coe = coe, tmp->exp = exp;
            tail->next = tmp;
            tail = tail->next;
        } else {
            i++;
        }
    }
    return nhead->next;
}

node *cal(node *head1, node *head2) {
    node *tra1 = head1, *tra2 = head2, *sum = (node*)calloc(1, sizeof(node));
    sum->exp = 1000000000;
    while (tra1 != NULL) {
        tra2 = head2;
        while (tra2 != NULL) {
            long long coe = tra1->coe*tra2->coe, exp = tra1->exp+tra2->exp;
            node *tra = sum;
            while (true) {
                if (tra->next == NULL || (exp <= tra->exp && exp > tra->next->exp)) break;
                tra = tra->next;
            }
            if (tra->exp == exp) tra->coe += coe;
            else if (tra->exp > exp) {
                node *tmp = (node*)calloc(1, sizeof(node));
                tmp->coe = coe, tmp->exp = exp;
                tmp->next = tra->next;
                tra->next = tmp;
            }

            tra2 = tra2->next;
        }
        tra1 = tra1->next;
    }
    return sum->next;
}

void output(node *ans) {
    node *tra = ans;
    while (tra != NULL) {
        printf("%lld %lld ", tra->coe, tra->exp);
        tra = tra->next;
    }
    printf("\n");
    return ;
}

int main() {
    node *head1 = init();
    node *head2 = init();

    node *ans = cal(head1, head2);
    output(ans);

    return 0;
}
