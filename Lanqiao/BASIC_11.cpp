/* 从键盘输入一个不超过8位的正的十六进制数字符串，将它转换为正的十进制数后输出。
 * 注：十六进制数中的10~15分别用大写的英文字母A、B、C、D、E、F表示。
 */

#include <iostream>
#include <cstring>

using namespace std;

int main() {
    char num[10] = {0};
    scanf("%s", num);
    int n = (int)strlen(num);
    
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        sum *= 16;
        if (num[i] >= '0' && num[i] <= '9') {
            sum += num[i]-'0';
        } else {
            sum += 10+num[i]-'A';
        }
    }

    printf("%lld\n", sum);

    return 0;
}
