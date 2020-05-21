#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;
    int k = 0;
    cin >> k;

    //cout << s << " " << k << endl;
    for (int i = 0; i < k; i++) {
        int flag = 0;
        for (int j = 0; j < s.length()-1; j++) {
            if (s[j] > s[j+1]) {
                s = s.substr(0, j) + s.substr(j+1);
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            s = s.substr(1);
        } 
    }

    cout << s << endl;

    return 0;
}