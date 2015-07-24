#include <bits/stdc++.h>

using namespace std;

vector<int> edge[105];
bool visited[2][105];

void cnt(bool koleache, int node) {
    if(visited[koleache][node]) return;
    visited[koleache][node] = true;

    for(int i = 0; i < edge[node].size(); i++) {
        cnt(!koleache, edge[node][i]);
    }
}

void reset() {
    memset(visited, 0, sizeof visited);
    for(int i = 0; i <= 100; i++) {
        edge[i].clear();
    }
}

int main() {
    //freopen("in.txt", "r", stdin);
    int t, n, e, u, v;
    scanf("%d", &t);

    for(int i = 1; i <= t; i++) {
        reset();
        scanf("%d %d", &n, &e);
        for(int j = 0; j < e; j++) {
            scanf("%d %d", &u, &v);
            edge[u].push_back(v);
            edge[v].push_back(u);
        }

        int ans = 0;
        for(int j = 0; j < edge[1].size(); j++) {
            cnt(false, edge[1][j]);
        }

        for(int j = 1; j <= n; j++) {
            //cerr << visited[0][j] << " " << visited[1][j] << endl;
            ans += visited[1][j];
        }

        printf("Case %d: %d\n", i, ans);
    }

    return 0;
}
