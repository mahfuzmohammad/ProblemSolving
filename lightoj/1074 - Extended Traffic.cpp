#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>

#define maxn 200
#define INF  1 << 30

using namespace std;

struct edge {
    int u, v;
    edge(){}
    edge(int a, int b){u = a, v = b;}
};

bool            reachable[maxn + 3][maxn + 3];
int             initbz[maxn + 3], cost[maxn + 3];
vector<edge>    edgelist;

void reset()
{
    edgelist.clear();
    for(int i = 0; i <= maxn; i++){
        for(int j = 0; j <= maxn; j++)
            reachable[i][j] = false;
        cost[i] = INF;
    }
}

int bzness(int s, int d)
{
    int b = initbz[d] - initbz[s];
    return b*b*b;
}

void BellmanFord(int s, int m, int n)
{
    cost[s] = 0;
    for(int i = 1; i < n; i++){
        for(int j = 0; j < m; j++){
            if(cost[edgelist[j].v] > cost[edgelist[j].u] + bzness(edgelist[j].u, edgelist[j].v)){
                cost[edgelist[j].v] = cost[edgelist[j].u] + bzness(edgelist[j].u, edgelist[j].v);
                if(reachable[1][edgelist[j].u])
                    reachable[1][edgelist[j].v] = true;
            }
        }
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int T, n, m, q, u, v;
    cin >> T;

    for(int i = 1; i <= T; i++){
        reset();
        cin >> n;
        for(int j = 1; j <= n; j++){
            cin >> initbz[j];
        }

        cin >> m;
        for(int j = 1; j <= m; j++){
            cin >> u >> v;
            edgelist.push_back(edge(u, v));
            reachable[u][v] = true;
        }

        BellmanFord(1, m, n);

        cin >> q;
        cout << "Case " << i << ":" << endl;
        for(int j = 0; j < q; j++){
            cin >> v;

            if(reachable[1][v] && cost[v] >= 3){
                cout << cost[v] << endl;
            } else {
                cout << "?" << endl;
            }
        }
    }

    return 0;
}
