#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

int main() {
    int n;
    char op;
    int matrix[11][11] = {0};
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    while (1) {
        scanf("%c", &op);
        if (op == '#') break;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int tmp;
                scanf("%d", &tmp);
                if (op == '+') matrix[i][j] += tmp;
                else if (op == '-') matrix[i][j] -= tmp;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%5d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
