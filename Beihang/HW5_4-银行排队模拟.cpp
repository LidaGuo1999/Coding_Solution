
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <queue>

using namespace std;

typedef struct customer {
    int id, come;
} customer;

int main() {
    int n = 0, in = 0, id = 1, window = 3, i, cur = 0;
    queue<customer> wait;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &in);
        for (int j = 0; j < in; j++) {
            customer a;
            a.id = id++;
            a.come = i;
            wait.push(a);
            //printf("%d\n", a.id);
        }

        cur = (int)wait.size();
        if (cur/window >= 7) {
            while (window >= 3 && window < 5 && cur/window >= 7) {
                window++;
            }
        } else {
            while (window > 3 && cur/(window-1) < 7) {
                window--;
            }
        }

        for (int k = 0; k < window && !wait.empty(); k++) {
            printf("%d : %d\n", wait.front().id, i-wait.front().come);
            wait.pop();
        }

        cur = (int)wait.size();
        if (cur/window >= 7) {
            while (window >= 3 && window < 5 && cur/window >= 7) {
                window++;
            }
        } else {
            while (window > 3 && cur/(window-1) < 7) {
                window--;
            }
        }
    }

    for ( ; ; i++) {
        cur = (int)wait.size();
        if (cur/window >= 7) {
            while (window >= 3 && window < 5 && cur/window >= 7) {
                window++;
            }
        } else {
            while (window > 3 && cur/(window-1) < 7) {
                window--;
            }
        }

        for (int k = 0; k < window && !wait.empty(); k++) {
            printf("%d : %d\n", wait.front().id, i-wait.front().come);
            wait.pop();
        }

        if (wait.empty()) break;
    }

    return 0;
}
