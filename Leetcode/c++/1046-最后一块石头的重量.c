/*
 *
 * 思路梳理：
 * 1、每一次需要从石头中选出最重的两个，显然应该想到使用大顶堆来解决；
 *
 * 评测结果：
 * 0ms，100%；6MB，87.99%；
 */


class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> h{less<int>(), stones};
        if (stones.size() == 0) return 0;
        if (stones.size() == 1) return stones[0];

        while (h.size() >= 2) {
            int s1, s2;
            s1 = h.top();
            h.pop();
            s2 = h.top();
            h.pop();
            if (abs(s1-s2) > 0) h.push(abs(s1-s2));
        }

        if (h.size() == 0) return 0;
        if (h.size() == 1) return h.top();

        return 0;
    }
};
