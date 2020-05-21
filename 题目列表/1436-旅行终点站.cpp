/*
题目描述：
给你一份旅游线路图，该线路图中的旅行线路用数组 paths 表示，其中 paths[i] = [cityAi, cityBi] 表示该线路将会从 cityAi 直接前往 cityBi 。请你找出这次旅行的终点站，即没有任何可以通往其他城市的线路的城市。

题目数据保证线路图会形成一条不存在循环的线路，因此只会有一个旅行终点站。

思路梳理：
1、用两个集合分别存当前出现过的所有城市和当前有路径到达其他城市的始发城市；
2、然后遍历所有城市中没有在始发城市中出现的城市，该城市即为旅行终点站；

测试结果：
32ms, 52.74%; 无数据
 */

#include <set>
class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        set<string> appear, start;
        for (int i = 0; i < paths.size(); i++) {
            appear.insert(paths[i][0]);
            appear.insert(paths[i][1]);
            start.insert(paths[i][0]);
        }
        
        for (set<string>::iterator it = appear.begin(); it != appear.end(); it++) {
            if (start.find(*it) == start.end()) return *it;
        }
        
        return NULL;
    }
};