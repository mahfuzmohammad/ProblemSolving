#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#define maxcity 500
#define INF 1<<30

using namespace std;

struct obj {
    int node;
    int objCost;
    obj(){}
    obj(int a, int b){node = a; objCost = b;}
};

class CompareObj {
    public:
    bool operator()(obj o1, obj o2)
    {
        if(o1.objCost > o2.objCost) return true;
        return false;
    }
};

vector<int> edges[maxcity + 5], cost[maxcity + 5];
long long minCost[maxcity + 5];

void reset(){
    for(int i = 0; i <= maxcity; i++){
        edges[i].clear();
        cost[i].clear();
        minCost[i] = INF;
    }
}

void dijkstra(int start){
    int tempMaxCost;
    priority_queue<obj, vector<obj>, CompareObj > q;
    minCost[start] = 0;
    q.push(obj(start, minCost[start]));
    obj u;

    while(!q.empty()){
        u = q.top();
        q.pop();

        for(int i = 0; i < edges[u.node].size(); i++){
            tempMaxCost = (minCost[u.node] > cost[u.node][i])? minCost[u.node] : cost[u.node][i];
            if(minCost[edges[u.node][i]] > tempMaxCost)
            {
                /*if(minCost[edges[u.node][i]] == INF){*/
                    minCost[edges[u.node][i]] = tempMaxCost;
                    q.push(obj(edges[u.node][i], minCost[edges[u.node][i]]));
                /*} else {
                    minCost[edges[u.node][i]] = tempMaxCost;
                }*/
            }

        }// end of for
    }// end of while
}

int main()
{
    int T, n, m, u, v, w, t;

    cin >> T;

    for(int i = 1; i <= T; i++) {
        reset();
        cin >> n >> m;

        for(int j = 0; j < m; j++) {
            cin >> u >> v >> w;
            edges[u].push_back(v);
            cost[u].push_back(w);
            edges[v].push_back(u);
            cost[v].push_back(w);
        }

        cin >> t;

        dijkstra(t);

        cout << "Case " << i << ":" << endl;

        for(int j = 0; j < n; j++){
            if(minCost[j] == INF){
                cout << "Impossible" << endl;
            } else {
                cout << minCost[j] << endl;
            }
        }
    }

    return 0;
}
