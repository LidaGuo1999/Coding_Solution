#include <iostream>
#include <map>

using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;
    map<long long, long long> destroy;

    for (long long i = 0; i < m; i++) {
        long long op, pos;
        cin >> op >> pos;
        if (op == 1) {
            destroy[pos] = 1;
        } else {
            if (destroy.find(pos) == destroy.end()) cout << pos << endl;
            else if (pos < n && destroy.find(pos+1) == destroy.end()) cout << pos+1 << endl;
            else cout << -1 << endl;
        }
    }

    return 0;
}