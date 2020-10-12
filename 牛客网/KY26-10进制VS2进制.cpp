
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

void mergeSort(int total[], int start, int end) {
    if (start >= end) return ;
    int mid = start+(end-start)/2;
    mergeSort(total, start, mid);
    mergeSort(total, mid+1, end);

    int *tmp = (int*)calloc(end-start+1, sizeof(int));
    int left = start, right = mid+1, tpos = 0;
    while (left <= mid && right <= end) {
        if (total[left] <= total[right]) {
            tmp[tpos++] = total[left];
            left++;
        } else {
            tmp[tpos++] = total[right];
            right++;
        }
    }
    while (left <= mid) {
        tmp[tpos++] = total[left];
        left++;
    }
    while (right <= end) {
        tmp[tpos++] = total[right];
        right++;
    }

    for (int i = 0; i <= end-start; i++) {
        total[start+i] = tmp[i];
    }
    free(tmp);
    return ;
}

int main() {
    int n, m, a1[1000005] = {0}, a2[1000005] = {0}, total[2000010] = {0};
    int a, b, c, d, cnt = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a1[i]);
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", &a2[i]);

