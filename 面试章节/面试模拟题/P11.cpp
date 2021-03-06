/* 因为公司有免费健身福利，快手程序员老铁们都很爱健身，而且他们健身时像工作一样充满效率。
他们把健身过程神奇的简化了出来：健身有N种锻炼方式可选，器材可看成在一条直线上。
每种锻炼方式距门口Xi米，因为有的器材上可以支持多种锻炼方式，因此有可能出现两种锻炼方式的距离是一样的，即Xa = Xb。
老铁们一进健身房门口就开启健身形态，每走1米，就能获得1点锻炼效果值，而每种锻炼方式也有Ei的效果值，锻炼的过程就是从门口走到某种锻炼方式锻炼，然后到下一个方式锻炼，最后返回门口的过程。需要注意的是，锻炼过程中老铁们不会为了获得效果而刻意走回头路。
老铁们很想知道如果想选择某几种锻炼方式，怎样获得最大锻炼效果。

输入：
第一行N，表示锻炼方式的个数

第二行N个整数，表示每种锻炼方式距门口的距离

第三行N个整数，表示每种锻炼方式的效果值

输出：
N个整数，第k行表示选择k种锻炼方式时获得的最大锻炼效果
*/

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n = 0;
    cin >> n;
    vector<int> distance(n);
    vector<int> effect(n);
    vector<int> flag(n, 0);
    for (int i = 0; i < n; i++) cin >> distance[i];
    for (int i = 0; i < n; i++) {
        cin >> effect[i];
        flag[i] = i;
    }

    int cur_dis = 0;
    int total_effect = 0;
    for (int i = 0; i < n; i++) {
        int max_index = -1;
        int max_effect = 0;
        for (int k = 0; k < flag.size(); k++) {
            int j = flag[k];
            if (distance[j] > cur_dis) {
                if ((distance[j]-cur_dis)*2+effect[j] > max_effect) {
                    max_index = k;
                    max_effect = (distance[j]-cur_dis)*2+effect[j];
                }
            } else {
                if (effect[j] > max_effect) {
                    max_index = k;
                    max_effect = effect[j];
                }
            }
        }
        //cout << max_index << " " << max_effect << endl;
        total_effect += max_effect;
        cur_dis = (distance[flag[max_index]] > cur_dis) ? distance[flag[max_index]] : cur_dis;
        flag.erase(flag.begin()+max_index, flag.begin()+max_index+1);
        cout << total_effect << endl;
    }


    return 0;
}