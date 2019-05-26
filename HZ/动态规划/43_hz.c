/*************************************************************************
	> File Name: 43_hz.c
	> Author: Lix
	> Mail: 776579471@qq.com
	> URL: https://github.com/JK-Lix
	> Created Time: 2019年05月26日 星期日 14时19分16秒
 ************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<inttypes.h>
#include<math.h>
#define MAX_N 1000

int f[MAX_N + 5][MAX_N + 5];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for(int j = 0; j <= i; j++) {
            scanf("%d", &f[i][j]);
        }
    }
    for (int i = n - 2; i >= 0; --i) {
        for (int j = 0; j <= i; j++) {
            f[i][j] += fmax(f[i + 1][j], f[i + 1][j + 1]);
        }
    }
    printf("%d", f[0][0]);
    return 0;
}
