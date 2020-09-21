/* 问题描述：一根长度为1米的木棒上有若干只蚂蚁在爬动。它们的速度为每秒一厘米或静止不动，方向只有两种，向左或者向右。如果两只蚂蚁碰头，则它们立即交换速度并继续爬动。三只蚂蚁碰头，则两边的蚂蚁交换速度，中间的蚂蚁仍然静止。如果它们爬到了木棒的边缘（0或100厘米处）则会从木棒上坠落下去。在某一时刻蚂蚁的位置各不相同且均在整数厘米处（即1，2，3，…99厘米），有且只有一只蚂蚁A速度为0，其他蚂蚁均在向左或向右爬动。给出该时刻木棒上的所有蚂蚁位置和初始速度，找出蚂蚁A从此时刻到坠落所需要的时间。
 *
 * 输入描述：第一行包含一个整数表示蚂蚁的个数N（2<=N<=99），之后共有N行，每一行描述一只蚂蚁的初始状态。每个初始状态由两个整数组成，中间用空格隔开，第一个数字表示初始位置厘米数P（1<=P<=99），第二个数字表示初始方向,-1表示向左，1表示向右，0表示静止。
 *
 * 输出描述：蚂蚁A从开始到坠落的时间。若不会坠落，输出“Cannot fall!”
 */


#include <stdio.h>
#include <string.h>

typedef struct ant {
    int pos;
    int dire;
} ant;

int main() {
    int n, left[100] = {0}, right[100] = {0}, ap = -1, li = 0, ri = 0, asi = 0;
    ant as[100];
    memset(as, 0, sizeof(as));
    memset(left, 0, sizeof(left));
    memset(right, 0, sizeof(right));
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {

        int p, d;
        scanf("%d %d", &p, &d);
        if (d == 1) {
            right[ri++] = p;
        } else if (d == -1) {
            left[li++] = p;
        }
        if (d != 0) {
            as[asi].pos = p;
            as[asi].dire = d;
            asi++;
        } else {
            ap = p;
        }
    }

    for (int i = 0; i < li; i++) {
        for (int j = 0; j < li-i-1; j++) {
            if (left[j] > left[j+1]) {
                int tmp = left[j];
                left[j] = left[j+1];
                left[j+1] = tmp;
            }
        }
    }
    for (int i = 0; i < li; i++) {
        left[i] -= 0;
    }

    for (int i = 0; i < ri; i++) {
        for (int j = 0; j < ri-i-1; j++) {
            if (right[j] < right[j+1]) {
                int tmp = right[j];
                right[j] = right[j+1];
                right[j+1] = tmp;
            }
        }
    }
    for (int i = 0; i < ri; i++) {
        right[i] = 100-right[i];
    }

    for (int i = 0; i < asi; i++) {
        for (int j = 0; j < asi-i-1; j++) {
            if (as[j].pos > as[j+1].pos || (as[j].pos == as[j+1].pos && as[j].dire < as[j+1].dire)) {
                ant tmp = as[j];
                as[j] = as[j+1];
                as[j+1] = tmp;
            }
        }
    }

    int order = n;
    for (int i = 0; i < asi; i++) {
        if (ap < as[i].pos) {
            order = i+1;
            break;
        } else if (ap > as[i].pos) {
            continue;
        } else {
            if (as[i].dire == 1) {
                continue;
            } else {
                order = i+1;
                break;
            }
        }
    }

    int ltime = 1000000000, rtime = 1000000000;
    if (li >= order) ltime = left[order-1];
    if (ri >= (n-order+1)) rtime = right[n-order];

    if (ltime == 1000000000 && rtime == 1000000000) printf("Cannot fall!\n");
    else printf("%d\n", ltime<rtime ? ltime : rtime);

    return 0;

}
