/* 问题描述：输入任意4个字符(如：abcd)， 并按反序输出(如：dcba)
 *
 * 输入描述：题目可能包含多组用例，每组用例占一行，包含4个任意的字符。
 *
 * 输出描述：对于每组输入,请输出一行反序后的字符串。
具体可见样例。
 */

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    char word[4] = {0};
    while (gets(word) != NULL) {
        swap(word[0], word[3]);
        swap(word[1], word[2]);
        printf("%s\n", word);
    }

    return 0;
}
