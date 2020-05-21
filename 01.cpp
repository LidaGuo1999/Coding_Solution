#include <iostream>
#include <set>

using namespace std;

int matrix[502][502];
int pos[502];

int main() {
    int n, m;
    set<int> appear;
    cin >> n >> m;
    if (n == 0 && m == 0) {
        cout << 0 << endl;
        return 0;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[j][i];
        }
    }

    for (int i = 0; i < m; i++) {
        for (int ii = 0; ii < n; ii++) pos[ii] = ii;
        for (int j = 0; j < n; j++) {
            for (int k = j+1; k < n; k++) {
                if (matrix[i][j]<matrix[i][k]) {
                    int tmp = matrix[i][j];
                    matrix[i][j] = matrix[i][k];
                    matrix[i][k] = tmp;
                    tmp = pos[j];
                    pos[j] = pos[k];
                    pos[k] = tmp;
                }
            }
        }
        int cur_max = matrix[i][0];
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == cur_max) appear.insert(pos[j]);
            else break;
        }
    }

    cout << appear.size() << endl;

    return 0;
}