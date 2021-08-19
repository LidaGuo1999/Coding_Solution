/* 问题描述：有 N 个花园，按从 1 到 N 标记。在每个花园中，你打算种下四种花之一。

paths[i] = [x, y] 描述了花园 x 到花园 y 的双向路径。

另外，没有花园有 3 条以上的路径可以进入或者离开。

你需要为每个花园选择一种花，使得通过路径相连的任何两个花园中的花的种类互不相同。

以数组形式返回选择的方案作为答案 answer，其中 answer[i] 为在第 (i+1) 个花园中种植的花的种类。花的种类用  1, 2, 3, 4 表示。保证存在答案
 *
 * 思路梳理：
 * 1、这是一个着色问题，我们注意到花有4种颜色，且没有花园有3条以上的路径离开，说明任何一个花园在任何时刻着色，都一定存在一种颜色邻接的花园没有；
 * 2、所以这就是一个贪心算法，遍历所有的节点，选择邻接节点中没有出现过的颜色涂上即可；
 * 3、由于边比较少，所以采用邻接表来进行存储即可；
 *
 * 评测结果：
 * 180ms，14.29%；15.2MB，96.43；
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

typedef struct garden {
    int color;
    int neighbour[3];
} garden;

void insert(garden gs[], int start, int end) {
    garden tmp = gs[start];
    for (int i = 0; i < 3; i++) {
        if (tmp.neighbour[i] == 0) {
            tmp.neighbour[i] = end;
            break;
        }
    }
    gs[start] = tmp;
    return ;
}

int distri(garden gs[], int pos) {
    int flag[5] = {0};
    garden tmp = gs[pos];
    for (int i = 0; i < 3; i++) {
        flag[gs[tmp.neighbour[i]].color]++;
    }
    for (int i = 1; i <= 4; i++) {
        if (flag[i] == 0) {
            tmp.color = i;
            break;
        }
    }
    gs[pos] = tmp;
    return gs[pos].color;
}

int* gardenNoAdj(int N, int** paths, int pathsSize, int* pathsColSize, int* returnSize){
    garden gs[10005];
    int *ans = calloc(N, sizeof(int));
    memset(gs, 0, sizeof(gs));
    for (int i = 0; i < pathsSize; i++) {
        int *p = paths[i];
        insert(gs, p[0], p[1]);
        insert(gs, p[1], p[0]);
    }
    for (int i = 1; i <= N; i++) {
        ans[i-1] = distri(gs, i);
    }
    *returnSize = N;
    return ans;
}
