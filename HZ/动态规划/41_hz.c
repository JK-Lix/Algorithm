/*************************************************************************
	> File Name: s.c
	> Author: Lix
	> Mail: 776579471@qq.com
	> URL: https://github.com/JK-Lix
	> Created Time: 2019年05月25日 星期六 21时07分28秒
 ************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<inttypes.h>
#include<math.h>

int f[1005];

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    int a = 1, b = k - 1;
    int f[1000] = {0};
    f[0] = f[1] = 1;
    if (n & 1) a = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= f[0]; j++) f[j] *= b;
        for (int j = 1; j <= f[0]; j++) {
            if (f[j] < 10) continue;
            f[j + 1] += f[j] / 10;
            f[j] %= 10;
            f[0] += (j == f[0]);
        }
    }
    a *= (k - 1);
    f[1] += a;
    for (int j = 1; j <= f[0]; j++) {
        if (f[j] < 10) continue;
        f[j + 1] += f[j] / 10;
        f[j] %= 10;
        f[0] += (j == f[0]);
    }
    for (int i = f[0]; i >= 1; --i) printf("%d", f[i]);
    return 0;
}
