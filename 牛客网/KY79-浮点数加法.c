/* 问题描述：求2个浮点数相加的和 题目中输入输出中出现浮点数都有如下的形式： P1P2...Pi.Q1Q2...Qj 对于整数部分，P1P2...Pi是一个非负整数 对于小数部分，Qj不等于0
 *
 * 输入描述：对于每组案例，每组测试数据占2行，分别是两个加数
 *
 * 输出描述：每组案例是n行，每组测试数据有一行输出是相应的和。
输出保证一定是一个小数部分不为0的浮点数
 */


#include <stdio.h>
#include <string.h>

void cal(char p1[100005], char p2[100005]) {
    int n1 = strlen(p1), n2 = strlen(p2), dot1 = -1, dot2 = -1;
    for (int i = 0; i < n1; i++) {
        if (p1[i] == '.') {
            dot1 = i;
            break;
        }
    }
    for (int i = 0; i < n2; i++) {
        if (p2[i] == '.') {
            dot2 = i;
            break;
        }
    }

    int dec1 = n1-dot1-1, dec2 = n2-dot2-1;
    int dec = dec1>dec2 ? dec1 : dec2;
    int carry = 0;
    char decimal[100005] = {0};
    for (int i = dec; i >= 1; i--) {
        if (dec1 < i) {
            decimal[i] = (p2[dot2+i]-'0'+carry)%10+'0';
            if ((p2[dot2+i]-'0'+carry)/10 > 0) carry = 1;
            else carry = 0;
        } else if (dec2 < i) {
            decimal[i] = (p1[dot1+i]-'0'+carry)%10+'0';
            if ((p1[dot1+i]-'0'+carry)/10 > 0) carry = 1;
            else carry = 0;
        } else {
            decimal[i] = (p1[dot1+i]-'0'+p2[dot2+i]-'0'+carry)%10+'0';
            if ((p1[dot1+i]-'0'+p2[dot2+i]-'0'+carry)/10 > 0) carry = 1;
            else carry = 0;
        }
    }

    int ndec = dec;
    for (; ndec >= 0; ndec--) {
        if (decimal[ndec] != '0') break;
    }

    int inte1 = dot1, inte2 = dot2;
    int inte = inte1>inte2 ? inte1 : inte2;
    char integ[100005] = {0};
    for (int i = 1; i <= inte; i++) {
        if (inte1 < i) {
            integ[i] = (p2[dot2-i]-'0'+carry)%10+'0';
            if ((p2[dot2-i]-'0'+carry)/10 > 0) carry = 1;
            else carry = 0;
        } else if (inte2 < i) {
            integ[i] = (p1[dot1-i]-'0'+carry)%10+'0';
            if ((p1[dot1-i]-'0'+carry)/10 > 0) carry = 1;
            else carry = 0;
        } else {
            integ[i] = (p1[dot1-i]-'0'+p2[dot2-i]-'0'+carry)%10+'0';
            if ((p1[dot1-i]-'0'+p2[dot2-i]-'0'+carry)/10 > 0) carry = 1;
            else carry = 0;
        }
    }
    int ninte = inte;
    if (carry == 1) {
        integ[inte+1] = '1';
        ninte++;
    }

    for (int i = ninte; i >= 1; i--) {
        printf("%c", integ[i]);
    }
    printf(".");
    for (int i = 1; i <= ndec; i++) {
        printf("%c", decimal[i]);
    }
    printf("\n");

    return ;
}

int main() {
    char p1[100005], p2[100005];
    while (gets(p1) != NULL && gets(p2) != NULL) {
        cal(p1, p2);
        memset(p1, 0, sizeof(p1));
        memset(p2, 0, sizeof(p2));
    }

    return 0;
}
