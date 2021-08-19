// 思路梳理：
// 1、雨水的堆积本质上是两边有柱子围住形成的空间；
// 2、设计一个栈，里面存储的是目前最高的柱子高度，当碰到一个更高的柱子，那么栈里的这个柱子和这个更高的柱子之间围住的雨水就可以计算，计算完后将栈中的柱子弹出，压入更高的柱子；
// 3、但是从所有柱子中最高的柱子到最后一个柱子之间的雨水没有计算，所以还要从最后一个柱子倒序遍历，直到最高的柱子为止，方法与正序一样；
// 4、最终将正序和倒叙所得到的雨水体积相加即可得到答案；

// 8ms, 87.89%; 14.2MB, 76.04%;

#include <stack>
class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() == 0) return 0;

        stack<int> col, index;
        int cur_sum = 0, total_water = 0;   

        for (int i = 0; i < height.size(); i++) {
            if (col.empty()) {
                col.push(height[i]);
                index.push(i);
            } else if (height[i] >= col.top()) {
                int gap_area = min(height[i], col.top()) * (i-index.top()-1);
                int gap_water = gap_area-cur_sum;
                total_water += gap_water;

                col.pop();
                index.pop();
                col.push(height[i]);
                index.push(i);

                //printf("%d %d %d %d\n", i, gap_area, cur_sum, gap_water);

                cur_sum = 0;
            } else {
                cur_sum += height[i];
            }
        }
        //printf("\n");
        int reverse_water = 0, tallest = index.top();
        cur_sum = 0;
        
        while (!col.empty()) {
            col.pop();
            index.pop();
        }
         
        for (int i = height.size()-1; i >= tallest; i--) {
            if (col.empty()) {
                col.push(height[i]);
                index.push(i);
            } else if (height[i] >= col.top()) {
                int gap_area = min(height[i], col.top()) * (index.top()-i-1);
                int gap_water = gap_area-cur_sum;
                reverse_water += gap_water;

                col.pop();
                index.pop();
                col.push(height[i]);
                index.push(i);

                //printf("%d %d %d %d\n", i, gap_area, cur_sum, gap_water);

                cur_sum = 0;
            } else {
                cur_sum += height[i];
            }
        }

        total_water += reverse_water;
        return total_water;
    }
};