/* 问题描述：将一个长度最多为30位数字的十进制非负整数转换为二进制数输出。
 *
 * 输入描述：多组数据，每行为一个长度不超过30位的十进制非负整数。
（注意是10进制数字的个数可能有30个，而非30bits的整数）
 * 
 * 输出描述：每行输出对应的二进制数。
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void cal(char num[40], char ans[500], char half[40]) {
    if (strlen(num) == 1 && num[0] == '0') {
        ans[0] = '0';
        return ;
    }
    
    int cnt = 0;
    while (strlen(num) > 1 || (strlen(num) == 1 && num[0] != '1')) {
        //printf("%s %s\n", num, half);
        int flag = 0, tmp = 0, quo = 0, remain = 0;
        for (int i = 0; i < strlen(num); i++) {
            if (num[i] != '0') {
                flag = 1;
                break;
            }
        }
        if (flag == 0) break;
        
        int n = strlen(num);
        for (int i = 0; i < n; i++) {
            tmp = tmp*10+num[i]-'0';
            quo = tmp/2;
            remain = tmp%2;
            half[i] = '0'+quo;
            tmp = remain;
        }
        ans[cnt] = remain+'0';
        cnt++;
        strcpy(num, half);
        memset(half, 0, sizeof(half));
    }
    
    if (num[0] == '1') ans[cnt] = '1';
    return ;
}

int main() {
    char num[40] = {0};
    while (scanf("%s", num) != EOF) {
        char ans[500] = {0}, half[40] = {0};
        cal(num, ans, half);
        for (int i = strlen(ans)-1; i >= 0; i--) printf("%c", ans[i]);
        printf("\n");
    }
    
    return 0;
}
