/* 问题描述：
 * 找出所有相加之和为 n 的 k 个数的组合。组合中只允许含有 1 - 9 的正整数，并且每种组合中不存在重复的数字。所有数字都是正整数，且解集不能包含重复的组合。
 *
 * 思路梳理：
 * 1、看到题目后得知这是一道以搜索回溯为框架的题目，使用递归的方法。我们首先构建一个1-9的数组，每个数字有“选择”和“不选择”两种情况，对于每个数字的搜索，我们分别“选择”和“不选择”即可；
 * 2、鉴于这个数组本身是单调递增的，所以当处于cur位置的数字被选择后和超过了n，那么后面的任何一个数只会更大，所以直接剪枝return；
 * 3、还有一个需要注意的是，组合满足要求的条件是和为n且数字个数为k，所以剩余数字个数也需要传入递归中处理。
 *
 * 评测结果：
 * 4ms，45.65%；12.3MB，5.10%；
 */

class Solution {
public:
    vector<int> tmp;

    void dfs(vector<int> nums, vector<vector<int> >& ans, int cur, int n, int k) {
        // 当剩余和为0且剩余数字个数为0时，代表一个符合要求的组合找到了；
        if (k == 0 && n == 0 && tmp.size() > 0) {
            ans.push_back(tmp);
            return ;
        }

        // 数组已经遍历完毕；
        if (cur >= 9) return ;
        
        // 数字已经用完或者和已经用完，因为上面已经判断过，所以不会出现两者都等于0的情况；
        if (k == 0 || n == 0) return ;

        if (n-nums[cur] >= 0) {
            tmp.push_back(nums[cur]);
            dfs(nums, ans, cur+1, n-nums[cur], k-1);        // 选择该数字；
            tmp.pop_back();

            dfs(nums, ans, cur+1, n, k);        // 不选择该数字；
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int> > ans;
        vector<int> nums {1,2,3,4,5,6,7,8,9};
        if (n > 45) return ans;

        dfs(nums, ans, 0, n, k);
        
        return ans;
    }
};
