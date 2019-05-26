/*************************************************************************
	> File Name: qianbi.c
	> Author: Lix
	> Mail: 776579471@qq.com
	> URL: https://github.com/JK-Lix
	> Created Time: 2019年05月25日 星期六 23时36分33秒
 ************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<inttypes.h>
#include <math.h>

int f[10006][1006];
int main() {
    int m, n, t;
    f[0][1] = f[0][0] = 1;
    scanf("%d%d", &m, &n);
    for (int i = 0; i < m; i++) {
        scanf("%d", &t);
        for (int j = t; j <= n; j++) {
            f[j][0] = fmax(f[j - t][0], f[j][0]);
            for (int k = 1; k <= f[j][0]; k++) f[j][k] += f[j - t][k];
            for (int k = 1; k <= f[j][0]; k++) {
                if (f[j][k] < 10) continue;
                f[j][k + 1] += f[j][k] / 10;
                f[j][k] %= 10;
                f[j][0] += (k == f[j][0]);
            }
        }
    }
    int ans = 0, c = 9973;
    for(int i = f[n][0]; i >= 1; --i) {
        ans = ((ans * 10) + f[n][i]) % c;
    }
    printf("%d", ans);
    return 0;
}
