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

void floyd(int nv);
void dijkstra(int nv);
void prim(int nv, int ne);
void kruscal(int nv, int ne);
void sorting(int ne);
int unionSearch(int node);
void unionJoin(int v1, int v2);

edge es[1000];
cedge closest[1000];
int pre[1000];
int matrix[1000][1000], change[1000][1000];

int main() {
    int nv, ne;
    int start, end, weight;
    memset(matrix, 127, sizeof(matrix));
    memset(change, 127, sizeof(change));

    scanf("%d %d", &nv, &ne);
    for (int i = 0; i < ne; i++) {
        scanf("%d %d %d", &start, &end, &weight);
        es[i].v1 = start, es[i].v2 = end, es[i].weight = weight;

        matrix[start][end] = weight;
        change[start][end] = weight;
    }
    sorting(ne);
    printf("\n");
    printf("kruscal:\n");
    kruscal(nv, ne);
    printf("prim:\n");
    prim(nv, ne);
    
    printf("dijkstra:\n");
    dijkstra(nv);
    printf("floyd:\n");
    floyd(nv);

    
    return 0;
}

void floyd(int nv) {
    //int change[1000][1000];
    //memcpy(change, matrix, sizeof(matrix));
    //for (int i = 1; i <= nv; i++) printf("%d ", change[1][i]);
    printf("max:%d\n", INT_MAX);
    for (int i = 1; i <= nv; i++) {
        for (int j = 1; j <= nv; j++) {
            for (int k = 1; k <= nv; k++) {
                if (change[j][i] < 10000 && change[i][k] < 10000 && change[j][k] > change[j][i]+change[i][k]) {
                    change[j][k] = change[j][i]+change[i][k];
                }
                //printf("j:%d k:%d dis:%d\n", j, k, change[j][k]);
            }
        }
    }
    for (int i = 1; i <= nv; i++) printf("%d ", change[1][i]);
    printf("\n");
    return ;
}

void dijkstra(int nv) {
    int *dis, *flag;
    dis = (int*)calloc(nv+1, sizeof(int)), flag = (int*)calloc(nv+1, sizeof(int));
    memset(dis, 127, (nv+1)*sizeof(int));
    memset(flag, 0, (nv+1)*sizeof(int));
    dis[1] = 0, flag[1] = 1;
    for (int i = 1; i <= nv; i++) {
        dis[i] = matrix[1][i];
    }
    
    for (int i = 0; i < nv-1; i++) {
        int k = 0;
        for (int j = 1; j <= nv; j++) {
            if (!flag[j] && dis[j] < dis[k]) {
                k = j;
            }
        } 
        if (k == 0) break;
        flag[k] = 1;
        for (int j = 1; j <= nv; j++) {
            if (!flag[j] && dis[k]+matrix[k][j] < dis[j]) {
                dis[j] = dis[k]+matrix[k][j];
            }
        }
    }
    for (int i = 1; i <= nv; i++) {
        printf("%d ", dis[i]);
    }
    printf("\n");
    return ;
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
