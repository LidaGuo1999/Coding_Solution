
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main() {
    double x;
    int n;
    while (scanf("%lf %d", &x, &n) != EOF) {
        double pre = x;
        for (int i = 0; i < n; i++) {
            pre = pre*2.0/3.0 + x/(3.0*pre*pre);
        }
        printf("%.6lf\n", pre);
    }

    return 0;
}
