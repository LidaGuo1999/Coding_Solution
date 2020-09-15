/* 问题描述：输入一个字符串，以回车结束（字符串长度<=100）。该字符串由若干个单词组成，单词之间用一个空格隔开，所有单词区分大小写。现需要将其中的某个单词替换成另一个单词，并输出替换之后的字符串。
 *
 * 输入描述：多组数据。每组数据输入包括3行， 第1行是包含多个单词的字符串 s， 第2行是待替换的单词a，(长度<=100) 第3行是a将被替换的单词b。(长度<=100) s, a, b 最前面和最后面都没有空格
 * 
 * 输出描述：每个测试数据输出只有 1 行， 将s中所有单词a替换成b之后的字符串。
 */

#include <iostream>
#include <cstring>

using namespace std;

void substitute(char ori[200], char w1[105], char w2[105], char change[100005]) {
    int start = 0, write = 0, len = strlen(ori), len1 = strlen(w1), len2 = strlen(w2);
    while (start < len) {
        //printf("%c\n", ori[start]);
        if (ori[start] == ' ') {
            change[write] = ' ';
            start++, write++;
        } else {
            int flag = 1, i = 0;
            for (i = 0; i < len1; i++) {
                //printf("%c %c\n", ori[start+i], w1[i]);
                if (ori[start+i] == 0) {
                    flag = 0; 
                    break;
                }
                if (ori[start+i] != w1[i]) {
                    flag = 0;
                    break;
                }
            }
            //printf("%d\n", i);
            if (ori[start+i] != ' ' && ori[start+i] != 0) flag = 0;
            //printf("%d\n", flag);
            
            if (flag == 1) {
                for (int j = 0; j < len2; j++) {
                    change[write] = w2[j];
                    write++;
                }
                start += i;
            } else {
                while (ori[start] != ' ' && ori[start] != 0) {
                    change[write] = ori[start];
                    start++, write++;
                }
            }
        }
    }
    return ;
}

int main() {
    char ori[200] = {0}, w1[105] = {0}, w2[105] = {0}, change[100005] = {0};
    while (gets(ori)) {
        gets(w1);
        gets(w2);
        substitute(ori, w1, w2, change);
        printf("%s\n", change);
    }
    
    return 0;
}
