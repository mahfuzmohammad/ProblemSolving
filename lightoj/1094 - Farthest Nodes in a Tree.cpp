#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <algorithm>

#define MAXN 30000
#define INF 1000000000

using namespace std;

vector<int> edges[MAXN + 5], costs[MAXN + 5];
long long mincost[MAXN + 5];

void minCostReset()
{
    for(int i = 0; i <= MAXN; i++){
        mincost[i] = INF;
    }
}

void reset()
{
    for(int i = 0; i <= MAXN; i++){
        mincost[i] = INF;
        edges[i].clear();
        costs[i].clear();
    }
}

typedef struct {
    long long maxCost, node;
} Obj;

Obj Bfs(int i){
    Obj o;
    o.maxCost = 0; o.node = i;
    mincost[i] = 0;
    queue<int> q;
    q.push(i);

    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int j = 0; j < edges[u].size(); j++){
            if(costs[u][j] + mincost[u] < mincost[edges[u][j]]){
                mincost[edges[u][j]] = costs[u][j] + mincost[u];
                if(o.maxCost < mincost[edges[u][j]]){
                    o.maxCost = mincost[edges[u][j]];
                    o.node = edges[u][j];
                }
                q.push(edges[u][j]);
            }
        }
    }

    minCostReset();

    return o;
}


int main()
{
    //freopen("input.txt", "r", stdin);
    int T, N, u, v, w;
    cin >> T;

    for(int i = 1; i <= T; i++){
        reset();
        cin >> N;

        for(int j = 1; j < N; j++){
            cin >> u >> v >> w;
            edges[u].push_back(v);
            edges[v].push_back(u);
            costs[u].push_back(w);
            costs[v].push_back(w);
        }

        cout << "Case " << i << ": " << Bfs(Bfs(0).node).maxCost << endl;
    }


    return 0;
}
