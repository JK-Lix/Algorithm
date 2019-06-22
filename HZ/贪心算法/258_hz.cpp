/*************************************************************************
	> File Name: 258_hz.cpp
	> Author: Lix
	> Mail: 776579471@qq.com
	> URL: https://github.com/JK-Lix
	> Created Time: 2019年06月20日 星期四 19时48分26秒
 ************************************************************************/

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <functional>
#include <iomanip>
#include <string>
using namespace std;
#define MAX_N 100
int g[MAX_N + 5][MAX_N + 5];

int main() {
    int n, ans = -128;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> g[i][j];
            ans = max(ans, g[i][j]);
            g[i][j] += g[i - 1][j];
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = i; j <= n; j++) {
            int sum = 0, pre_min = 0;//pre_min：s[i]前缀最小值
            for (int k = 1; k <= n; k++) {
                sum += g[j][k] - g[i - 1][k];
                ans = max(ans,sum - pre_min);
                pre_min = min(pre_min, sum);
            }
        }
    }
    cout << ans << endl;
    return 0;
}
