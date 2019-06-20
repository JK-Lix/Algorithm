/*************************************************************************
	> File Name: 253_hz.cpp
	> Author: Lix
	> Mail: 776579471@qq.com
	> URL: https://github.com/JK-Lix
	> Created Time: 2019年06月18日 星期二 19时07分45秒
 ************************************************************************/

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <functional>
#include <iomanip>
#include <string>
using namespace std;
//贪心
//区间问题三种情况
#define MAX_N 2500
struct Range {
    int l, r;
} arr[MAX_N + 5], item[MAX_N + 5];

bool cmp(const Range &a, const Range &b) {
    return a.r < b.r;
}

int main() {
    int n, l;
    cin >> n >> l;
    for (int i = 0; i < n; i++) {
        cin >> arr[i].l >> arr[i].r;
    }
    for (int i = 0; i < l; i++) {
        cin >> item[i].l >> item[i].r;
    }
    sort(arr, arr + n, cmp);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int flag = 0; //奶牛是否有防晒霜
        int ind = -1;
        for (int j = 0; j < l; j++) {
            if (item[j].r == 0) continue;
            if (item[j].l < arr[i].l || item[j].l > arr[i].r) continue;
            if (ind == -1) {
                ind = j;
                flag = 1;
                continue;
            }
            if (item[j].l < item[ind].l) ind = j; //选择低等级防晒霜
        }
        if (flag) item[ind].r -= 1;
        ans += flag;
    }
    cout << ans << endl;
    return 0;
}
