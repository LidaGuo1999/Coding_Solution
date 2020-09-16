/* 题目描述:输入任意（用户，成绩）序列，可以获得成绩从高到低或从低到高的排列,相同成绩
都按先录入排列在前的规则处理。
 *
 * 输入描述：输入多行，先输入要排序的人的个数，然后输入排序方法0（降序）或者1（升序）再分别输入他们的名字和成绩，以一个空格隔开。需要循环输入。
 *
 * 输出描述：按照指定方式输出名字和成绩，名字和成绩之间以一个空格隔开
 */

#include <iostream>
#include <vector>

using namespace std;

struct student {
    char name[100];
    int grade;
};

void handle(vector<student>& s, int mode) {
    int len = s.size();
    for (int i = 0; i < len; i++) {
        for (int j = 0; j+1 < len-i; j++) {
            if (mode == 0) {
                if (s[j].grade < s[j+1].grade) swap(s[j], s[j+1]);
            } else {
                if (s[j].grade > s[j+1].grade) swap(s[j], s[j+1]);
            }
        }
    }
}

int main() {
    int n, mode;
    while (scanf("%d %d", &n, &mode) != EOF) {
        vector<student> s(n);
        for (int i = 0; i < n; i++) {
            scanf("%s %d", s[i].name, &s[i].grade);
        }
    
        handle(s, mode);
    
        for (int i = 0; i < n; i++) {
            printf("%s %d\n", s[i].name, s[i].grade);
        }
    }
    
    return 0;
}
