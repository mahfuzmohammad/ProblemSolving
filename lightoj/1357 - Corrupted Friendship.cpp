#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
vector<int> edge[100005];
ll cnt[100005];
bool visited[100005];

ll dfs(int x) {
    visited[x] = true;
    for(int i = 0; i < edge[x].size(); i++) {
        cnt[x] += 1L + dfs(edge[x][i]);
    }

    return cnt[x];
}

void reset() {
    for(int i = 0; i <= 100000; i++) {
        edge[i].clear();
        cnt[i] = 0;
        visited[i] = false;
    }
}

int main() {
    //freopen("in.txt", "r", stdin);
    int t, n, u, v;
    scanf("%d", &t);

    for(int i = 1; i <= t; i++) {
        reset();
        scanf("%d", &n);
        for(int j = 1; j < n; j++) {
            scanf("%d %d", &u, &v);
            edge[u].push_back(v);
        }

        ll temp = dfs(1);
        ll ans = (ll)n*(ll)(n-1);
        ans >>= 1;
        int invited = 0;
        for(int j = 1; j <= n; j++) {
            invited += visited[j];
            ans -= (ll)cnt[j];
        }

        printf("Case %d: %d %lld\n", i, invited-1, ans);
    }

    return 0;
}
