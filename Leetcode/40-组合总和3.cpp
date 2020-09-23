/* 问题描述：
 * 给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。candidates中的每个数字在每个组合中只能使用一次。 
 * 所有数字都是正整数，且解集不能包含重复的组合。
 *
 * 思路梳理：
 * 1、首先明显这是一道搜索回溯的问题，使用递归作为大框架；
 * 2、但是我们注意到每个数字只能使用一次，且解集中不能有重复的结果，如果直接搜索回溯的话，会出现重复的结果；
 * 3、为了解决重复的问题，我们先构建一个数组freq，其中存储了每个数字的值和其出现的次数；
 * 4、在进入下一次搜索回溯的时候，我们就枚举该元素出现的次数，就可以保证同样的结果只出现一次。
 *
 * 评测结果：
 * 8ms，78.09%；9.4MB，21.10%；
 */

class Solution {
private:
    vector<pair<int, int>> freq;
    vector<vector<int>> ans;
    vector<int> sequence;

public:
    void dfs(int pos, int rest) {
        if (rest == 0) {
            ans.push_back(sequence);
            return;
        }
        if (pos == freq.size() || rest < freq[pos].first) {
            return;
        }

        dfs(pos + 1, rest);

        int most = min(rest / freq[pos].first, freq[pos].second);
        for (int i = 1; i <= most; ++i) {
            sequence.push_back(freq[pos].first);
            dfs(pos + 1, rest - i * freq[pos].first);
        }
        for (int i = 1; i <= most; ++i) {
            sequence.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        for (int num: candidates) {
            if (freq.empty() || num != freq.back().first) {
                freq.emplace_back(num, 1);
            } else {
                ++freq.back().second;
            }
        }
        dfs(0, target);
        return ans;
    }
};
