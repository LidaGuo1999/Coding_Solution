#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node *left, *right;
} node;

node* build_tree(int nums[1000], int n) {
    if (n == 0) return NULL;
    node *root = (node*)calloc(1, sizeof(node));
    root->val = nums[1];
    node *tra = root;
    node *s[1000];
    int top = 0, bottom = 0;

    for (int i = 2; i <= n; i++) {
        if (tra->left == NULL) {
            node *tmp = (node*)calloc(1, sizeof(node));
            tmp->val = nums[i];
            tra->left = tmp;
            s[bottom++] = tmp;
        } else if (tra->right == NULL) {
            node *tmp = (node*)calloc(1, sizeof(node));
            tmp->val = nums[i];
            tra->right = tmp;
            s[bottom++] = tmp;
        } 

        if (tra->left != NULL && tra->right != NULL) tra = s[top++];
    }

    return root;
}

void pre_traverse(node *root) {
    node *s[1000];
    int top = -1;
    node *tra = root;

    if (root == NULL) return ;

    s[++top] = tra;
    while (top > -1) {
        tra = s[top--];
        printf("%d ", tra->val);
        if (tra->right != NULL) s[++top] = tra->right;
        if (tra->left != NULL) s[++top] = tra->left;
    }

    return ;
}

void mid_traverse(node *root) {
    if (root == NULL) return ;

    node *s[1000];
    int top = -1;
    node *tra = root;

    while (tra != NULL || top > -1) {
        while (tra != NULL) {
            s[++top] = tra;
            tra = tra->left;
        }
        
        tra = s[top--];
        printf("%d ", tra->val);
        tra = tra->right;
    }
    return ;
}

void post_traverse(node *root) {
    node *s1[1000];
    int top = -1;
    int s2[1000] = {0};
    int cnt = 0;
    node *tra = root;

    if (root == NULL) return ;

    s1[++top] = tra;
    while (top > -1) {
        tra = s1[top--];
        s2[cnt++] = tra->val;
        if (tra->left != NULL) s1[++top] = tra->left;
        if (tra->right != NULL) s1[++top] = tra->right;
    }

    for (int i = cnt-1; i >= 0; i--) printf("%d ", s2[i]);

    return ;
}

int main() {
    int nums[1000] = {0}, n = 0;
    for (int i = 1; scanf("%d", &nums[i]) != EOF; i++) n++;
    
    //printf("Here!\n");
    node *root = build_tree(nums, n);
    pre_traverse(root);
    printf("\n");
    mid_traverse(root);
    printf("\n");
    post_traverse(root);
    printf("\n");

    return 0;
}
