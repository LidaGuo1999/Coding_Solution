/* 问题描述：
 * 给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。
 *
 * 思路梳理：
 * 1、对于n个数字来说，每个数字有“选”和“不选”两个选择，使用递归，每次向前推进一个数字，分别讨论“选择该数字”和“不选择该数字”的情况，再进行下一轮递归；
 * 2、对于剩余的数字即便全选上也达不到k个数字的情况，可以直接剪枝；
 * 3、还有一个trick就是我们只需要一个vector tmp，因为vector的push_back函数添加的是元素的一个copy，是值传递，不用担心后续tmp改变会影响ans数组中已经添加的值；
 * 4、官方题解中还给了一种非递归（字典序法）组合型枚举，但是我还没有完全理解，故先不列出；
 *
 * 评测结果：
 * 16ms，92.51%；18.2MB，19.21%;
 */


class Solution {
public:
    vector<int> tmp;
    
    void dfs(int cur, int n, int k, vector<vector<int> >& ans) {
        // 当剩余的数字全部选择也达不到k个时，剪枝；
        if (tmp.size()+n-cur+1 < k) return;

        // 当已经选择的数量达到了k个时，代表选择过程已经结束，直接加入ans数组即可；
        if (tmp.size() == k) {
            ans.push_back(tmp);
            return ;
        }
        
        // 选择位于cur的数字；
        tmp.push_back(cur);
        dfs(cur+1, n, k, ans);
        tmp.pop_back();

        // 不选择位于cur的数字；
        dfs(cur+1, n, k, ans);        

    } 

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int> > ans;
        dfs(1, n, k, ans);

        return ans;
    }
};
