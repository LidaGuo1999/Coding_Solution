// 现给定任意正整数 n，请寻找并输出最小的正整数 m（m>9），使得 m 的各位（个位、十位、百位 ... ...）之乘积等于n，若不存在则输出 -1。

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * 输入一个整形数值，返回一个整形值
     * @param n int整型 n>9
     * @return int整型
     */
    int solution(int n) {
        // write code here
        vector<int> v(n, 0);
        for (int i = 0;i < 10; i++) v[i] = 1;
        return recursion(n, v);
    }

    int recursion(int n, vector<int> v) {
        if 
    }
};