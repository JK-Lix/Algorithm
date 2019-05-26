/*************************************************************************
	> File Name: louti.c
	> Author: Lix
	> Mail: 776579471@qq.com
	> URL: https://github.com/JK-Lix
	> Created Time: 2019年05月25日 星期六 23时06分51秒
 ************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<inttypes.h>
 int f[500][300];
int main() {
    int n;
    scanf("%d", &n);
   
    f[0][1] = 1;
    f[1][1] = 0;
    f[2][1] = 1;
    f[0][0] = f[1][0] = f[2][0] = 1;
    if (n == 1) {
        printf("%d", 0);
        return 0;
    }
    for (int i = 3; i <= n; i++) {
        int a = i - 3, b = i - 2;
        for (int j = 1; j <= f[b][0]; j++) f[i][j] = f[a][j] + f[b][j];
        f[i][0] = f[b][0];
        for (int j = 1; j <= f[i][0]; j++) {
            if (f[i][j] < 10) continue;
            f[i][j + 1] += f[i][j] / 10;
            f[i][j] %= 10;
            f[i][0] += (j == f[i][0]);
        }
    }
    for (int i = f[n][0]; i >= 1; --i) printf("%d", f[n][i]);
    return 0;
}
