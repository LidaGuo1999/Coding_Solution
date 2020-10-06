
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
}

int heapSort(int nums[], int n) {
    if (n == 0 || n == 1) return 0;
    int last = (n-2)/2, cnt = 0;

    for (int i = last; i >= 0; i--) {
        cnt += heapAdjust(nums, i, n);
    }

    for (int i = 0; i < n; i++) {
        swap(nums[0], nums[n-1-i]);
        cnt += heapAdjust(nums, 0, n-1-i);
    }
    return cnt;
}

int mergeSort(int nums[], int left, int right) {
    int cnt = 0;
    if (left >= right) return 0;
    if (right - left == 1) return 0;
    int mid = left+(right-left)/2;
    cnt += mergeSort(nums, left, mid);
    cnt += mergeSort(nums, mid, right);

    int tmp[1000] = {0}, pos = left;
    int i = left, j = mid;
    while (i < mid && j < right) {
        cnt++;
        if (nums[i] <= nums[j]) {
            tmp[pos++] = nums[i];
            i++;
        } else {
            tmp[pos++] = nums[j];
            j++;
        }
    }
    while (i < mid) {
        tmp[pos++] = nums[i];
        i++;
    }
    while (j < right) {
        tmp[pos++] = nums[j];
        j++;
    }
    for (int k = left; k < right; k++) {
        nums[k] = tmp[k];
    }
    return cnt;
}

int quickSort(int nums[], int left, int right) {
    int cnt = 0, last = left;
    if (left < right) {
        for (int i = left+1; i < right; i++) {
            cnt++;
            if (nums[i] < nums[left]) {
                swap(nums[++last], nums[i]);
            }
        }
        swap(nums[left], nums[last]);
        cnt += quickSort(nums, left, last);
        cnt += quickSort(nums, last+1, right);
    }

    return cnt;
}

int main() {
    int n = 0, mode = 0, nums[1000] = {0}, cnt = 0;
    scanf("%d %d", &n, &mode);
    for (int i = 0; i < n; i++) scanf("%d", &nums[i]);
    if (mode == 1) {
        cnt = selectSort(nums, n);
    } else if (mode == 2) {
        cnt = bubbleSort(nums, n);
    } else if (mode == 3) {
        cnt = heapSort(nums, n);
    } else if (mode == 4) {
        cnt = mergeSort(nums, 0, n);
    } else if (mode == 5) {
        cnt = quickSort(nums, 0, n);
    }

    for (int i = 0; i < n; i++) printf("%d ", nums[i]);
    printf("\n");
    printf("%d\n", cnt);

    return 0;
}
