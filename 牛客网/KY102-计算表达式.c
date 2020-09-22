/* 问题描述：对于一个不存在括号的表达式进行计算
 *
 * 输入描述存在多种数据，每组数据一行，表达式不存在空格：
 * 
 * 输出描述：输出结果
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

typedef struct unit {
    int type;
    double val;
    char o;
} unit;

int poland(char expr[1005], unit nums[1000]) {
    int m = 0, len = strlen(expr), num = 0, cnt = 0;
    unit oper[1000];
    int top = -1;

    memset(oper, 0, sizeof(oper));
    for (int i = 0; i < len; i++) {
        if (i == 0 && expr[i] == '-') m = 1;
        else m = 0;

        if (expr[i] >= '0' && expr[i] <= '9') {
            num = num*10+expr[i]-'0';
        } else {
            if (m == 1) num = -num;
            nums[cnt].type = 1;
            nums[cnt].val = num;
            num = 0;
            cnt++;

            unit tmp;
            tmp.type = 2;
            tmp.o = expr[i];
            if (expr[i] == '*' || expr[i] == '/') tmp.val = 2;
            else tmp.val = 1;

            while (top > -1 && tmp.val <= oper[top].val) {
                nums[cnt] = oper[top];
                cnt++;
                top--;
            }
            top++;
            oper[top] = tmp;
        }
    }
    nums[cnt].type = 1;
    nums[cnt].val = num;
    cnt++;

    while (top > -1) {
        nums[cnt] = oper[top];
        cnt++;
        top--;
    }

    return cnt;
}

int calculate(unit nums[1000], int len) {
    unit s[1000];
    int top = -1;
    memset(s, 0, sizeof(s));
    for (int i = 0; i < len; i++) {
        if (nums[i].type == 1) {
            s[++top] = nums[i];
        } else if (nums[i].type == 2) {
            if (nums[i].o == '+') {
                s[top-1].val += s[top].val;
                top--;
            } else if (nums[i].o == '-') {
                s[top-1].val -= s[top].val;
                top--;
            } else if (nums[i].o == '*') {
                s[top-1].val *= s[top].val;
                top--;
            } else if (nums[i].o == '/') {
                s[top-1].val /= s[top].val;
                top--;
            }
        }
    }

    return round(s[0].val);
}

int main() {
    char expr[1005] = {0};
    unit nums[1000];
    while (scanf("%s", expr) != EOF) {
        memset(nums, 0, sizeof(nums));
        int len = poland(expr, nums);
        int ans = calculate(nums, len);
        printf("%d\n", ans);
    }

    return 0;
}
