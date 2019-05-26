/*************************************************************************
	> File Name: 48_hz.c
	> Author: Lix
	> Mail: 776579471@qq.com
	> URL: https://github.com/JK-Lix
	> Created Time: 2019年05月26日 星期日 18时47分20秒
 ************************************************************************/

//完全背包

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<inttypes.h>
#include<math.h>

#define MAX_V 10000
#define MAX_N 10000

int dp[MAX_V + 5];
int val[MAX_N + 5], wgh[MAX_N + 5];

int main() {
    int w, n;
    scanf("%d%d", &n, &w);
    for (int i = 1; i <= n; i++) scanf("%d%d", &wgh[i], &val[i]);
    for (int i = 1; i <= n; i++) {
        for (int j = wgh[i]; j <= w; j++) {
            dp[j] = fmax(dp[j], dp[j - wgh[i]] + val[i]);
        }
    }
    printf("%d", dp[w]);
    return 0;
}
