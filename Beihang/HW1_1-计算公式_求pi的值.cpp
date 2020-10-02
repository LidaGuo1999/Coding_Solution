#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

int main() {
    double e = 0.0, last = 0.0, cur = 1.0;
    double up = 1.0, down = 3.0;
    int cnt = 1;
    scanf("%lf", &e);

    /*while (2.0*cur-2.0*last >= e) {
        last = cur;
        double add = up/down;
        cur += add;
        cnt++;
        up *= cnt;
        down *= (2*cnt+1);
    }*/

    do {
        last = cur;
        double add = up/down;
        cur += add;
        cnt++;
        up *= cnt;
        down *= (2*cnt+1);
    } while (2.0*cur-2.0*last >= e);

    printf("%d %.7lf\n", cnt, 2.0*cur);

    return 0;
}
