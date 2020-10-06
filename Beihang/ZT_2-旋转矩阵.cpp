
#include <iostream> 
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

int isSame(int m1[][10], int m2[][10], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (m1[i][j] != m2[i][j]) return 0;
        }
    }
    return 1;
}

void ro(int m1[10][10], int n) {
    int tmp[10][10];
    memcpy(tmp, m1, sizeof(tmp));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            m1[j][n-1-i] = tmp[i][j];
        }
    }
    return ;
}

int main() {
    int n, m1[10][10], m2[10][10], flag = 0;
    while (scanf("%d", &n) != EOF) {
        flag = 0;
        memset(m1, 0, sizeof(m1)), memset(m2, 0, sizeof(m2));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%d", &m1[i][j]);
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%d", &m2[i][j]);
            }
        }

        for (int i = 0; i < 4; i++) {
            if (isSame(m1, m2, n) == 1) {
                printf("%d\n", 90*i);
                flag = 1;
                break;
            } else {
                ro(m1, n);
            }
        }
        if (flag == 0) printf("-1\n");
    }
}
