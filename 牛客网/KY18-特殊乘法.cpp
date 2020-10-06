
#include <iostream>

using namespace std;

int main() {
    int a = 0, b = 0, q = 0, r = 0, aa[10] = {0}, bb[10] = {0}, cnta = 0, cntb = 0, ans = 0;
    while (scanf("%d %d", &a, &b) != EOF) {
        q = 0, r = 0, cnta = 0, cntb = 0, ans = 0;
        memset(aa, 0, sizeof(aa)), memset(bb, 0, sizeof(bb));
        q = a;
        while (q > 0) {
            aa[cnta++] = q%10;
            q = q/10;
        }
        q = b;
        while (q > 0) {
            bb[cntb++] = q%10;
            q = q/10;
        }

        for (int i = 0; i < cnta; i++) {
            for (int j = 0; j < cntb; j++) {
                ans += aa[i]*bb[j];
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}


