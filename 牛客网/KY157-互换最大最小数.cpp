
#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

int main() {
    int n, nums[25] = {0};
    while (scanf("%d", &n) != EOF) {
        int cur_max = 0, cur_min = 0, pos_max = -1, pos_min = -1, flag_max = 0, flag_min = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &nums[i]);
            if (flag_max == 0 && flag_min == 0) {
                cur_max = nums[i], cur_min = nums[i];
                pos_max = i, pos_min = i;
            } else {
                if (nums[i] > cur_max) {
                    cur_max = nums[i], pos_max = i;
                }
                if (nums[i] < cur_min) {
                    cur_min = nums[i], pos_min = i;
                }
            }
            flag_max++, flag_min++;
        }

        int tmp = nums[pos_max];
        nums[pos_max] = nums[pos_min];
        nums[pos_min] = tmp;

        for (int i = 0; i < n; i++) printf("%d ", nums[i]);
        printf("\n");
    }

    return 0;
}
