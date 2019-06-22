/*************************************************************************
	> File Name: 256_hz.cpp
	> Author: Lix
	> Mail: 776579471@qq.com
	> URL: https://github.com/JK-Lix
	> Created Time: 2019年06月20日 星期四 19时57分54秒
 ************************************************************************/
#include<iostream>
#include<algorithm>
#include<climits>
#include<stdlib.h>
#include<math.h>
#include<string.h>
using namespace std;

#define MAX_N 1000
struct Data {
    int a, b;
} arr[MAX_N + 5];

bool cmp(const Data &a, const Data &b) {
    return a.a * a.b < b.a * b.b;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i <= n; i++) cin >> arr[i].a >> arr[i].b;
    sort(arr + 1, arr + 1 + n, cmp);
    int p = arr[0].a, ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(p / arr[i].b, ans);
        p *= arr[i].a;
    }
    cout << ans << endl;
    return 0;
}

