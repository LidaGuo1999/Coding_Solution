#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node *left, *right;
} node;

void insertNode(node *root, int val) {
    if (root == NULL) {
        root = (node*)calloc(1, sizeof(node));
        root->val = val;
        return ;
    } else {
        if (val < root->val) {
            if (root->left == NULL) {
                node *tmp = (node*)calloc(1, sizeof(node));
                tmp->val = val;
                root->left = tmp;
                return ;
            } else {
                insertNode(root->left, val);
                return ;
            }
        } else {
            if (root->right == NULL) {
                node *tmp = (node*)calloc(1, sizeof(node));
                tmp->val = val;
                root->right = tmp;
                return ;
            } else {
                insertNode(root->right, val);
                return ;
            }
        }
    }
    return ;
}

void preOrder(node *root) {
    if (root == NULL) return ;
    
    printf("%d ", root->val);
    preOrder(root->left);
    preOrder(root->right);

    return ;
}

void midOrder(node *root) {
    if (root == NULL) return ;

    midOrder(root->left);
    printf("%d ", root->val);
    midOrder(root->right);

    return ;
}

void postOrder(node *root) {
    if (root == NULL) return ;

    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->val);

    return ;
}

void layerOrder(node *root) {
    if (root == NULL) return ;

    node *q[10005];
    int top = 0, bottom = 0;
    q[bottom++] = root;
    while (top < bottom) {
        node *tmp = q[top++];
        printf("%d ", tmp->val);
        if (tmp->left != NULL) q[bottom++] = tmp->left;
        if (tmp->right != NULL) q[bottom++] = tmp->right;
    }

    return ;
}

int main() {
    int ar[10005] = {0};
    while (scanf("%d", &ar[0]) != EOF) {
        int i = 1;
        while (1) {
            char c = getchar();
            if (c == '\n' || c == EOF) break;
            scanf("%d", &ar[i++]);
        }
        
        //printf("len: %d\n", i);
        node *root;
        if (i >= 1) {
            root = (node*)calloc(1, sizeof(node));
            root->val = ar[0];
        } else root = NULL;

        for (int j = 1; j < i; j++) {
            insertNode(root, ar[j]);
        }

        preOrder(root);
        printf("\n");
        midOrder(root);
        printf("\n");
        postOrder(root);
        printf("\n");
        layerOrder(root);
        printf("\n");

        memset(ar, 0, sizeof(ar));
    }

    return 0;
}
