/*************************************************************************
	> File Name: 255_hz.cpp
	> Author: Lix
	> Mail: 776579471@qq.com
	> URL: https://github.com/JK-Lix
	> Created Time: 2019年06月18日 星期二 19时44分02秒
 ************************************************************************/
#include<iostream>
#include<algorithm>
#include<climits>
#include<stdlib.h>
#include<math.h>
#include<string.h>
using namespace std;
#define MAX_N 1000
struct Range {
    double l, r;
} arr[MAX_N + 5];

bool cmp(const Range &a, const Range &b) {
    return a.r < b.r;
}

int main() {
    int n;
    double d;
    int flag = 0;
    cin >> n >> d;
    for (int i = 0; i < n; i++) {
        double x, y;
        cin >> x >> y;
        if (y > d) flag = 1;
        arr[i].l = x - sqrt(d * d - y * y);
        arr[i].r = x + sqrt(d * d - y * y);
    }
    if (flag) {
        cout << -1 << endl;
        return 0;
    }
    sort(arr, arr + n, cmp);
    double p = arr[0].r;
    int cnt = 1;
    for (int i = 1; i < n; i++) {
        if (arr[i].l > p) {
            cnt += 1;
            p = arr[i].r;
        }
    }
    cout << cnt << endl;
}
