/* 问题描述：
 * 给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
 * candidates 中的数字可以无限制重复被选取。
 *
 * 思路梳理：
 * 1、寻找可行解问题，一般采用搜索回溯法；
 * 2、数组中的每个数字可以被“选择”和“不选择”，利用递归的方法可以遍历每一种情况；
 * 3、此题的特点是存在一个数字重复被选用的情况，所以要注意选择完该元素后下一轮递归还是得从该元素开始；
 * 4、如果将原数组先排序后，再进行搜索回溯，则可以利用大小关系进行更好地剪枝。
 *
 * 评测结果：
 * 8ms，87.52%；11MB，78.55%；
 */


class Solution {
public:
    vector<int> tmp;

    void dfs(vector<int>& candidates, int target, int cur, int n, vector<vector<int> >& ans) {
        // 已经遍历完candidates数组了；
        if (cur == n) return ;

        // 得到一个可行解；
        if (target == 0) {
            ans.push_back(tmp);
            return ;
        }

        if (target-candidates[cur] >= 0) {
            tmp.push_back(candidates[cur]);
            dfs(candidates, target-candidates[cur], cur, n, ans);
            
            tmp.pop_back();
        }
        dfs(candidates, target, cur+1, n, ans);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int> > ans;
        int n = candidates.size();
        dfs(candidates, target, 0, n, ans);

        return ans;
    }
};
