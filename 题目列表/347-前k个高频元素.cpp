/* 题目描述：
 * 给定一个非空的整数数组，返回其中出现频率前 k 高的元素。
 *
 * 思路梳理：
 * 1、首先利用哈希表将每个元素出现的次数储存下来，然后将出现的次数存成一个数组；
 * 2、接着只需要找到数组中的前k大个元素即可，有两种方法，第一种是使用堆，第二种是直接排序。我是使用了直接排序的方法；
 * 3、其中还有一个诀窍就是在结构体中对运算符进行重载，就可以不需要再写compare函数了；
 *
 * 评测结果：
 * 64ms，10.06%；14.1MB,44.99%;
 */


class Solution {

struct element {
    int val;
    int cnt;
    bool operator < (const element& x) const {
        return cnt < x.cnt;
    }
};

public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> cnt;
        for (int num: nums) {
            if (cnt.find(num) == cnt.end()) cnt[num] = 1;
            else cnt[num]++;
        }

        vector<element> numbers;
        for (auto x = cnt.begin(); x != cnt.end(); x++) {
            element temp;
            temp.val = x->first;
            temp.cnt = x->second;
            numbers.push_back(temp);
        }

        sort(numbers.begin(), numbers.end());
        reverse(numbers.begin(), numbers.end());

        vector<int> ans;
        for (int i = 0; i < k; i++) ans.push_back(numbers[i].val);

        return ans;
    }
};
