
#include <stdio.h>
#include <math.h>

int main() {
    double x0, y0, z0, x1, y1, z1;
    while (scanf("%lf %lf %lf %lf %lf %lf", &x0, &y0, &z0, &x1, &y1, &z1) != EOF) {
        double pi = acos(-1);
        double r = sqrt(pow(x1-x0, 2.0) + pow(y1-y0, 2.0) + pow(z1-z0, 2.0));
        //printf("%lf\n", r);
        double v = 4.0*pi*pow(r, 3.0) / 3.0;
        printf("%.3lf %.3lf\n", r, v);
    }
    
    return 0;
}
