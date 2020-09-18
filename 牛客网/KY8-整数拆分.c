/*
 *
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

const int m = 1000000000;

int cal_layer(int n) {
    int layer = 1, two = 2;
    while (1) {
        if (n >= two) {
            two = two << 1;
            layer++;
        } else break;
    }
    
    return layer;
}

int main() {
    int n;
    int dp[1000005];
    while (scanf("%d", &n) != EOF) {
        memset(dp, 0, sizeof(dp));
        int layer = cal_layer(n);
        
        for (int i = 0; i <= n; i++) 
            dp[i] = 1;
        
        for (int i = 1; i < layer; i++) {
            int start = pow(2, i);
            for (int j = start; j <= n; j++) {
                dp[j] += dp[j-start]%m;
                dp[j] %= m;
            }
        }
        
        printf("%d\n", dp[n]);
    } 
    
    return 0;
}
