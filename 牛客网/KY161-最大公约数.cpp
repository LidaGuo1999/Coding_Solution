
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

int largestFactor(int n, int m) {
    int a = 0, b = 0;
    if (n > m) {
        a = n, b = m;
    } else {
        a = m, b = n;
    }

    while (b != 0) {
        int tmp = a%b;
        if (tmp > b) {
            a = tmp;
        } else {
            a = b, b = tmp;
        }
    }
    return a;
}

int main() {
    int n, m;
    while (scanf("%d %d", &n, &m) != EOF) {
        int ans = largestFactor(n, m);
        printf("%d\n", ans);
    }

    return 0;
}
