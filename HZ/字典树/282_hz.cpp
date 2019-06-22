/*************************************************************************
	> File Name: 282_hz.cpp
	> Author: Lix
	> Mail: 776579471@qq.com
	> URL: https://github.com/JK-Lix
	> Created Time: 2019年06月18日 星期二 18时35分53秒
 ************************************************************************/
#include<iostream>
#include<algorithm>
#include<climits>
#include<stdlib.h>
#include<math.h>
#include<string.h>
using namespace std;

#define MAX_POOL 3200000
struct Node {
    int next[3];
} tree[MAX_POOL + 5];

int cnt = 1;

int getNode() {
    return ++cnt;
}

void insert(int val) {
    int p = 1;
    for (int i = 30; i >= 0; i--) {
        int ind = ((val & (1 << i)) != 0);
        if (tree[p].next[ind] == 0) {
            tree[p].next[ind] = getNode();
        }
        p = tree[p].next[ind];
    }
    return;
}

int query(int val) {
    int ans = 0; 
    int p = 1;
    for (int i = 30; i >= 0; i--) {
        int ind = ((val & (1 << i)) != 0);
        if (tree[p].next[!ind]) {
            ans |= (1 << i);
            p = tree[p].next[!ind];
        } else {
            p = tree[p].next[ind];
        }
    }
    return ans;
}

int arr[100005];

int main () {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        insert(arr[i]);
    }
    int ans = 0, temp;
    for (int i= 0; i < n; i++) {
        temp = query(arr[i]);
        ans = max(ans, temp);
    }
    cout << ans << endl;
    return 0;
}
