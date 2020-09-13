/* 给定一个自然数，取出它的十位上的数字。
 */

#include <iostream>

using namespace std;

int main() {
    int n, ans = 0;
    scanf("%d", &n);
    ans = n/10%10;

    printf("%d\n", ans);

    return 0;
}
