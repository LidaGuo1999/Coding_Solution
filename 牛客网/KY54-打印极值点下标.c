/* 问题描述：在一个整数数组上，对于下标为i的整数，如果它大于所有它相邻的整数， 或者小于所有它相邻的整数，则称为该整数为一个极值点，极值点的下标就是i。
 *
 * 输入描述：第一行是此数组的元素个数k(4<k<80)，第二行是k个整数，每两个整数之间用空格分隔。
 *
 * 输出描述：每个案例输出为n行：每行对应于相应数组的所有极值点下标值，下标值之间用空格分隔。
 */


#include <stdio.h>
#include <string.h>

void extreme(int nums[100], int k) {
    for (int i = 0; i < k; i++) {
        int flag = 1;
        if (i == 0) {
            if (nums[0] == nums[1]) flag = 0;
        } else if (i == k-1) {
            if (nums[k-1] == nums[k-2]) flag = 0;
        } else {
            if (nums[i] > nums[i-1] && nums[i] > nums[i+1]) flag = 1;
            else if (nums[i] < nums[i-1] && nums[i] < nums[i+1]) flag = 1;
            else flag = 0;
        }

        if (flag == 1) printf("%d ", i);
    }
    printf("\n");
    return ;
}

int main() {
    int k, nums[100] = {0};
    while (scanf("%d", &k) != EOF) {
        memset(nums, 0, sizeof(nums));
        for (int i = 0; i < k; i++) scanf("%d", &nums[i]);

        extreme(nums, k);
    }

    return 0;
}
