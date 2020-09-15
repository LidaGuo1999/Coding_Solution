/* 题目描述：在情报传递过程中，为了防止情报被截获，往往需要对情报用一定的方式加密，简单的加密算法虽然不足以完全避免情报被破译，但仍然能防止情报被轻易的识别。我们给出一种最简的的加密方法，对给定的一个字符串，把其中从a-y,A-Y的字母用其后继字母替代，把z和Z用a和A替代，则可得到一个简单的加密字符串。
 *
 * 输入描述：读取这一行字符串，每个字符串长度小于80个字符
 *
 * 输出描述：输出每行字符串的加密字符串。
 */

#include <iostream>

using namespace std;

void encrypt(char ar[85]) {
    for (int i = 0; ar[i] != 0; i++) {
        if (ar[i] >= 'a' && ar[i] <= 'z')
            ar[i] = 'a'+(ar[i]+1-'a')%26;
        else if (ar[i] >= 'A' && ar[i] <= 'Z') 
            ar[i] = 'A'+(ar[i]+1-'A')%26;
    }
    return ;
}

int main() {
    int n;
    char ar[85] = {0};
    for (int i = 0; i < 1; i++) {
        gets(ar);
        encrypt(ar);
        printf("%s\n", ar);
    }
    
    return 0;
}
