
#include <iostream>
#include <cstring>
using namespace std;

int isRelated(int num) {
    if (num%7 == 0) return 1;
    int tmp = num;
    while (tmp > 0) {
        if (tmp%10 == 7) return 1;
        tmp /= 10;
    }
    return 0;
}

int main() {
    int n = 0, ans = 0;
    while (scanf("%d", &n) != EOF) {
        ans = 0;
        for (int i = 1; i <= n; i++) {
            if (isRelated(i) == 0) ans += i*i;
        }
        printf("%d\n", ans);
    }

    return 0;
}

