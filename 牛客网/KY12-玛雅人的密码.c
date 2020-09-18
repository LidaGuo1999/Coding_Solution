/* 问题描述：玛雅人有一种密码，如果字符串中出现连续的2012四个数字就能解开密码。给一个长度为N的字符串，（2=<N<=13）该字符串中只含有0,1,2三种数字，问这个字符串要移位几次才能解开密码，每次只能移动相邻的两个数字。例如02120经过一次移位，可以得到20120,01220,02210,02102，其中20120符合要求，因此输出为1.如果无论移位多少次都解不开密码，输出-1。
 *
 * 输入描述：输入包含多组测试数据，每组测试数据由两行组成。
第一行为一个整数N，代表字符串的长度（2<=N<=13）。
第二行为一个仅由0、1、2组成的，长度为N的字符串。
 *
 * 输出描述：对于每组测试数据，若可以解出密码，输出最少的移位次数；否则输出-1。
 */

#include <stdio.h>
#include <string.h>

#define MAXSIZE 200000

typedef struct ps {
    char password[15];
    int len;
    int cost;
} ps;

int correct(ps p) {
    for (int i = 0; i+3 < p.len; i++) {
        if (p.password[i] == '2' && p.password[i+1] == '0' && p.password[i+2] == '1' && p.password[i+3] == '2')
            return 1;
    }
    
    return 0;
}

int bfs(char ori[15]) {
    int check[3] = {0};
    for (int i = 0; i < strlen(ori); i++) {
        check[ori[i]-'0']++;
        
    if (check[0] < 1 || check[1] < 1 || check[2] < 2) return -1;
    
    ps queue[MAXSIZE];
    int front = 0, end = 0;
    
    ps first;
    strcpy(first.password, ori);
    first.len = strlen(ori);
    first.cost = 0;
    queue[end++] = first;
    
    while (front != end) {
        ps tmp = queue[front++];
        if (correct(tmp)) return tmp.cost;
        for (int i = 0; i < tmp.len-1; i++) {
            char s = tmp.password[i];
            tmp.password[i] = tmp.password[i+1];
            tmp.password[i+1] = s;
            tmp.cost++;
            queue[end++] = tmp;
            
            s = tmp.password[i];
            tmp.password[i] = tmp.password[i+1];
            tmp.password[i+1] = s;
            tmp.cost--;
        }
    }
    
    return -1;
}

int main() {
    int n;
    char ori[15] = {0};
    while (scanf("%d", &n) != EOF) {
        scanf("%s", ori);
        int ans = bfs(ori);
        printf("%d\n", ans);
    }
    
    return 0;
}
