#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node {
    char name[25];
    struct node *left, *right;
    int layer;
} node;

node *ancient = NULL;

node* insertNode(node *root, char parent[25], char child1[25], char child2[25]) {
    node *head = root;
    if (root == NULL) {
        head = (node*)calloc(1, sizeof(node));
        strcpy(head->name, parent);
        head->layer = 0;   
    }

    if (strcmp(head->name, parent) == 0) {
        if (strcmp(child1, "NULL") != 0) {
            node *left = (node*)calloc(1, sizeof(node));
            strcpy(left->name, child1);
            left->layer = head->layer+1;
            head->left = left;
        }
        if (strcmp(child2, "NULL") != 0) {
            node *right = (node*)calloc(1, sizeof(node));
            strcpy(right->name, child2);
            right->layer = head->layer+1;
            head->right = right;
        }
    } else {
        if (head->left != NULL) head->left = insertNode(head->left, parent, child1, child2);
        if (head->right != NULL) head->right = insertNode(head->right, parent, child1, child2);
    }

    return head;
}

node* find(node *root, char f1[25]) {
    if (root == NULL) return NULL;
    if (strcmp(root->name, f1) == 0) return root;

    node *left = find(root->left, f1);
    node *right = find(root->right, f1);

    if (left != NULL) return left;
    else return right;
}

int nearestParent(node *root, char f1[25], char f2[25]) {
    if (ancient != NULL) return 0;
    if (root == NULL) return 0;
    int left = 0, right = 0, total = 0;
    
    left = nearestParent(root->left, f1, f2);
    right = nearestParent(root->right, f1, f2);
    if (strcmp(root->name, f1) == 0 || strcmp(root->name, f2) == 0) total = left+right+1;
    else total = left+right;
    //printf("name: %s total: %d\n", root->name, total);
    
    if (total == 2 && ancient == NULL) ancient = root;
    return total;
}

int main() {
    FILE *fp = fopen("in.txt", "r");
    int n;
    fscanf(fp, "%d", &n);
    node *root = NULL;
    char parent[25], child1[25], child2[25], find1[25], find2[25];
    for (int i = 0; i < n; i++) {
        fscanf(fp, "%s %s %s", parent, child1, child2);
        root = insertNode(root, parent, child1, child2);
    }
    //printf("Read file finish!\n");
    scanf("%s %s", find1, find2);
    node *c1 = find(root, find1);
    node *c2 = find(root, find2);
    //printf("%s: %d\n", c1->name, c1->layer);
    //printf("%s: %d\n", c2->name, c2->layer);

    if (c1->layer == c2->layer) {
        nearestParent(root, find1, find2);
        //if (ancient == NULL) printf("Fuck!\n");
        printf("%s %s %d\n", ancient->name, find1, c1->layer-ancient->layer);
        printf("%s %s %d\n", ancient->name, find2, c2->layer-ancient->layer);
    } else {
        if (c1->layer > c2->layer) {
            printf("%s %s %d\n", c1->name ,c2->name, c1->layer-c2->layer);
        } else {
            printf("%s %s %d\n", c2->name, c1->name, c2->layer-c1->layer);
        }
    }

    return 0;
}
