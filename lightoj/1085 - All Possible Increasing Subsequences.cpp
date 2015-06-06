#include <bits/stdc++.h>

using namespace std;

#define LOGSZ 17
#define ll long long
#define _MOD 1000000007
#define ii pair<ll, ll>

int N;
map<int, int> m;
ll tree[(1<<LOGSZ)+1];
ll arr[100009];

// add v to value at x
void add(int x, ll v) {
    while(x <= N) {
        tree[x] += v;
        tree[x] %= _MOD;
        x += (x & -x);
    }
}

// get cumulative sum up to and including x
int get(int x) {
    if(x <= 0) return 0;

    ll res = 0;
    while(x) {
        res += tree[x];
        res %= _MOD;
        x -= (x & -x);
    }

    return res;
}

void reset() {
    m.clear();
    memset(tree, 0, sizeof tree);
    memset(arr, 0, sizeof arr);
}

int main() {
    //freopen("in.txt", "r", stdin);
    int t, n;

    scanf("%d", &t);

    for (int i = 1; i <= t; i++) {
        reset();
        scanf("%d", &n);
        N = n;

        for(int j = 0; j < n; j++) {
            scanf("%d", &arr[j]);
            m[arr[j]] = 0;
        }

        int indx = 1;
        map<int, int>::iterator it;
        for (it = m.begin(); it != m.end(); it++) {
            it->second = indx++;
        }

        for(int j = 0; j < n; j++) {
            arr[j] = m[arr[j]];
        }

        for(int j = 0; j < n; j++) {
            ll temp = get(arr[j] - 1);
            add( arr[j], temp + 1 );
        }

        int res = get(indx - 1);

        printf("Case %d: %d\n", i, res);
    }

    return 0;
}
