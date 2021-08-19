#include <iostream>
#include <cstring>
#include <cstdlib>
#include <map>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    map<int, int> m;
    for (int i = 0; i < n; i++) {
        int tmp;
        scanf("%d", &tmp);
        if (m.find(tmp) == m.end()) {
            m[tmp] = 0;
        } else {
            m[tmp]++;
        }
    }
    
    int cur_max = -1, ans = 0;
    for (map<int, int>::iterator i = m.begin(); i != m.end(); i++) {
        if (i->second > cur_max) {
            cur_max = i->second;
            ans = i->first;
        }
    }

    printf("%d\n", ans);

    return 0;
}
