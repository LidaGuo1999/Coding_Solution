
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

typedef struct dis {
    long long q, r;
} dis;

int comp(dis d1, dis d2) {
    if (d1.q == -1) {
        if (d2.q == -1) return 0;
        else return 1;
    } else if (d2.q == -1) {
        return -1;
    } else {
        if (d1.q != d2.q) {
            if (d1.q > d2.q) return 1;
            else return -1;
        } else {
            if (d1.r > d2.r) return 1;
            else if (d1.r == d2.r) return 0;
            else if (d1.r < d2.r) return -1;
        }
    }
    return 0;
}

void dijkstra(int n, dis d[][105], dis result[]) {
    int flag[105] = {0};
    dis closest[105];
    memset(closest, 0, sizeof(closest));
    for (int i = 0; i < n; i++) {
        result[i].q = -1, result[i].r = -1;
    }
    flag[0] = 1;
    for (int i = 1; i < n; i++) {
        closest[i] = d[i][0];
    }

    for (int i = 1; i < n; i++) {
        int pos = -1;
        dis cur_min;
        cur_min.q = -1, cur_min.r = -1;
        for (int j = 0; j < n; j++) {
            if (flag[j] == 0 && comp(closest[j], cur_min) == -1) {
                cur_min = closest[j], pos = j;
            }
        }
        if (pos != -1) {
            flag[pos] = 1;
            result[pos] = closest[pos];
            for (int j = 0; j < n; j++) {
                if (flag[j] == 0) {
                    dis tmp;
                    tmp.q = closest[pos].q+d[j][pos].q, tmp.r = closest[pos].r+d[j][pos].r;
                    if (tmp.r >= 100000) {
                        tmp.r -= 100000;
                        tmp.q++;
                    }

                    if (comp(tmp, closest[j]) == -1) {
                        closest[j] = tmp;
                    }
                } else {
                    continue;
                }
            }
        } else {
            break;
        }
    }
    return ;
}

int main() {
    int n, m, v1, v2;
    dis d[105][105], result[105];
    memset(d, 0, sizeof(d)), memset(result, 0, sizeof(result));
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                d[i][j].q = -1, d[i][j].r = -1;
            }
        }
    }

    long long a = 0, b = 1;
        for (int i = 0; i < m; i++) {
            scanf("%d %d", &v1, &v2);
        dis tmp;
        tmp.q = a, tmp.r = b;
        if (comp(tmp, d[v1][v2]) == -1) {
            d[v1][v2] = tmp, d[v2][v1] = tmp;
        } else {

        }

        b *= 2;
        if (b >= 100000) {
            b -= 100000;
            a = a*2+1;
        } else {
            a = a*2;
        }
    }
    dijkstra(n, d, result);
    for (int i = 1; i < n; i++) {
        if (result[i].q != -1) {
            printf("%lld\n", result[i].r);
        } else {
            printf("-1\n");
        }
    }

    return 0;
}
