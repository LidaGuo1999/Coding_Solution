#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node {
    char c;
    struct node *left, *right;
} node;

int cur = 1;
int ans = 0;

void build_tree(char ar[105], int len, node* root) {
    if (cur >= len) return ;
    //printf("cur: %d\n", cur);
    if (ar[cur] != '#') {
        node *tmp = (node*)calloc(1, sizeof(node));
        tmp->c = ar[cur];
        //printf("cur[%d] left: %c\n", cur, ar[cur]);
        root->left = tmp;
        cur++;
        build_tree(ar, len, root->left);
    } else cur++;

    if (ar[cur] != '#') {
        node *tmp = (node*)calloc(1, sizeof(node));
        tmp->c = ar[cur];
        //printf("cur[%d] right: %c\n", cur, ar[cur]);
        root->right = tmp;
        cur++;
        build_tree(ar, len, root->right);
    } else cur++;

    if (root->left == NULL && root->right == NULL) ans++;

    return ;
}

int count_leaf(node *root) {
    if (root == NULL) return 0;
    
    //printf("node: %c\n", root->c);

    if (root->left == NULL && root->right == NULL) return 1;
    int ans = 0;
    if (root->left != NULL) ans += count_leaf(root->left);
    if (root->right != NULL) ans += count_leaf(root->right);

    return ans;
}

int main() {
    char ar[105] = {0};

    while (gets(ar) != NULL) {
        int len = strlen(ar);
        node *root = (node*)calloc(1, sizeof(node));
        if (len == 0) {
            printf("0\n");
            continue;
        }
            
        root->c = ar[0];
        cur = 1, ans = 0;
        build_tree(ar, len, root);
        //int ans = count_leaf(root);
        printf("%d\n", ans);
    }

    return 0;
}
