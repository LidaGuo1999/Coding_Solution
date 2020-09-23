#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

typedef struct node {
    int val;
    struct node *left, *right;
    int layer;
} node;

node* build_tree(int nums[1005], int len) {
    node *nhead = (node*)calloc(1, sizeof(node));
    nhead->val = INT_MAX;
    
    for (int i = 0; i < len; i++) {
        node *tra = nhead;
        while (1) {
            if (nums[i] < tra->val) {
                if (tra->left == NULL) {
                    node *tmp = (node*)calloc(1, sizeof(node));
                    tmp->val = nums[i];
                    tmp->layer = tra->layer+1;
                    tra->left = tmp;
                    break;
                } else {
                    tra = tra->left;
                    continue;
                }
            } else {
                if (tra->right == NULL) {
                    node *tmp = (node*)calloc(1, sizeof(node));
                    tmp->val = nums[i];
                    tmp->layer = tra->layer+1;
                    tra->right = tmp;
                    break;
                } else {
                    tra = tra->right;
                    continue;
                }
            }
        }
    }

    return nhead->left;
}

void output(node *root) {
    if (root == NULL) return ;
    if (root->left == NULL && root->right == NULL) {
        printf("%d %d\n", root->val, root->layer);
        return ;
    } else {
        if (root->left != NULL) {
            output(root->left);
        }
        if (root->right != NULL) {
            output(root->right);
        }
    }

    return ;
}

int main() {
    int nums[1005] = {0};
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    node *root = build_tree(nums, n);
    output(root);

    return 0;
}
