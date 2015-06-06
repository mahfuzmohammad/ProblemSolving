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
long long tempMinCost[MAXN + 5];
long long mincost[MAXN + 5];

void minCostReset()
{
    for(int i = 0; i <= MAXN; i++){
        tempMinCost[i] = INF;
    }
}

void reset()
{
    for(int i = 0; i <= MAXN; i++){
        mincost[i] = 0;
        tempMinCost[i] = INF;
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
    tempMinCost[i] = 0;
    queue<int> q;
    q.push(i);

    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int j = 0; j < edges[u].size(); j++){
            if(costs[u][j] + tempMinCost[u] < tempMinCost[edges[u][j]]){
                tempMinCost[edges[u][j]] = costs[u][j] + tempMinCost[u];
                if(o.maxCost < tempMinCost[edges[u][j]]){
                    o.maxCost = tempMinCost[edges[u][j]];
                    o.node = edges[u][j];
                }
                q.push(edges[u][j]);
            }
        }//end of for
    }//end of while

    return o;
}


int main()
{
    //freopen("input.txt", "r", stdin);
    int T, N = MAXN, u, v, w;
    Obj o;
    cin >> T;

    for(int i = 1; i <= T; i++){
        reset();
        scanf("%d", &N);

        for(int j = 1; j < N; j++){
            scanf("%d%d%d", &u, &v, &w);
            edges[u].push_back(v);
            edges[v].push_back(u);
            costs[u].push_back(w);
            costs[v].push_back(w);
        }

        int x = Bfs(0).node;
        minCostReset();
        o = Bfs(x);
        tempMinCost[x] = o.maxCost;
        x = o.node;
        for(int j = 0; j < N; j++){
            mincost[j] = tempMinCost[j];
        }
        minCostReset();
        o = Bfs(x);
        tempMinCost[x] = o.maxCost;
        x = o.node;

        printf("Case %d:\n", i);
        for(int j = 0; j < N; j++){
            printf("%d\n", max(mincost[j], tempMinCost[j]));
        }
    }


    return 0;
}
