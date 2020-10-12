
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node {
    int id;
    struct node *parent, *lchild, *mchild, *rchild;
} node;

typedef struct leaf {
    int id, priority;
} leaf;

node* findPath(node *start, node *end) {
    int spath[105] = {0}, epath[105] = {0}, scnt = 0, ecnt = 0;
    node *s = start, *e = end;
    while (1) {
        spath[scnt++] = s->id;
        if (s->parent != NULL) {
            s = s->parent;
        } else {
            break;
        }
    }
    while (1) {
        epath[ecnt++] = e->id;
        if (e->parent != NULL) {
            e = e->parent;
        } else {
            break;
        }
    }

    int a = scnt-1, b = ecnt-1, meet = -1, aa = -1, bb = -1;
    while (a >= 0 && b >= 0) {
        if (spath[a] == epath[b]) {
            meet = spath[a];
            aa = a, bb = b;
        }
        a--, b--;
    }

    for (int i = 0; i < scnt; i++) {
        if (i == 0) {
            if (spath[i] >= 100) printf("%d ", spath[i]);
        } else {
            printf("%d ", spath[i]);
        }

        if (spath[i] == meet) break;
    }
    if (epath[bb] >= 100) {
        for (int i = bb-1; i >= 0; i--) {
            printf("%d ", epath[i]);
        }
    } else {
        for (int i = bb; i >= 0; i--) {
            printf("%d ", epath[i]);
        }
    }

    printf("\n");

    return end;
}

int main() {
    int n, m, root, ch1, ch2, ch3;
    node *q[10000], *head;
    node *yz[105];
    int front = 0, bottom = 0;
    memset(q, 0, sizeof(q)), memset(yz, 0, sizeof(yz));
    scanf("%d", &n);

    if (n == 0) {
        return 0;
    }

    for (int i = 0; i < n; i++) {
        node *tmp;
        scanf("%d %d %d %d", &root, &ch1, &ch2, &ch3);
        if (i == 0) {
            tmp = (node *) calloc(1, sizeof(node));
            tmp->id = root;
            head = tmp;
        } else {
            tmp = q[front++];
        }
        if (ch1 != -1) {
            node *t1 = (node *) calloc(1, sizeof(node));
            t1->id = ch1;
            t1->parent = tmp;
            tmp->lchild = t1;
            if (ch1 >= 100) {
                q[bottom++] = t1;
            } else {
                yz[ch1] = t1;
            }
        }
        if (ch2 != -1) {
            node *t2 = (node *) calloc(1, sizeof(node));
            t2->id = ch2;
            t2->parent = tmp;
            tmp->mchild = t2;
            if (ch2 >= 100) {
                q[bottom++] = t2;
            } else {
                yz[ch2] = t2;
            }
        }
        if (ch3 != -1) {
            node *t3 = (node *) calloc(1, sizeof(node));
            t3->id = ch3;
            t3->parent = tmp;
            tmp->rchild = t3;
            if (ch3 >= 100) {
                q[bottom++] = t3;
            } else {
                yz[ch3] = t3;
            }
        }
    }

    leaf ls[105];
    memset(ls, 0, sizeof(leaf));
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &ls[i].id, &ls[i].priority);
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m-i-1; j++) {
            if (ls[j].priority > ls[j+1].priority) {
                leaf tmp = ls[j];
                ls[j] = ls[j+1];
                ls[j+1] = tmp;
            }
        }
    }

    node *cur = head;
    for (int i = 0; i < m; i++) {
        cur = findPath(cur, yz[ls[i].id]);
    }
    findPath(cur, head);


    return 0;	
}

