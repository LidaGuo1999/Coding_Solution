/* 问题描述：给你一串路径，譬如： a\b\c a\d\e b\cst d\ 你把这些路径中蕴含的目录结构给画出来，子目录直接列在父目录下面，并比父目录向右缩一格，就像这样： a   b     c   d      e b   cst d 同一级的需要按字母顺序排列，不能乱。
 *
 * 输入描述：每个测试案例第一行为一个正整数n（n<=10）表示有n个路径，当n为0时，测试结束，接下来有n行，每行有一个字串表示一个路径，长度小于50。
 *
 * 输出描述：输出目录结构，每一个测试样例的输出紧跟一个空行。
 */


#include <stdio.h>
#include <string.h>

typedef struct node {
    char name[50];
    struct node* child[50];
} node;

void sorting(char ar[10][55], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (strcmp(ar[j], ar[j+1]) > 0) {
                char tmp[55];
                strcpy(tmp, ar[j]);
                strcpy(ar[j], ar[j+1]);
                strcpy(ar[j+1], tmp);
            }
        }
    }

    return ;
}

node* build_tree(node *root, char s[55]) {
    int cnt = 0, ncnt = 0;
    char name[50] = {0};
    root = NULL;
    node *pre = root;
    while (1) {
        if (s[cnt] == '\\' || s[cnt] == 0) {
            if (strlen(name) == 0) break;
            node *tmp = (node*)malloc(sizeof(node));
            strcpy(tmp->name, name);
            if (pre == NULL) {
                pre = tmp;
                root = tmp;
            } else {
                pre->child[0] = tmp;
                pre = pre->child[0];
            }
            memset(name, 0, sizeof(name));
            ncnt = 0;
        } else {
            name[ncnt++] = s[cnt];
        }
        if (s[cnt] == 0) break;
        cnt++;
    }

    return root;
}

node* insert_tree(node *root, char s[55]) {
    char name[50] = {0};
    int cnt = 0, ncnt = 0, layer = 0;
    node *tra = (node*)malloc(sizeof(node));
    tra->child[0] = root;
    while (1) {
        while (s[cnt] != '\\' && s[cnt] != 0) {
            name[ncnt++] = s[cnt++];
        }
        cnt++;
        if (strlen(name) == 0) {
            if (s[cnt] == 0) break;
            else continue;
        }

        int flag = 0, i;
        for (i = 0; tra->child[i] != NULL; i++) {
            if (strcmp(tra->child[i]->name, name) == 0) {
                flag = 1;
                tra = tra->child[i];
                break;
            }
        }
        if (flag == 0) {
            node *nnode = (node*)malloc(sizeof(node));
            strcpy(nnode->name, name);
            tra->child[i] = nnode;
            tra = tra->child[i];
        }

        ncnt = 0;
        memset(name, 0, sizeof(name));
    }

    return root;
}

void draw_tree(node* root, int layer) {
    if (root == NULL) return ;

    for (int i = 0; i < layer; i++) printf("  ");
    printf("%s", root->name);
    printf("\n");
    for (int i = 0; root->child[i] != NULL; i++) {
        draw_tree(root->child[i], layer+1);
    }


    return ;
}

void handle(char ar[10][55], int n) {
    node *root = NULL;
    for (int i = 0; i < n; i++) {
        char first[50] = {0};
        int cnt = 0;
        for (int j = 0; j < strlen(ar[i]); j++) {
            if (ar[i][j] == '\\') break;
            first[cnt++] = ar[i][j];
        }

        if (root == NULL) {
            root = build_tree(root, ar[i]);
        } else if (strcmp(root->name, first) != 0) {
            draw_tree(root, 0);
            root = build_tree(root, ar[i]);
        } else {
            root = insert_tree(root, ar[i]);
        }
    }
    draw_tree(root, 0);

    return ;
}

int main() {
    int n;
    char ar[10][55];
    while (scanf("%d", &n) != EOF) {
        if (n == 0) break;

        memset(ar, 0, sizeof(ar));
        for (int i = 0; i < n; i++) {
            scanf("%s", &ar[i]);
        }
        sorting(ar, n);

        handle(ar, n);
        printf("\n");
    }

    return 0;
}
