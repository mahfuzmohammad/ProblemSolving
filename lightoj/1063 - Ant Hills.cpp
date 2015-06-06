#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

#define UNVISITED -1
#define _MAXN 100010
#define _MAXM 200000

using namespace std;

int         dfsNumberCounter = 0,
            dfsRoot,
            rootChildren;

int         dfs_num[_MAXN],
            dfs_low[_MAXN],
            dfs_parent[_MAXN];

vector<int> adj[_MAXN];

bool        articulation_vertex[_MAXN];

void reset () {

    dfsNumberCounter = 0;
    dfsRoot = -1;
    rootChildren = 0;

    memset(dfs_num, UNVISITED, sizeof(dfs_num));
    memset(dfs_low, 0, sizeof(dfs_low));
    memset(dfs_parent, 0, sizeof(dfs_parent));
    memset(articulation_vertex, false, sizeof(articulation_vertex));

    for (int i = 0; i < _MAXN; i++) { adj[i].clear(); }

}

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
                articulation_vertex[u] = true;
            }

            if (dfs_low[v] > dfs_num[u]) {
                //print bridges
            }

            dfs_low[u] = min( dfs_low[u], dfs_low[v] );

        } else if ( v != dfs_parent[u] )
            dfs_low[u] = min( dfs_low[u], dfs_num[v] );

    }

}


int main () {

    int T, n, m,
        a, b;

    cin >> T;

    for (int i = 1; i <= T; i++) {

        reset();
        cin >> n >> m;

        for (int j = 0; j < m; j++) {
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        for (int j = 1; j <= n; j++) {
            if (dfs_num[j] == UNVISITED) {
                dfsRoot = j;
                rootChildren = 0;
                articulationPoinAndBridge(j);
                articulation_vertex[dfsRoot] = (rootChildren > 1);
            }
        }

        int numOfArticulationPoint = 0;

        for(int j = 1; j <= n; j++) {
            if (articulation_vertex[j])
                numOfArticulationPoint++;
        }

        cout << "Case " << i << ": " << numOfArticulationPoint << endl;

    }

    return 0;

}
