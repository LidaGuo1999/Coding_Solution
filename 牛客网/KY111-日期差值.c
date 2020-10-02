/*
 *
 * 思路梳理：
 * 1、代码的写法是首先确定两个日期谁大，然后大的日期减去小的日期，注意闰年的操作即可；
 * 2、但其实我们只需要都和0年1月1日比，然后两个差值再相减并取绝对值即可，能够省去比较的步骤；
 * 3、同时，由于输入规定为yyyymmdd，所以用scanf的%xd就可以读入整数，不需要后续自己进行转换；
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct da {
    int year, month, day;
} da;

int cnt[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

void order(da *d1, da *d2) {
    int flag = 0;
    if (d1->year == d2->year) {
        if (d1->month == d2->month) {
            if (d1->day <= d2->day) {
                
            } else {
                flag = 1;
            }
        } else {
            if (d1->month > d2->month) {
                flag = 1;
            }
        }
    } else {
        if (d1->year > d2->year) {
            flag = 1;
        }
    }

    if (flag == 1) {
        int tmp = d1->year;
        d1->year = d2->year, d2->year = tmp;
        tmp = d1->month, d1->month = d2->month, d2->month = tmp;
        tmp = d1->day, d1->day = d2->day, d2->day = tmp;
    }
    return ;
}

int cal_gap(da *da1, da *da2) {
    int y = 0, m = 0, d = 0, gap = 0, gap1 = 0, gap2 = 0;
    for (int i = da1->year+1; i <= da2->year; i++) {
        if ((i%100 == 0 && i%400 == 0) || (i%100 != 0 && i%4 == 0)) {
            gap += 366;
        } else {
            gap += 365;
        }
    }
    
    for (int i = da1->month+1; i <= 12; i++) {
        gap1 += cnt[i];
    }
    gap1 += cnt[da1->month]-da1->day;
    int j = da1->year;
    if ((j%100 == 0 && j%400 == 0) || (j%100 != 0 && j%4 == 0)) {
        if (da1->month <= 2) gap1 += 1;
    }

    for (int i = da2->month+1; i <= 12; i++) {
        gap2 += cnt[i];
    }
    gap2 += cnt[da2->month]-da2->day;
    j = da2->year;
    if ((j%100 == 0 && j%400 == 0) || (j%100 != 0 && j%4 == 0)) {
        if (da2->month <= 2) gap2 += 1;
    }

    gap += gap1-gap2+1;
    return gap;
}

int main() {
    char ar1[10] = {0}, ar2[10] = {0};
    da da1, da2;
    while (scanf("%s %s", ar1, ar2) != EOF) {
        int y1 = 0, y2 = 0, m1 = 0, m2 = 0, d1 = 0, d2 = 0;
        for (int i = 0; i < 4; i++) {
            y1 = y1*10+ar1[i]-'0';
            y2 = y2*10+ar2[i]-'0';
        }
        for (int i = 4; i < 6; i++) {
            m1 = m1*10+ar1[i]-'0';
            m2 = m2*10+ar2[i]-'0';
        }
        for (int i = 6; i < 8; i++) {
            d1 = d1*10+ar1[i]-'0';
            d2 = d2*10+ar2[i]-'0';
        }
        da1.year = y1, da1.month = m1, da1.day = d1;
        da2.year = y2, da2.month = m2, da2.day = d2;

        order(&da1, &da2);
        int ans = cal_gap(&da1, &da2);
        printf("%d\n", ans);
    }

    return 0;
}
