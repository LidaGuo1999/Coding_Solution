#include <iostream>
#include <string>
#include <map>

using namespace std;

int cal_A(int n) {
    int ans = 1;
    for (int i = 1; i <= n; i++) {
        ans *= i;
    }
    return (int)ans;
}

int main() {
    string s;
    cin >> s;
    int ans = cal_A(s.length());
    map<char, int> count;
    map<char, int>::iterator it;
    
    for (int i = 0; i < s.length(); i++) {
        if (count.find(s[i]) == count.end()) {
            count[s[i]] = 1;
        } else {
            count[s[i]]++;
        }
    }

    for (it = count.begin(); it != count.end(); it++) {
        ans = (int)(ans/cal_A((int)(it->second)));
    }
    if (s.length() == 0) ans = 0;
    cout << ans << endl;

    return 0;
}