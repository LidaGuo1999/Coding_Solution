/* 
 *
 *
 *
 */


#include <stdio.h>

int cal(int num) {
    int cnt = 0;
    for (int i = 1; i*i <= num; i++) {
        if (i*i == num) cnt++;
        else if (num%i == 0) cnt += 2;
    }
    
    return cnt;
}

int main() {
    int n, num;
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; i++) {
            scanf("%d", &num);
            int ans = cal(num);
            printf("%d\n", ans);
        }
    }
    
    return 0;
}
