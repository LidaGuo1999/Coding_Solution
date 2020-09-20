/* 问题描述：对一个字符串中的所有单词，如果单词的首字母不是大写字母，则把单词的首字母变成大写字母。 在字符串中，单词之间通过空白符分隔，空白符包括：空格(' ')、制表符('\t')、回车符('\r')、换行符('\n')。
 *
 * 输入描述：输入一行：待处理的字符串（长度小于100）。
 *
 * 输出描述：可能有多组测试数据，对于每组数据，
输出一行：转换后的字符串。
 */


#include <stdio.h>
#include <string.h>

void transform(char ar[105]) {
    int flag = 1, len = strlen(ar);
    for (int i = 0; i < len; i++) {
        if (flag == 1) {
            if (ar[i] >= 'a' && ar[i] <= 'z') {
                ar[i] += 'A'-'a';
            }
        }
        if (ar[i] == ' ' || ar[i] == '\t' || ar[i] == '\r' || ar[i] == '\n') flag = 1;
        else flag = 0;
    }

    return ;
}

int main() {
    char ar[105] = {0};
    while (gets(ar) != NULL) {
        transform(ar);
        printf("%s\n", ar);
    }

    return 0;
}
