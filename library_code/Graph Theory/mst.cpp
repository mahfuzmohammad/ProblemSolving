//MST with Uniqueness

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

struct edge {
    int u, v, w;
    edge(){}
    edge(int _u, int _v, int _w):u(_u), v(_v), w(_w){}
};

vector<edge> elist;
map<int, int> par;
vector<int> mst_edges;

bool ascending(edge a, edge b){
    return (a.w < b.w);
}

void makeset(int n){par[n] = n;}

int find_representative(int a){
    if(par[a] == a) return a;
    par[a] = find_representative(par[a]);
    return par[a];
}

void uni(int a, int b){
    int u = find_representative(a);
    int v = find_representative(b);

    if(u != v){par[u] = v;}
}

void mst(int m, int& cost, int exclude_edge, bool collect_edge){
    for(int i = 0; i < m; i++){
        if(i == exclude_edge) continue;

        if(find_representative(elist[i].u) != find_representative(elist[i].v)){
            if(collect_edge) mst_edges.push_back(i);

            cost += elist[i].w;
            uni(elist[i].u, elist[i].v);
        }
    }
}

int main() {
    //freopen("in.txt", "r", stdin);
    int t, n, m, u, v, w, cost;
    bool isUnique;
    cin >> t;

    for(int i = 0; i < t; i++) {

        cost = 0, isUnique = true;
        elist.clear();
        par.clear();
        mst_edges.clear();

        cin >> n >> m;
        for(int j = 0; j < m; j++) {
            cin >> u >> v >> w;
            elist.push_back(edge(u, v, w));
        }

        sort(elist.begin(), elist.end(), ascending);

        for(int j = 1; j <= n; j++) {makeset(j);}
        mst(m, cost, -1, true);

        for(int k = 0; k < n - 1; k++) {
            int tempCost = 0;
            for(int j = 1; j <= n; j++) {makeset(j);}
            mst(m, tempCost, mst_edges[k], false);

            set<int> s;
            for(int j = 1; j <= n; j++) {
                s.insert(find_representative(j));
            }

            if(tempCost == cost && s.size() == 1) {
                isUnique = false;
                break;
            }
        }

        if(!isUnique) cout << "Not Unique!" << endl;
        else cout << cost << endl;

    }

    return 0;
}
