/*************************************************************************
	> File Name: a.c
	> Author: Lix
	> Mail: 776579471@qq.com
	> URL: https://github.com/JK-Lix
	> Created Time: 2019年05月25日 星期六 20时54分14秒
 ************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<inttypes.h>

int main() {
    int n;
    int f[3][1000] = {0};
    scanf("%d", &n);
    f[1][0] = f[2][0] = 1;
    f[1][1] = 1, f[2][1] = 2;
    for (int i = 3; i <= n; i++) {
        int a = (i - 1) % 3, b = (i - 2) % 3, c = i % 3;
        for (int j = 1; j <= f[a][0]; j++) f[c][j] = f[a][j] + f[b][j];
        f[c][0] = f[a][0];
        for (int j = 1; j <= f[c][0]; j++) {
            if (f[c][j] < 10) continue;
            f[c][j + 1] += f[c][j] / 10;
            f[c][j] %= 10;
            f[c][0] += (j == f[c][0]);
        }
    }
    for (int i = f[n % 3][0]; i >= 1; --i) printf("%d", f[n % 3][i]);
    printf("\n");
    return 0;
 }
