#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node {
    char word[51];
    int cnt;
    struct node *left, *right;
} node;

void transform(char w[]) {
    int len = strlen(w);
    for (int i = 0; i < len; i++) {
        if (w[i] >= 'A' && w[i] <= 'Z') {
            w[i] += 'a'-'A';
        }
    }
}

node* insertNode (node *root, char w[]) {
    node *tmp;
    if (root == NULL) {
        tmp = (node*)calloc(1, sizeof(node));
        strcpy(tmp->word, w);
        tmp->cnt = 1;
        return tmp;
    } else {
        if (strcmp(root->word, w) == 0) {
            root->cnt++;
            return root;
        } else if (strcmp(root->word, w) > 0) {
            root->left = insertNode(root->left, w);
            return root;
        } else {
            root->right = insertNode(root->right, w);
            return root;
        }
    }
    return root;
}

void output(node *root) {
    if (root == NULL) return ;

    output(root->left);
    printf("%s %d\n", root->word, root->cnt);
    output(root->right);

    return ;
}

node* handle_line(char line[], node* root) {
    transform(line);
    int len = strlen(line);
    char tmp[51] = {0};
    int start, end, cnt = 0;
    for (int i = 0; i < len; ) {
        memset(tmp, 0, sizeof(tmp));
        cnt = 0;
        if (line[i] >= 'a' && line[i] <= 'z') {
            for (int j = i; j < len && (line[j] >= 'a' && line[j] <= 'z'); j++) {
                tmp[cnt++] = line[j];
                i++;
            }
            root = insertNode(root, tmp);
        } else {
            i++;
        }
    }
    return root;
}

int main() {
    FILE *fp = fopen("article.txt", "r");
    char w[51] = {0}, line[1005] = {0};
    node *root = NULL;
    while (fgets(line, 1005, fp) != NULL) {
        root = handle_line(line, root);
    }
    printf("handle finish!\n");

    if (root != NULL) {
        printf("%s ", root->word);
        if (root->right != NULL) {
            printf("%s ", root->right->word);
            if (root->right->right != NULL) {
                printf("%s\n", root->right->right->word);
            } else {
                printf("\n");
            }
        } else {
            printf("\n");
        }
    }

    output(root);

    fclose(fp);

    return 0;
}
