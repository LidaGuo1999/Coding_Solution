/* 有位老铁设计了一个跳格子游戏，游戏有N个格子顺序排成一行，编号从1到N，每个格子有点数Qi，有标记Li（标记的范围是1-M），每次跳格子，要选择一个格子a，以任意正偶数距离x跳到格子b，如果格子b在游戏区域内，且La=Lb，则称为一次合法跳跃，获得的分数是(a + b) * (Qa + Qb)。
在继续设计游戏玩法时，这位老铁纠结了很久，于是他决定放弃……但是他想知道所有合法跳跃总共能获得多少分。
*/

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m = 0;
    long long ans = 0;
    cin >> n >> m;
    vector<int> point(n);
    vector<int> flag(n);

    for (int i = 0; i < n; i++) {
        cin >> point[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> flag[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = i+2; j < n; j += 2) {
            if (flag[i] == flag[j]) {
                ans = (ans + ((i+j+2)*(point[i]+point[j])) % 10007) % 10007;
            }
        }
    }

    cout << ans << endl;

    return 0;
}