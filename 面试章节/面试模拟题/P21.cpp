#include <iostream>
#include <vector>
#include <map>

using namespace std;

int dfs(int src, int n, int k, map<int, vector<int> >& des, map<int, vector<int> >& dis, map<int, vector<int> >& fee, vector<int> &flag, int total_dis, int total_fee) {
    int best_total = 10000000;
    for (int i = 0; i < des[src].size(); i++) {
        if (flag[des[src][i]]== 0) {
            flag[des[src][i]] = 1;
            if (des[src][i] == n) {
                if (total_fee + fee[src][i] <= k) {
                    if (best_total > total_dis+dis[src][i]) best_total = total_dis+dis[src][i];
                }
            } else {
                if (total_fee + fee[src][i] <= k) {
                    int result = dfs(des[src][i], n, k, des, dis, fee, flag, total_dis+dis[src][i], total_fee+fee[src][i]);
                    if (result != -1 && result < best_total) best_total = result;
                }
            }
            flag[des[src][i]] = 0;
        }
    }
    if (best_total == 10000000) return -1;
    else return best_total;
}

int main() {
    int k = 0, n = 0, r = 0;
    cin >> k >> n >> r;
    map<int, vector<int> >::iterator it;
    map<int, vector<int> > des;
    map<int, vector<int> > dis;
    map<int, vector<int> > fee;
    vector<int> flag(n+1, 0);
    for (int i = 0; i < n; i++) {
        vector<int> tmp1, tmp2, tmp3;
        des[i] = tmp1;
        dis[i] = tmp2;
        fee[i] = tmp3;
    }

    for (int i = 0; i < r; i++) {
        int s, d, l, t;
        cin >> s >> d >> l >> t;
        des[s].push_back(d);
        dis[s].push_back(l);
        fee[s].push_back(t);
    }

    flag[1] = 1;
    int result = dfs(1, n, k, des, dis, fee, flag, 0, 0);
    cout << result << endl;


    return 0;
}