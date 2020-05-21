/*
题目描述
小Q正在给一条长度为n的道路设计路灯安置方案。
为了让问题更简单,小Q把道路视为n个方格,需要照亮的地方用'.'表示, 不需要照亮的障碍物格子用'X'表示。
小Q现在要在道路上设置一些路灯, 对于安置在pos位置的路灯, 这盏路灯可以照亮pos - 1, pos, pos + 1这三个位置。
小Q希望能安置尽量少的路灯照亮所有'.'区域, 希望你能帮他计算一下最少需要多少盏路灯。

输入描述:
输入的第一行包含一个正整数t(1 <= t <= 1000), 表示测试用例数
接下来每两行一个测试数据, 第一行一个正整数n(1 <= n <= 1000),表示道路的长度。
第二行一个字符串s表示道路的构造,只包含'.'和'X'。

输出描述:
对于每个测试用例, 输出一个正整数表示最少需要多少盏路灯。

思路梳理：
1、主要是使用动态规划的思想；
2、设置bright数组记录每个位置被照亮的次数，count数组记录截止到第几个位置为止所需的最大灯光数，light用来记录当前最后一盏灯光的位置；
3、一般地说，当我们知道了前i-1个位置的情况后，要想知道第i个位置的情况，有三种选择，第一种是将最后一盏灯移到第i个位置，第二种是将最后一盏灯移到第i-1个位置，
第三种是在第i个位置添加一盏灯。按照顺序遍历这三种方法，选择能够实现的那种方法即可；
4、can_move函数就是用来判断某盏灯可不可以被移到另外一个地方。
 */

#include <iostream>
#include <vector>

using namespace std;

bool can_move(vector<int> bright, string s, int origin, int target) {
    if (origin > 0) bright[origin-1]--;
    bright[origin]--;
    bright[origin+1]--;
    bright[target-1]++;
    bright[target]++;
    bright[target+1]++;
    if (origin > 0) {
        if ((bright[origin-1] == 0 && s[origin-1] == '.') || (bright[origin] == 0 && s[origin] == '.') || (bright[origin+1] == 0 && s[origin+1] == '.')) return false;
        else return true;
    } else {
        if ((bright[origin] == 0 && s[origin] == '.') || (bright[origin+1] == 0 && s[origin+1] == '.')) return false;
        else return true;
    }

    return false;
}

int main() {
    int T = 0;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int n;
        string s = "";
        cin >> n >> s;
        vector<int> bright(n+2, 0), count(n, 0);
        int light = -2;

        for (int i = 0; i < n; i++) {
            if (s[i] == '.') {
                if (light == i-1) {
                    count[i] = count[i-1];
                }
                else if (light < 0) {
                    count[i] = 1;
                    if (i > 0) bright[i-1]++;
                    bright[i]++;
                    bright[i+1]++;
                    light = i;
                } else {
                    if (can_move(bright, s, light, i)) {
                        count[i] = count[i-1];
                        if (light > 0) bright[light-1]--;
                        bright[light]--;
                        bright[light+1]--;
                        bright[i-1]++;
                        bright[i]++;
                        bright[i+1]++;
                        light = i;
                    } else if (can_move(bright, s, light, i-1)) {
                        count[i] = count[i-1];
                        if (light > 0) bright[light-1]--;
                        bright[light]--;
                        bright[light+1]--;
                        bright[i-2]++;
                        bright[i-1]++;
                        bright[i]++;
                        light = i-1;
                    } else {
                        count[i] = count[i-1]+1;
                        bright[i-1]++;
                        bright[i]++;
                        bright[i+1]++;
                        light= i;
                    }
                }
            } else {
                if (i > 0) count[i] = count[i-1];
            }

            //for (int j = 0; j < n; j++) cout << bright[j] << " ";
            //cout << endl;
        }

        cout << count[n-1] << endl;

    }

    return 0;
}