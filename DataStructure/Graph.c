#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

typedef struct edge {
    int v1, v2;
    int weight;
} edge;

typedef struct cedge {
    int v;
    int weight;
} cedge;

void prim(int nv, int ne);
void kruscal(int nv, int ne);
void sorting(int ne);
int unionSearch(int node);
void unionJoin(int v1, int v2);

edge es[1000];
cedge closest[1000];
int pre[1000];
int matrix[1000][1000];

int main() {
    int nv, ne;
    int start, end, weight;
    memset(matrix, 127, sizeof(matrix));

    scanf("%d %d", &nv, &ne);
    for (int i = 0; i < ne; i++) {
        scanf("%d %d %d", &start, &end, &weight);
        es[i].v1 = start, es[i].v2 = end, es[i].weight = weight;

        matrix[start][end] = weight;
        matrix[end][start] = weight;
    }
    sorting(ne);
    printf("\n");
    printf("kruscal:\n");
    kruscal(nv, ne);
    printf("prim:\n");
    prim(nv, ne);
    
    return 0;
}

void prim(int nv, int ne) {
    closest[0].weight = 0;
    for (int i = 1; i < nv; i++) {
        closest[i].v = 0;
        closest[i].weight = matrix[i][0];
    }
    
    for (int i = 1; i < nv; i++) {
        int cur_min = INT_MAX;
        
        int k = -1;
        for (int j = 0; j < nv; j++) {
            if (closest[j].weight != 0 && closest[j].weight < cur_min) {
                cur_min = closest[j].weight;
                k = j;
            }
        }

        printf("%d %d %d\n", k, closest[k].v, closest[k].weight);
        closest[k].weight = 0;

        for (int j = 0; j < nv; j++) {
            if (matrix[j][k] < closest[j].weight) {
                closest[j].weight = matrix[j][k];
                closest[j].v = k;
            }
        }
    }
    return ;
}

void kruscal(int nv, int ne) {
    for (int i = 0; i < nv; i++) pre[i] = i;
    
    int v1, v2, root1, root2;
    for (int i = 0; i < ne; i++) {
        v1 = es[i].v1, v2 = es[i].v2;
        root1 = unionSearch(v1), root2 = unionSearch(v2);
        if (root1 != root2) {
            pre[root1] = root2;
            printf("%d %d %d\n", v1, v2, es[i].weight);
        } else {
            continue;
        }
    }
    return ;
}

void sorting(int ne) {
    for (int i = 0; i < ne; i++) {
        for (int j = 0; j < ne-i-1; j++) {
            if (es[j].weight > es[j+1].weight) {
                edge tmp = es[j];
                es[j] = es[j+1];
                es[j+1] = tmp;
            }
        }
    }
    return ;
}

int unionSearch(int v) {
    int root = v, son = v;
    while (root != pre[root]) {
        root = pre[root];
    }

    while (son != root) {
        int tmp = pre[son];
        pre[son] = root;
        son = tmp;
    }

    return root;
}

void unionJoin(int v1, int v2) {
    int root1 = unionSearch(v1), root2 = unionSearch(v2);
    if (root1 != root2) {
        pre[root1] = root2;
    }
    return ;
}
