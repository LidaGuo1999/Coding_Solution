/* 一年一度的快手运动会又要开始了，同学们终于有一天可以离开鼠标键盘显示器，全身心的投入到各种体育项目中。UED设计师小红虽然没有参加体育项目，但她的责任重大，因为她是拉拉队的队长，她需要在每个项目中为参赛的同学们加油助威。
因为运动会的项目众多，很多项目在同一时间会同时进行着。作为拉拉队长，小红需要遵守以下规则：
不能同时给多个体育项目加油助威
给每个体育项目加油的时长必须超过项目时长的一半，每个体育项目只能加油一次
体育项目的开始和结束时间都是整点，如果项目进行到一半想要离开，也只能选择整点离开
不考虑往返于各个体育项目比赛场地中花费的时间
请帮小红设计一个算法，在已知所有体育项目日程的前提下，计算是否能在每个体育项目中为参赛的同学们加油。

说明：
如果体育项目时长为2，超过时长的一半为2;
如果体育项目时长为3，超过时长的一半为2;
如果体育项目时长为4，超过时长的一半为3；
*/

#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int n = 0;
    int schedule[11][3] = {0};
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> schedule[i][0] >> schedule[i][1];
        schedule[i][2] = (int)((float)(schedule[i][1] - schedule[i][0]) / 2 + 1);
    }

    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (schedule[i][1] > schedule[j][1]) {
                int temp[3];
                memcpy(temp, schedule[i], sizeof(schedule[i]));
                memcpy(schedule[i], schedule[j], sizeof(schedule[j]));
                memcpy(schedule[j], temp, sizeof(temp));
            }
        }
    }

    int start = schedule[0][0];
    for (int i = 0; i < n-1; i++) {
        if (schedule[i][0] >= start) {
            start = schedule[i][0] + schedule[i][2];
        } else {
            if (start + schedule[i][2] > schedule[i][1]) {
                cout << -1 << endl;
                return 0;
            } else {
                start = start + schedule[i][2];
            }
        }
    }

    cout << 1 << endl;
    return 0;
}