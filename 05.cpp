#include <iostream>

using namespace std;

int nums[100001], ans[100001];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    for (int i = 0; i < n; i++) {
        if (ans[i] == 1) continue;
        for (int j = 0; j < n; j++) {
            if ((nums[i] & nums[j]) == 0) {
                ans[i] = 1;
                ans[j] = 1;
                continue;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (ans[i] == 0) cout << -1 << " ";
        else cout << 1 << " ";
    }
    cout << endl;

    return 0;
}