/*************************************************************************
	> File Name: 44_hz.c
	> Author: Lix
	> Mail: 776579471@qq.com
	> URL: https://github.com/JK-Lix
	> Created Time: 2019年05月26日 星期日 14时59分35秒
 ************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<inttypes.h>
#include<math.h>
#define MAX_N 1000000

int dp[MAX_N + 5];
int len[MAX_N  + 5];
int val[MAX_N + 5];

int binary(int *arr, int n, int x) {
    int head = 0, tail = n, mid;
    while (head < tail) {
        mid = (head + tail) >> 1;
        if (arr[mid] >= x) tail = mid;
        else head = mid + 1;
    }
    return head;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &val[i]);
    dp[0] = 1;
    len[0] = 0;
    len[1] = val[0];
    int ans = 1;
    for (int i = 1; i < n; i++) {
        len[ans + 1] = val[i] + 1;
        dp[i] = binary(len, ans + 1, val[i]);
        len[dp[i]] = val[i];
        ans = fmax(ans, dp[i]);
    }
    printf("%d", ans);
    return 0;
}
