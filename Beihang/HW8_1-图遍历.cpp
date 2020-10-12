

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

int selectSort(int nums[], int n) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            cnt++;
            if (nums[j] < nums[i]) swap(nums[j], nums[i]);
        }
    }
    return cnt;
}

int bubbleSort(int nums[], int n) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int flag = 0;
        for (int j = 0; j < n-i-1; j++) {
            cnt++;
            if (nums[j] > nums[j+1]) {
                swap(nums[j], nums[j+1]);
                flag++;
            }
        }
        if (flag == 0) break;
    }
    return cnt;
}

int heapAdjust(int nums[], int start, int n) {
    int tmp = nums[start];
    int cur = 2*start+1, cnt = 0;

    while (cur < n) {
        if (cur+1 < n && nums[cur] < nums[cur+1]) {
            cur++;
        }
        cnt++;
        if (tmp >= nums[cur]) break;
        nums[(cur-1)/2] = nums[cur];
        cur = cur*2+1;
    }
    nums[(cur-1)/2] = tmp;
    return cnt;
