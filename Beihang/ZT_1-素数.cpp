
#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

int main() {
    int n, mark[10005] = {0}, cnt = 0;
    while (scanf("%d", &n) != EOF) {
        cnt = 0;
        memset(mark, 0, sizeof(mark));
        for (int i = 2; i < n; i++) {
            if (mark[i] == 0) {
                mark[i] = 1;

                if (i%10 == 1) {
                    if (cnt == 0) {
                        printf("%d", i);
                    } else {
                        printf(" %d", i);
                    }
                    cnt++;
                }

                int j = i;
                while (j < n) {
                    mark[j] = 1;
                    j += i;
                }
            } else {
                continue;
            }
        }
        if (cnt == 0) printf("-1");
        printf("\n");
    }

    return 0;
}
