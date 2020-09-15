/* 题目描述：对于给定的字符序列，从左至右将所有的数字字符取出拼接成一个无符号整数（字符序列长度小于100，拼接出的整数小于2^31,），计算并输出该整数的最大素因子（如果是素数，则其最大因子为自身）
 *
 * 输入描述：有多组数据，输入数据的第一行为一个正整数，表示字符序列的数目，每组数据为一行字符序列。
 *
 * 输出描述：对每个字符序列，取出所得整数的最大素因子，若字符序列中没有数字或者找出的整数为0，则输出0，每个整数占一行输出。
 */

#include <iostream>

using namespace std;

int getNum(char ar[105]) {
    int sum = 0, i = 0;
    while (ar[i] != 0) {
        if (ar[i] >= '0' && ar[i] <= '9') {
            sum *= 10;
            sum += ar[i]-'0';
        }
        i++;
    }
    
    return sum;
}

int getPrime(int num) {
    if (num <= 3) return num;
    int a = 2, nnum = num, cur_max = 1;
    while (a*a <= nnum) {
        //printf("%d\n", a);
        if (nnum%a == 0) {
            cur_max = a;
            nnum /= a;
        } else {
            a++;
        }
    }
    
    return nnum>cur_max ? nnum : cur_max;
}

int main() {
    int n;
    char ar[105] = {0};
    scanf("%d", &n);
    getchar();
    for (int c = 1; c <= n; c++) {
        gets(ar);
        //printf("string: %s\n", ar);
        int num = getNum(ar);
        //printf("nums get: %d\n", num);
        int ans = getPrime(num);
        printf("%d\n", ans);
    }
    
    return 0;
}
