#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

int main() {
    int sa[1000000] = {0}, sb[1000000] = {0};
    int cnta = 0, cntb = 0, tmp;
    while (1) {
        scanf("%d", &tmp);
        if (tmp == -1) break;
        sa[cnta++] = tmp;
    }
    while (1) {
        scanf("%d", &tmp);
        if (tmp == -1) break;
        sb[cntb++] = tmp;
    }

    for (int i = 0; i < cnta; i++) {
        int flag = 0;
        for (int j = 0; j < cntb; j++) {
            if (sb[j] == sa[i]) {
                flag = 1;
                break;
            }
        }
        if (flag == 0) printf("%d ", sa[i]);
    }
    printf("\n");

    return 0;
}
