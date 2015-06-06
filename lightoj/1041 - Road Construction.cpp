#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

struct edge {
    string u, v;
    int w;
    edge(){}
    edge(string u, string v, int w):u(u), v(v), w(w){}
};

map<string, string> par;
vector<edge> elist;
set<string> nodes;

bool ascending(edge a, edge b){
    return (a.w < b.w);
}

void makeset(string n){par[n] = n;}

string find_representative(string a){
    if(par[a] == "") makeset(a);
    if(par[a] == a) return a;
    par[a] = find_representative(par[a]);
    return par[a];
}

void uni(string a, string b){
    string u = find_representative(a);
    string v = find_representative(b);

    if(u != v){par[u] = v;}
}

void mst(int m, int& cost){
    for(int i = 0; i < m; i++){
        if(find_representative(elist[i].u) != find_representative(elist[i].v)){
            cost += elist[i].w;
            uni(elist[i].u, elist[i].v);
        }
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int t, m, w, cost;
    set<string>::iterator it;
    string u, v, p;
    edge e;

    cin >> t;

    for(int i = 1; i <= t; i++){
        elist.clear();
        par.clear();
        nodes.clear();
        cost = 0;
        cin >> m;
        for(int j = 0; j < m; j++){
            cin >> u >> v >> w;
            e.u = u;
            e.v = v;
            e.w = w;
            elist.push_back(e);
            nodes.insert(u);
            nodes.insert(v);
        }

        sort(elist.begin(), elist.end(), ascending);
        mst(m, cost);
        it = nodes.begin();
        p = find_representative(*it);
        for(; it != nodes.end(); it++){
            if(p != find_representative(*it)){cost = -1;}
        }

        if(cost < 0){cout << "Case " << i << ": Impossible" << endl;}
        else {cout << "Case " << i << ": " << cost << endl;}
    }

    return 0;
}
