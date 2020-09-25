#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int pre[1000];

int unionSearch(int node) {
    int root = node;
    int son = pre[node];
    while (pre[root] != root) {
        root = pre[root];
    }
    
    while (son != root) {
        int tmp = pre[son];
        pre[son] = root;
        son = tmp;
    }
    return root;
}

void unionJoin(int n1, int n2) {
    int root1 = unionSearch(n1);
    int root2 = unionSearch(n2);
    if (root1 != root2) {
        pre[root1] = root2;
    }
    return ;
}

int main() {
    for (int i = 0; i < 1000; i++) pre[i] = i;
    
    printf("%d\n", unionSearch(3));
    unionJoin(3, 1);
    printf("%d %d\n", unionSearch(3), unionSearch(1));
    unionJoin(2, 3);
    printf("%d\n", unionSearch(2));
    unionJoin(1, 4);
    printf("%d %d %d\n", unionSearch(1), unionSearch(2), unionSearch(3));
    return 0;
}
