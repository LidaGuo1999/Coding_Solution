#include <iostream>

using namespace std;

int main() {
    double dif[10], gap = 0.01, tmp = 0.0, tmp2 = 0.0;
    scanf("%lf", &tmp);
    for (int i = 0; i < 8; i++) {
        scanf("%lf", &tmp2);
        dif[i] = tmp2-tmp;
        tmp = tmp2;
    }

    double gg = 0.0;
    for (int i = 0; i < 4; i++) {
        gg += (dif[i+4]-dif[i])/4.0/gap;
    }

    printf("%.2lf\n", gg/4.0/100.0);

    return 0;

}
