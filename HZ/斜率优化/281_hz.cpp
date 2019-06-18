/*************************************************************************
	> File Name: new.cpp
	> Author: Lix
	> Mail: 776579471@qq.com
	> URL: https://github.com/JK-Lix
	> Created Time: 2019年06月18日 星期二 18时23分44秒
 ************************************************************************/

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <functional>
#include <iomanip>
#include <string>
using namespace std;
#define MAX_POOL 1000000
#define MAX_BASE 26

struct Node {
    int flag;
    int next[26];
} trie[MAX_POOL + 5];
int cnt = 1; //用掉的节点数,根节点为1号
int getNode() {
    return ++cnt;
}

void insert(int ind, const char *str) {
    int p = ind;
    for (int i = 0; str[i]; i++) {
        if (trie[p].next[str[i] - 'a'] == 0) {
            trie[p].next[str[i] - 'a'] = getNode();
        }
        p = trie[p].next[str[i] - 'a'];
    }
    trie[p].flag += 1;
    return ;
}

int query(int ind, const char *str) {
    int p = ind;
    int ans = 0;
    for (int i = 0; str[i]; i++) {
        if (p == 0) break;
        p = trie[p].next[str[i] - 'a'];
        ans += trie[p].flag;
    }
    return ans;
}

char str[MAX_POOL + 5];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> str;
        insert(1, str);
    }
    for (int i = 0; i < m; i++) {
        cin >> str;
        cout << query(1, str) << endl;
    }
    return 0;
}
