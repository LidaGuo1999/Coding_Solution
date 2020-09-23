#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int count_leaf(char ar[105]) {
    int len = strlen(ar);
    int cnt = 0;
    for (int i = 0; i < len; i++) {
        if (ar[i] != '#') {
            if (ar[i+1] == '#' && ar[i+2] == '#') cnt++;
        }
    }

    return cnt;
}

int main() {
    char ar[105] = {0};
    while (fgets(ar, 100, stdin) != NULL) {
        int ans = count_leaf(ar);
        printf("%d\n", ans);
    }
}
