/* 问题描述：使用代理服务器能够在一定程度上隐藏客户端信息，从而保护用户在互联网上的隐私。我们知道n个代理服务器的IP地址，现在要用它们去访问m个服务器。这 m 个服务器的 IP 地址和访问顺序也已经给出。系统在同一时刻只能使用一个代理服务器，并要求不能用代理服务器去访问和它 IP地址相同的服务器（不然客户端信息很有可能就会被泄露）。在这样的条件下，找到一种使用代理服务器的方案，使得代理服务器切换的次数尽可能得少。
 *
 * 输入描述：每个测试数据包括 n + m + 2 行。
    第 1 行只包含一个整数 n，表示代理服务器的个数。
    第 2行至第n + 1行每行是一个字符串，表示代理服务器的 IP地址。这n个 IP地址两两不相同。
    第 n + 2 行只包含一个整数 m，表示要访问的服务器的个数。
    第 n + 3 行至第 n + m + 2 行每行是一个字符串，表示要访问的服务器的 IP 地址，按照访问的顺序给出。
    每个字符串都是合法的IP地址，形式为“xxx.yyy.zzz.www”，其中任何一部分均是0–255之间的整数。输入数据的任何一行都不包含空格字符。
     其中，1<=n<=1000，1<=m<=5000。

 *
 * 输出描述：可能有多组测试数据，对于每组输入数据， 输出数据只有一行，包含一个整数s，表示按照要求访问服务器的过程中切换代理服务器的最少次数。第一次使用的代理服务器不计入切换次数中。若没有符合要求的安排方式，则输出-1。
 */

#include <iostream>
#include <vector>
#include <deque>
#include <cstring>
#include <algorithm>

using namespace std;

void handle(char dele[][20], int n, char access[][20], int m, vector<deque<int> >& cor, vector<int>& overlap) {
    for (int i = 0; i < n; i++) {
        cor.push_back(deque<int>());
        //printf("%d\n", cor[i].size());
        for (int j = 0; j < m; j++) {
            if (strcmp(dele[i], access[j]) == 0) {
                //printf("%d\n", cor.size());
                cor[i].push_back(j);
                overlap.push_back(j);
            }
        }
    }
    
    sort(overlap.begin(), overlap.end());
    return ;
}

int cal(vector<deque<int> >& cor, vector<int>& overlap) {
    int cnt = 0;
    if (cor.size() == 1 && !cor[0].empty()) return -1;
    while (true) {
        int latest = -1, flag = 1;
        for (int i = 0; i < cor.size(); i++) {
            if (cor[i].empty()) {
                flag = 0;
                break;
            }
            latest = max(cor[i].front(), latest);
        }
        if (flag == 0) break;
        
        cnt++;
        for (int i = 0; i < cor.size(); i++) {
            while (!cor[i].empty() && cor[i].front() < latest) {
                cor[i].pop_front();
            }
        }
    }
    
    return cnt;
}

int main() {
    int n, m;
    char dele[1005][20] = {0}, access[5005][20] = {0};
    while (scanf("%d", &n) != EOF) {
        //printf("In loop\n");
        for (int i = 0; i < n; i++) {
            scanf("%s", dele[i]);
        }
        scanf("%d", &m);
        for (int i = 0; i < m; i++) {
            scanf("%s", access[i]);
        }
        
        vector<deque<int> > cor;
        vector<int> overlap;
        //printf("Input finish\n");
        handle(dele, n, access, m, cor, overlap);
        //printf("Handle finish\n");
        
        int ans = cal(cor, overlap);
        //printf("Cal finish\n");
        
        printf("%d\n", ans);
    }
    
    return 0;
}
