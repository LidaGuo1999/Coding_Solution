// 在vivo产线上，每位职工随着对手机加工流程认识的熟悉和经验的增加，日产量也会不断攀升。
// 假设第一天量产1台，接下来2天(即第二、三天)每天量产2件，接下来3天(即第四、五、六天)每天量产3件 ... ... 
// 以此类推，请编程计算出第n天总共可以量产的手机数量。
#include <iostream>
#include <math.h>
using namespace std;

class Solution {
public:
    /**
     * 
     * @param n int整型 第n天
     * @return int整型
     */
    int solution(int n) {
        int about = (int)sqrt(2*n);
        int left = about - 1;
        int right = about + 1;
        int bottom = 0;
        if (left*(left+1)/2 > n) {
            bottom = left - 1;
        } else if (left*(left+1)/2 <= n && about*(about+1)/2 > n) {
            bottom = left;
        } else if (about*(about+1)/2 <= n && right*(right+1)/2 > n) {
            bottom = about;
        } else if (right*(right+1)/2 <= n) {
            bottom = right;
        }
        int sum = bottom*(bottom+1)*(2*bottom+1)/6 + (bottom+1)*(n-(bottom*(bottom+1))/2);
        return sum;
    }
};

int main() {
    Solution s = Solution();
    int n;
    cin >> n;
    cout << s.solution(n) << endl;
}