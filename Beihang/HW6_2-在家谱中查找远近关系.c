#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node {
    char name[25];
    int layer;
} node;

int main() {
    FILE *fp = fopen("in.txt", "r");
    int n;
    fscanf(fp, "%d", &n);
    char parent[25], child1[25], child2[25];
    for (int i = 0; i < n; i++) {
        scanf("%s %s %s", parent, child1, child2);
    }
}
