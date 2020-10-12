
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int largestFactor(int a, int b) {
    int n1 = 0, n2 = 0;
    if (a > b) {
        n1 = a, n2 = b;
    } else {
        n1 = b, n2 = a;
    }
    while (n2 > 0) {
        int tmp = n1%n2;
        if (tmp > n2) {
            n1 = tmp;
        } else {
            n1 = n2, n2 = tmp;
        }
    }
    return n1;
}

int main() {
    int n, nums[1005] = {0};
    while (scanf("%d", &n) != EOF) {
        if (n == 0) break;
        for (int i = 0; i < n; i++) {
            scanf("%d", &nums[i]);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n-i-1; j++) {
                if (nums[j] > nums[j+1]) {
                    int tmp = nums[j];
                    nums[j] = nums[j+1];
                    nums[j+1] = tmp;
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                if (largestFactor(nums[i], nums[j]) == 1) ans++;
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}
