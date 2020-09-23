/*
题目描述：
在一个火车旅行很受欢迎的国度，你提前一年计划了一些火车旅行。在接下来的一年里，你要旅行的日子将以一个名为 days 的数组给出。每一项是一个从 1 到 365 的整数。

火车票有三种不同的销售方式：

一张为期一天的通行证售价为 costs[0] 美元；
一张为期七天的通行证售价为 costs[1] 美元；
一张为期三十天的通行证售价为 costs[2] 美元。
通行证允许数天无限制的旅行。 例如，如果我们在第 2 天获得一张为期 7 天的通行证，那么我们可以连着旅行 7 天：第 2 天、第 3 天、第 4 天、第 5 天、第 6 天、第 7 天和第 8 天。

返回你想要完成在给定的列表 days 中列出的每一天的旅行所需要的最低消费。

思路梳理：
1、这是一道典型的动态规划的题目；
2、我们在第i天的时候分别可以选择使用1天、7天或30天的通行证，此时我们需要知道的就是第前i-1天，前i-7天和前i-30天的最低消费；
3、然后在上述三者中取最小值，即为前i天的最低消费。

评测结果：
4ms, 85.16%; 9.7MB, 20%;
*/

#include <algorithm>
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> min_cost(366, 0);
        int p = days[0];
        for (int i = 0; i < days.size(); i++) {
            int one = costs[0]+min_cost[days[i]-1];
            int seven = costs[1], thirty = costs[2];
            if (days[i] >= 30) {
                seven += min_cost[days[i]-7];
                thirty += min_cost[days[i]-30];
            } else if (days[i] >= 7) {
                seven += min_cost[days[i]-7];
            }
            
            min_cost[days[i]] = min(min(one, seven), thirty);
            
            while (i < days.size()-1 && p < days[i+1]) {
                min_cost[p] = min_cost[days[i]];
                p++;
            }
            //cout << min_cost[days[i]] << endl;
        }
        return min_cost[days[days.size()-1]];
    }
};