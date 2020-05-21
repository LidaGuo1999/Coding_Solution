/*
题目描述
牛牛以前在老师那里得到了一个正整数数对(x, y), 牛牛忘记他们具体是多少了。
但是牛牛记得老师告诉过他x和y均不大于n, 并且x除以y的余数大于等于k。
牛牛希望你能帮他计算一共有多少个可能的数对。

输入描述:
输入包括两个正整数n,k(1 <= n <= 10^5, 0 <= k <= n - 1)。

输出描述:
对于每个测试用例, 输出一个正整数表示可能的数对数量。

解题思路：
1、注意到固定住y后，x从1到n遍历的时候，除以y的余数是周期性的，周期为y。所以利用这个特点，我们就可以快速算出对于给定的y，有多少个x符合条件。
2、然后让y从k+1开始向n遍历即可。
 */

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    long long count = 0;
    for (int y = max(1, k); y <= n; y++) {
        count = count + (n/y)*(y-k);
        if (n%y>=k) {
            if (k == 0) count += n%y;
            else count += n%y-k+1;
        }
        
        //cout << count << endl;
    }

    cout << count << endl;

    return 0;
}