
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

void mergeSort(vector<int> &total, int start, int end) {
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
    int n, m;
    int a, b, c, d, cnt = 0;
    vector<int> a1, a2, total;
    scanf("%d %d", &n, &m);
    a1.resize(n), a2.resize(m), total.resize(n+m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a1[i]);
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", &a2[i]);
    }
    scanf("%d %d %d %d", &a, &b, &c, &d);
    if (a > 0) {
        for (int i = a-1; i < b; i++) {
            total[cnt++] = a1[i];
        }
    }
    if (c > 0) {
        for (int i = c-1; i < d; i++) {
            total[cnt++] = a2[i];
        }
    }


    if (cnt != 0) {
        mergeSort(total, 0, cnt-1);
        int pos = (cnt-1)/2;
        printf("%d\n", total[pos]);
    } else {

    }

    return 0;
}
