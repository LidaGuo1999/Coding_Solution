/* 有n 个老铁（编号为 1 到n）正在玩丢手绢。在游戏里每人会把当前手里的手绢丢给一个固定的人，编号为Ti。 游戏开始时，每人手里有自己的手绢。之后每一轮中，所有人会同时将自己当前手里的手绢全部丢给接收的对象。当有人重新拿到自己的手绢时，游戏结束。
那么游戏几轮会结束呢？
*/ 

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, tmp = 0;
    int min_round = 1000000;
    cin >> n;
    vector<int> to(n);
    vector<int> in_degree(n, 0);
    vector<int> s;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        tmp--;
        to[i] = tmp;
        in_degree[to[i]]++;
    }

    for (int i = 0; i < n; i++) {
        if (in_degree[i] == 0) s.push_back(i);
    }

    while (!s.empty()) {
        tmp = s.back();
        s.pop_back();
        in_degree[tmp]--;
        in_degree[to[tmp]]--;
        if (in_degree[to[tmp]] == 0) s.push_back(to[tmp]);
    }

    for (int i = 0; i < n; i++) {
        if (in_degree[i] != -1) {
            int round = 1;
            int start = i;
            int j = i;
            while (to[j] != start) {
                j = to[j];
                round++;
                in_degree[j] = -1;
            }
            min_round = round < min_round ? round : min_round;
        } 
    }

    cout << min_round << endl;

    return 0;
}