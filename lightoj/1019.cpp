#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>

#define MAXEDGE 100
#define INF 9999999

using namespace std;

struct Obj {
    int junction;
    int cost;

    Obj(){}
    Obj(int node, int c){junction = node; cost = c;}
};

vector<int> edges[MAXEDGE + 5], cost[MAXEDGE + 5];
int minCost[MAXEDGE + 5];

void reset(){
    for(int i = 0; i <= MAXEDGE; i++){
        edges[i].clear();
        cost[i].clear();
        minCost[i] = INF;
    }
}

class CompareObj {
    public:
    bool operator() (Obj a, Obj b){
        if(a.cost > b.cost) return true;
        return false;
    }
};

void dijsktra(int start){
    priority_queue<Obj, vector<Obj>, CompareObj > q;
    minCost[start] = 0;
    q.push(Obj(start, 0));
    Obj u;

    while(!q.empty()){
        u = q.top();
        q.pop();

        for(int i = 0; i < edges[u.junction].size(); i++){
            if( minCost[ edges[u.junction][i] ] > (minCost[u.junction] + cost[u.junction][i]) ){
                /*if(minCost[ edges[u.junction][i] ] == INF){*/
                    minCost[ edges[u.junction][i] ] = (minCost[u.junction] + cost[u.junction][i]);
                    q.push(Obj(edges[u.junction][i], minCost[ edges[u.junction][i] ]));
                /*} else {
                    minCost[ edges[u.junction][i] ] = (minCost[u.junction] + cost[u.junction][i]);
                }*/
            }
        }//end of for
    }//end of while
}//end of dijsktra


int main(){
    //freopen("input.txt", "r", stdin);
    int T, N, M, u, v, w;
    cin >> T;

    for(int i = 1; i <= T; i++){
        reset();
        cin >> N >> M;

        for(int j = 0; j < M; j++){
            cin >> u >> v >> w;

            edges[u].push_back(v);
            cost[u].push_back(w);
            edges[v].push_back(u);
            cost[v].push_back(w);
        }

        dijsktra(1);

        cout << "Case " << i << ": ";

        if(minCost[N] == INF){
            cout << "Impossible";
        } else {
            cout << minCost[N];
        }

        cout << endl;
    }
}
