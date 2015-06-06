#include <bits/stdc++.h>

#define _MAXN 10000
#define ii pair<int, int>
#define UNVISITED -1

using namespace std;

int         dfs_low[_MAXN + 5],
            dfs_num[_MAXN + 5],
            dfs_parent[_MAXN + 5];

//bool        articulation_vertex[_MAXN + 5];

int         dfsNumberCounter = 0,
            dfsRoot,
            rootChildren;

vector<ii>  bridge;
vector<int> adj[_MAXN + 5];

void articulationPoinAndBridge (int u) {

    dfs_low[u] = dfsNumberCounter;
    dfs_num[u] = dfsNumberCounter;
    dfsNumberCounter++;

    for (int j = 0; j < adj[u].size(); j++) {

        int  v = adj[u][j];
        if ( dfs_num[v] == UNVISITED ) {

            dfs_parent[v] = u;
            if( u == dfsRoot ) rootChildren++;

            articulationPoinAndBridge(v);

            if (dfs_low[v] >= dfs_num[u]) {
                //articulation_vertex[u] = true;
            }

            if (dfs_low[v] > dfs_num[u]) {
                bridge.push_back(ii(min(u,v), max(u,v)));
            }

            dfs_low[u] = min( dfs_low[u], dfs_low[v] );

        } else if ( v != dfs_parent[u] )
            dfs_low[u] = min( dfs_low[u], dfs_num[v] );

    }

}

bool asc(ii a, ii b) {
    if (a.first == b.first) return (a.second < b.second);
    return (a.first < b.first);
}

void reset() {

    bridge.clear();
    dfsNumberCounter = 0;
    dfsRoot = -1;
    rootChildren = 0;

    memset(dfs_num, UNVISITED, sizeof(dfs_num));
    memset(dfs_low, 0, sizeof(dfs_low));
    memset(dfs_parent, 0, sizeof(dfs_parent));
//    memset(articulation_vertex, false, sizeof(articulation_vertex));

    for (int i = 0; i < _MAXN; i++) { adj[i].clear(); }

}

int main() {
    //freopen("input.txt", "r", stdin);
    int T, n, u, k, v;
    scanf("%d", &T);

    for (int i = 1; i <= T; i++) {
        reset();
        scanf("%d", &n);

        for (int j = 0; j < n; j++) {
            scanf("%d (%d) ", &u, &k);
            for (int l = 0; l < k; l++) {
                scanf("%d", &v);
                adj[u].push_back(v);
            }
        }

        for (int j = 1; j <= n; j++) {
            if (dfs_num[j] == UNVISITED) {
                dfsRoot = j;
                rootChildren = 0;
                articulationPoinAndBridge(j);
//                articulation_vertex[dfsRoot] = (rootChildren > 1);
            }
        }

//        int numOfArticulationPoint = 0;
//
//        for(int j = 1; j <= n; j++) {
//            if (articulation_vertex[j])
//                numOfArticulationPoint++;
//        }

        sort(bridge.begin(), bridge.end(), asc);

        printf("Case %d:\n%d critical links\n", i, bridge.size());
        for (int j = 0; j < bridge.size(); j++) {
            printf("%d - %d\n", bridge[j].first, bridge[j].second);
        }
    }

    return 0;
}
