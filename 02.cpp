#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int cal_dis(int a, int b) {
    int tmp = a^b, count = 0;
    while (tmp != 0) {
        if ((tmp & 1) == 1) count++;
        tmp = tmp >> 1;
    }
    return count;
}

int main() {
    int n, cur_max = 0;
    cin >> n;
    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++) cin >> nums[i];

    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            cur_max = max(cur_max, cal_dis(nums[i], nums[j]));
        }
    }

    cout << cur_max << endl;

    return 0;
}