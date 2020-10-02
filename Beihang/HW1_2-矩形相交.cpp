#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

int main() {
    int ax1, ay1, ax2, ay2, bx1, by1, bx2, by2, hflag = 0, vflag = 0, ans = 0;
    scanf("%d %d %d %d %d %d %d %d", &ax1, &ay1, &ax2, &ay2, &bx1, &by1, &bx2, &by2);
    if (ax1 > ax2) swap(ax1, ax2);
    if (ay1 < ay2) swap(ay1, ay2);
    if (bx1 > bx2) swap(bx1, bx2);
    if (by1 < by2) swap(by1, by2);

    if ((ax1 >= bx1 && ax1 < bx2) || (bx1 >= ax1 && bx1 < ax2)) {
        hflag = 1;
    }
    if ((ay1 <= by1 && ay1 > by2) || (by1 <= ay1 && by1 > ay2)) {
        vflag = 1;
    }

    if (hflag == 0 || vflag == 0) {
        ans = 0;
    } else {
        int tmp[4] = {ax1, ax2, bx1, bx2};
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4-i-1; j++) {
                if (tmp[j] > tmp[j+1]) {
                    swap(tmp[j], tmp[j+1]);
                }
            }
        }
        int tmp2[4] = {ay1, ay2, by1, by2};
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4-i-1; j++) {
                if (tmp2[j] > tmp2[j+1]) {
                    swap(tmp2[j], tmp2[j+1]);
                }
            }
        }

        ans = (tmp[2]-tmp[1]) * (tmp2[2]-tmp2[1]);
    }

    printf("%d\n", ans);

    return 0;
}
