#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

typedef struct node {
    char c;
    struct node *left, *right;
} node;

node* build_tree(char s[]) {
    int len = strlen(s);
    node *head = NULL;
    for (int i = 0; i < len; i++) {
        char tmp = s[i];
        if (head == NULL) {
            head = (node*)calloc(1, sizeof(node));
            head->c = tmp;
        }
        else {
            node *tra = head;
            while (true) {
                if (tmp < tra->c) {
                    if (tra->left == NULL) {
                        node *add = (node*)calloc(1, sizeof(node));
                        add->c = tmp;
                        tra->left = add;
                        break;
                    } else {
                        tra = tra->left;
                        continue;
                    }
                } else {
                    if (tra->right == NULL) {
                        node *add = (node*)calloc(1, sizeof(node));
                        add->c = tmp;
                        tra->right = add;
                        break;
                    } else {
                        tra = tra->right;
                        continue;
                    }
                }
            }
        }
    }
    return head;
}

bool isSame(node *h1, node *h2) {
    if (h1 == NULL && h2 == NULL) return true;
    else if (h1 == NULL || h2 == NULL) return false;

    if (h1->c == h2->c) {
        bool l, r;
        l = isSame(h1->left, h2->left);
        r = isSame(h1->right, h2->right);
        return (l&r);
    } else {
        return false;
    }

    return false;
}   

int main() {
    int n;
    char ori[15] = {0}, com[15] = {0};
    while (scanf("%d", &n) != EOF) {
        while (getchar() != '\n');
        if (n == 0) break;
        fgets(ori, 15, stdin);
        ori[strlen(ori)-1] = '\0';
        //printf("size:%d\n", strlen(ori));
        node *ohead = build_tree(ori);
        for (int i = 0; i < n; i++) {
            fgets(com, 15, stdin);
            com[strlen(com)-1] = '\0';
            node *chead = build_tree(com);
            if (isSame(ohead, chead)) printf("YES\n");
            else printf("NO\n");
        }
    }

    return 0;
}
