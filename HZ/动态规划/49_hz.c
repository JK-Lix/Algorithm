/*************************************************************************
	> File Name: 49_hz.c
	> Author: Lix
	> Mail: 776579471@qq.com
	> URL: https://github.com/JK-Lix
	> Created Time: 2019年05月26日 星期日 18时55分35秒
 ************************************************************************/

//多重背包
//将多个物品拆分合并
//形成别可拼合成最多的数的数进行筛选
//——————多重背包的二进制分解法

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<inttypes.h>
#include<math.h>

#define MAX_V 100000
#define MAX_N 100

int dp[MAX_V + 5];
int val[MAX_N + 5], wgh[MAX_N + 5], cnt[MAX_N + 5];

int main() {
    int w, n;
    scanf("%d%d", &w, &n);
    for (int i = 1; i <= n; i++) scanf("%d%d%d", &wgh[i], &val[i], &cnt[i]);
    for (int i = 1; i <= n; i++) {
        int k = 1;
        while (cnt[i]) {
            for (int j = w; j >= wgh[i] * k; --j) {
                dp[j] = fmax(dp[j], dp[j - wgh[i] * k] + val[i] * k);
            }
            cnt[i] -= k;
            k = fmin(2 * k, cnt[i]);
        }
    }
    printf("%d", dp[w]);
    return 0;
}

