/*************************************************************************
	> File Name: 50_hz.c
	> Author: Lix
	> Mail: 776579471@qq.com
	> URL: https://github.com/JK-Lix
	> Created Time: 2019年05月26日 星期日 20时20分27秒
 ************************************************************************/

//dp(i, j)最坏最少，i个鸡蛋j层楼的次数
//dp(i, j) = min(max(dp[i][j - k], dp[i - 1][k - 1])) + 1
//第一次扔鸡蛋选择的是第k层楼
//               max____________最坏_________________
//           min____________最少次数的最坏情况_______
//秘籍优化：值和状态互换————前提：相关（同增同减）
//      dp(i, k) = j   i个鸡蛋扔k次可以测j层楼
//      dp(i, k) = 1 + dp(i - 1, k - 1) + dp(i, k - 1);

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<inttypes.h>

#define MAX_N 32
#define MAX_M 65536

long long dp[MAX_N + 5][MAX_M + 5];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    if (n == 1) {
        printf("%d", m);
        return 0;
    }
    for (int i = 2; i <= n; i++) {
        for (int j = 1; dp[i][j - 1] < m; j++) {
            long long val;
            if (i - 1 == 1) val = j - 1;
            else val = dp[i - 1][j - 1];
            dp[i][j] = 1 + val + dp[i][j - 1];
        }
    }
    long long k = 1;
    while (dp[n][k] < m) k++;
    printf("%lld", k);
    return 0;
}
