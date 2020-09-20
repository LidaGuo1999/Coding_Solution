/* 问题描述：编写一个程序，将输入字符串中的字符按如下规则排序(一个测试用例可能包含多组数据，请注意处理)。

规则 1 ：英文字母从 A 到 Z 排列，不区分大小写。

如，输入： Type 输出： epTy

规则 2 ：同一个英文字母的大小写同时存在时，按照输入顺序排列。

如，输入： BabA 输出： aABb

规则 3 ：非英文字母的其它字符保持原来的位置。

如，输入： By?e 输出： Be?y
 *
 * 输入描述：一行字符串
 *
 * 输出描述：重新排序过后的字符串
 */


#include <stdio.h>
#include <string.h>

void sorting(char ori[100005]) {
    char letter[100005] = {0};
    int len = strlen(ori), cnt = 0;
    for (int i = 0; i < len; i++) {
        if ((ori[i] >= 'A' && ori[i] <= 'Z') || (ori[i] >= 'a' && ori[i] <= 'z')) {
            letter[cnt] = ori[i];
            cnt++;
        }
    }

    for (int i = 0; i < cnt; i++) {
        for (int j = 0; j < cnt-i-1; j++) {
            char left, right;
            if (letter[j] >= 'a' && letter[j] <= 'z') left = letter[j];
            else if (letter[j] >= 'A' && letter[j] <= 'Z') left = letter[j]+'a'-'A';
            if (letter[j+1] >= 'a' && letter[j+1] <= 'z') right = letter[j+1];
            else if (letter[j+1] >= 'A' && letter[j+1] <= 'Z') right = letter[j+1]+'a'-'A';

            if (left > right) {
                char tmp = letter[j];
                letter[j] = letter[j+1];
                letter[j+1] = tmp;
            }
        }
    }

    int t = 0;
    for (int i = 0; i < len; i++) {
        if ((ori[i] >= 'A' && ori[i] <= 'Z') || (ori[i] >= 'a' && ori[i] <= 'z')) {
            ori[i] = letter[t];
            t++;
        }
    }

    return ;
}

int main() {
    char ori[100005] = {0};
    while (gets(ori) != NULL) {
        sorting(ori);
        printf("%s\n", ori);
    }

    return 0;
}
