/*************************************************************************
	> File Name: 49_hz_better.c
	> Author: Lix
	> Mail: 776579471@qq.com
	> URL: https://github.com/JK-Lix
	> Created Time: 2019年05月26日 星期日 19时22分09秒
*************************************************************************/

//多重背包的动态滑动窗口法
//即相对静态，减去等比数列即可，然后取值加上相对静态偏移量

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<inttypes.h>
#include<math.h>

#define MAX_V 100000
#define MAX_N 100

int dp[MAX_V + 5];
int val[MAX_N + 5], wgh[MAX_N + 5], cnt[MAX_N + 5];

typedef struct Node {
    int v, w;
} Node;

Node q[MAX_V + 5];
int head = 0, tail = 0;

int main() {
    int w, n;
    scanf("%d%d", &w, &n);
    for (int i = 0; i < n; i++) scanf("%d%d%d", &wgh[i], &val[i], &cnt[i]);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < wgh[i]; j++) {
            head = tail = 0;
            for (int k = j; k <= w; k += wgh[i]) {
                Node d = {k, dp[k] - k / wgh[i] * val[i]};
                while (tail > head && d.w > q[tail - 1].w) tail--;
                q[tail++] = d;
                if ((k - q[head].v) / wgh[i] > cnt[i]) head++;
                dp[k] = q[head].w + k / wgh[i] * val[i];
            }
        }
    }
    printf("%d", dp[w]);
    return 0;
}
