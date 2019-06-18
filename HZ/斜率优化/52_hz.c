/*************************************************************************
	> File Name: glddzj.c
	> Author: Lix
	> Mail: 776579471@qq.com
	> URL: https://github.com/JK-Lix
	> Created Time: 2019年05月26日 星期日 21时55分15秒
 ************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<inttypes.h>

#define MAX_N 1000000
#define ll long long
ll c[MAX_N + 5], sum[MAX_N + 5];
ll f[MAX_N + 5], dp[MAX_N + 5];
ll q[MAX_N + 5], head = 0, tail = 0;
ll n, m;

void set(int i, int j) {
    dp[i] = dp[j] + (sum[i] - sum[j]) * (sum[i] - sum[j]) + m;
    f[i] = dp[i] + sum[i] * sum[i];
}

double slope(int i, int j) {
    return 1.0 * (f[j] - f[i]) / (sum[j] - sum[i]);
}

int main() {
    scanf("%lld%lld", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &c[i]);
        sum[i] = sum[i - 1] + c[i];
    }
    set(1, 0);
    q[tail++] = 0; //单调队列初始化
    for (int i = 1; i <= n; i++) {
        while (tail - head >= 2 && 2 * sum[i] >= slope(q[head], q[head + 1])) ++head;
        set(i, q[head]);
        while (tail - head >= 2 && slope(q[tail - 1], i) <= slope(q[tail - 2], q[tail - 1])) --tail;
        q[tail++] = i;
    }
    printf("%lld", dp[n]);
    return 0;
}
