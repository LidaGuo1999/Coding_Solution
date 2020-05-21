/*
题目描述
为了找到自己满意的工作，牛牛收集了每种工作的难度和报酬。牛牛选工作的标准是在难度不超过自身能力值的情况下，牛牛选择报酬最高的工作。在牛牛选定了自己的工作后，牛牛的小伙伴们来找牛牛帮忙选工作，牛牛依然使用自己的标准来帮助小伙伴们。牛牛的小伙伴太多了，于是他只好把这个任务交给了你。

输入描述:
每个输入包含一个测试用例。
每个测试用例的第一行包含两个正整数，分别表示工作的数量N(N<=100000)和小伙伴的数量M(M<=100000)。
接下来的N行每行包含两个正整数，分别表示该项工作的难度Di(Di<=1000000000)和报酬Pi(Pi<=1000000000)。
接下来的一行包含M个正整数，分别表示M个小伙伴的能力值Ai(Ai<=1000000000)。
保证不存在两项工作的报酬相同。

输出描述:
对于每个小伙伴，在单独的一行输出一个正整数表示他能得到的最高报酬。一个工作可以被多个人选择。
 */

/*
思路梳理：
1、按照要求输入，用work和ability两个数组存下工作和小伙伴的信息；
2、对两个数组进行排序，从小到大；
3、对work数组进行操作，将每个元素的报酬值更新为能力范围内的最大值；
4、利用双指针，让ability中的能力值和work中的能力值进行比较，得到每个小伙伴可以得到的最大报酬；
5、最终按照小伙伴的顺序输出即可。
 */

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool cmp(pair<long long, long long> a, pair<long long, long long> b) {
    return a.first < b.first;
}

int main() {
    int n = 0, m = 0;
    long long cur_max = 0;
    cin >> n >> m;
    vector<pair<long long, long long> > work(n);
    vector<pair<long long, long long> > ability(m);
    vector<long long> order(m, 0);
    for (int i = 0; i < n; i++) {
        cin >> work[i].first >> work[i].second;
    }
    for (int i = 0; i < m; i++) {
        cin >> ability[i].first;
        ability[i].second = i;
    }
    sort(work.begin(), work.end(), cmp);
    sort(ability.begin(), ability.end(), cmp);

    for (int i = 0; i < n; i++) {
        cur_max = max(cur_max, work[i].second);
        work[i].second = cur_max;
    }

    int w = 0, a = 0;
    while (w < n && a < m) {
        if (ability[a].first < work[w].first) {
            if (w > 0) {
                order[ability[a].second] = work[w-1].second;
            } else {
                order[ability[a].second] = 0;
            }
            a++;
        } else {
            w++;
        }
    }
    for (; a < m; a++) {
        order[ability[a].second] = work[n-1].second;
    }
    for (int i = 0; i < m; i++) cout << order[i] << endl;

    
    return 0;
}