#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

#define maxn 100000

using namespace std;

int arr[maxn + 5],
    tree[maxn << 2];

void build_tree(int root, int tl, int tr) {
    if(tl == tr) {
        tree[root] = arr[tl];
    } else {
        int tmid = (tl + tr) / 2;
        build_tree(root * 2, tl, tmid);
        build_tree((root * 2) + 1, tmid + 1, tr);
        tree[root] = tree[root * 2] + tree[(root * 2) + 1];
    }
}

void add(int root, int tl, int tr, int val, int pos) {
    if(tl == tr) {
        tree[root] += val;
    } else {
        int tm = (tl + tr) / 2;
        if(tl <= pos && pos <= tm)
            add(root * 2, tl, tm, val, pos);
        else
            add((root * 2) + 1, tm + 1, tr, val, pos);
        tree[root] = tree[root * 2] + tree[(root * 2) + 1];
    }
}

int query(int root, int tl, int tr, int l, int r) {
    if(l > r) return 0;

    if(tl == l && tr == r) {
        return tree[root];
    }

    int tm = (tl + tr) / 2;
    return query(root * 2, tl, tm, l, min(tm, r)) + query((root * 2) + 1, tm + 1, tr, max(l, tm + 1), r);
}

int main() {
    //freopen("input.txt", "r", stdin);
    int T, n, q, cmd, x, y;

    scanf("%d", &T);

    for(int i = 1; i <= T; i++) {
        scanf("%d %d", &n, &q);
        for(int j = 0; j < n; j++) {
            scanf("%d", arr + j);
        }

        build_tree(1, 0, n - 1);
        printf("Case %d:\n", i);
        for(int j = 0; j < q; j++) {
            scanf("%d", &cmd);
            if(cmd == 1) {
                scanf("%d", &x);
                int temp = query(1, 0, n - 1, x, x);
                printf("%d\n", temp);
                add(1, 0, n - 1, temp * (-1), x);
            } else if(cmd == 2) {
                scanf("%d %d", &x, &y);
                add(1, 0, n - 1, y, x);
            } else {
                scanf("%d %d", &x, &y);
                printf("%d\n", query(1, 0, n - 1, x, y));
            }
        }
    }

    return 0;
}
