
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node {
    int id;
    struct node *lchild, *rchild;
} node;

void search(node *head, int d) {
    if (head == NULL) return ;
    int level = 1, width = 1, front = 0, bottom = 0, flag = 0;
    node *q[1005] = {0}, *cur = NULL;
    q[bottom++] = head;
    while (front < bottom) {
        int nlevel = 0;
        int reach = 0;
        for (int i = 0; i < width; i++) {
            cur = q[front++];
            if (cur->lchild != NULL) {
                q[bottom++] = cur->lchild;
                nlevel++;
            }
            if (cur->rchild != NULL) {
                q[bottom++] = cur->rchild;
                nlevel++;
            }
            if (level == d) {
                printf("%d ", cur->id);
                reach = 1;
                flag = 1;
            } else {}
        }
        width = nlevel;
        level++;
        if (reach == 1) {
            break;
        } else {
            continue;
        }
    }
    if (flag == 0) printf("EMPTY");
    printf("\n");

    return ;
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        node *q[1005], *head = NULL;
        int front = 0, bottom = 0, nums[1005] = {0};
        memset(q, 0, sizeof(q));

        for (int i = 0; i < n; i++) {
            scanf("%d", &nums[i]);
        }
        if (n > 0) {
            int pos = 0;
            node *cur = NULL;
            head = (node*)calloc(1, sizeof(node));
            head->id = nums[0];
            pos++;
            if (pos < n) {
                node *left = (node*)calloc(1, sizeof(node));
                left->id = nums[pos++];
                head->lchild = left;
                q[bottom++] = left;
            }
            if (pos < n) {
                node *right = (node*)calloc(1, sizeof(node));
                right->id = nums[pos++];
                head->rchild = right;
                q[bottom++] = right;
            }
            while (pos < n && front != bottom) {
                cur = q[front++];
                node *tmp = (node*)calloc(1, sizeof(node));
                tmp->id = nums[pos++];
                cur->lchild = tmp;
                q[bottom++] = tmp;
                if (pos < n) {
                    node *right = (node*)calloc(1, sizeof(node));
                    right->id = nums[pos++];
                    cur->rchild = right;
                    q[bottom++] = right;
                } else break;
            }

            int d;
            scanf("%d", &d);
            search(head, d);

        } else {}
    }

    return 0;
}
