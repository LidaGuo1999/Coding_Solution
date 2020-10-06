#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

void flat(unsigned a, int aa[]) {
    unsigned tmp = a;
    for (int i = 15; i >= 0; i--) {
        aa[i] = tmp&1;
        tmp = tmp >> 1;
    }
    return ;
}

void output(int s[]) {
    for (int i = 0; i < 16; i++) printf("%d ", s[i]);
    printf("\n");
}

int main() {
    unsigned int a, b;
    int aa[16] = {0}, bb[16] = {0};
    while (scanf("%u %u", &a, &b) != EOF) {
        int ans = 0;
        flat(a, aa), flat(b, bb);
        //output(aa), output(bb);
        for (int i = 0; i < 16; i++) {
            int flag = 1, pos = i;
            for (int j = 0; j < 16; j++) {
                if (aa[pos] != bb[j]) {
                    flag = 0;
                    break;
                }
                pos = (pos+1)%16;
            }
            if (flag == 1) {
                ans = 1;
                break;
            }
        }
        if (ans == 1) printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}
