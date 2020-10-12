
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct edge {
    int v1, v2;
} edge;

typedef struct vertex {
    vector<int> neibour;
} vertex;

void dfs(int cur, int end, edge es[1005], vertex vs[1005], int n, int e, int flag[1005], int result[1005], int cnt) {
    flag[cur] = 1;
    if (cur == end) {
        for (int i = 0; i < cnt; i++) {
            if (i == 0) printf("%d", result[i]);
            else printf(" %d", result[i]);
        }
        printf("\n");
    } else {
        int len = (int)vs[cur].neibour.size();
        for (int i = 0; i < len; i++) {
            int oppo = -1;
            if (es[vs[cur].neibour[i]].v1 == cur) oppo = es[vs[cur].neibour[i]].v2;
            else oppo = es[vs[cur].neibour[i]].v1;

            if (flag[oppo] == 0) {
                result[cnt] = vs[cur].neibour[i];
                cnt++;
                dfs(oppo, end, es, vs, n, e, flag, result, cnt);
                cnt--;
            } else {
                continue;
            }
        }
    }
    flag[cur] = 0;

    return ;
}

void output(int start, int end, edge es[1005], vertex vs[1005], int n, int e) {
    int flag[1005] = {0}, result[1005] = {0};
    dfs(start, end, es, vs, n, e, flag, result, 0);
}

int main() {
    int n, e;
    edge es[1005];
    vertex vs[1005];
    memset(es, 0, sizeof(es)), memset(vs, 0, sizeof(vs));
    scanf("%d %d", &n, &e);
    for (int i = 0; i < e; i++) {
        int id, v1, v2;
        scanf("%d %d %d", &id, &v1, &v2);
        es[id].v1 = v1, es[id].v2 = v2;
        vs[v1].neibour.push_back(id), vs[v2].neibour.push_back(id);
    }
    for (int i = 0; i < n; i++) {
        int len = (int)vs[i].neibour.size();
        for (int j = 0; j < len; j++) {
            for (int k = 0; k < len-j-1; k++) {
                if (vs[i].neibour[k] > vs[i].neibour[k+1]) swap(vs[i].neibour[k], vs[i].neibour[k+1]);
            }
        }
    }
    if (n > 0) {
        output(0, n-1, es, vs, n, e);
    }

    return 0;
}
