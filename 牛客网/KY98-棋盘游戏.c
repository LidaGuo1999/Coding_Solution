/* 问题描述： 有一个6*6的棋盘，每个棋盘上都有一个数值，现在又一个起始位置和终止位置，请找出一个从起始位置到终止位置代价最小的路径：     1、只能沿上下左右四个方向移动     2、总代价是没走一步的代价之和     3、每步（从a,b到c,d）的代价是c,d上的值与其在a,b上的状态的乘积     4、初始状态为1     每走一步，状态按如下公式变化：（走这步的代价%4）+1。
 *
 * 输入描述：每组数据一开始为6*6的矩阵，矩阵的值为大于等于1小于等于10的值，然后四个整数表示起始坐标和终止坐标。
 *
 * 输出描述：输出最小代价。
 */


#include <stdio.h>
#include <string.h>

int move(int matrix[7][7], int flag[7][7], int sx, int sy, int ex, int ey, int status) {
    if (sx == ex && sy == ey) {
        return 0;
    }

    flag[sx][sy] = 1;
    int ans[4] = {0}, cost = 0, ns = 0;
    for (int i = 0; i < 4; i++) ans[i] = 1000000000;
    if (sx > 0) {
        if (flag[sx-1][sy] == 0) {
            cost = status*matrix[sx-1][sy];
            ns = cost%4+1;
            ans[0] = cost+move(matrix, flag, sx-1, sy, ex, ey, ns);
        }
    }
    if (sx < 5) {
        if (flag[sx+1][sy] == 0) {
            cost = status*matrix[sx+1][sy];
            ns = cost%4+1;
            ans[1] = cost+move(matrix, flag, sx+1, sy, ex, ey, ns);
        }
    }
    if (sy > 0) {
        if (flag[sx][sy-1] == 0) {
            cost = status*matrix[sx][sy-1];
            ns = cost%4+1;
            ans[2] = cost+move(matrix, flag, sx, sy-1, ex, ey, ns);
        }
    }
    if (sy < 5) {
        if (flag[sx][sy+1] == 0) {
            cost = status*matrix[sx][sy+1];
            ns = cost%4+1;
            ans[3] = cost+move(matrix, flag, sx, sy+1, ex, ey, ns);
        }
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4-i-1; j++) {
            if (ans[j] > ans[j+1]) {
                int tmp = ans[j];
                ans[j] = ans[j+1];
                ans[j+1] = tmp;
            }
        }
    }

    //printf("%d %d: %d\n", sx, sy, ans[0]);
    flag[sx][sy] = 0;

    return ans[0];
}

int main() {
    int matrix[7][7], flag[7][7], sx, sy, ex, ey;
    while (scanf("%d", &matrix[0][0]) != EOF) {
        memset(flag, 0, sizeof(flag));
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 6; j++) {
                if (i != 0 || j != 0) scanf("%d", &matrix[i][j]);
            }

        }
        scanf("%d %d %d %d", &sx, &sy, &ex, &ey);

        int ans = move(matrix, flag, sx, sy, ex, ey, 1);

        printf("%d\n", ans);
    }

    return 0;
}
