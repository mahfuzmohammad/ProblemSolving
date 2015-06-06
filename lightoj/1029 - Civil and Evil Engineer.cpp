#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>

#define MAXN 100

using namespace std;

struct edge {
    int u, v, w;
    edge(){}
    edge(int u, int v, int w):u(u), v(v), w(w){}
};

vector<edge> vect;
int par[MAXN + 5];

bool ascending(edge a, edge b){
    return (a.w < b.w);
}

bool descending(edge a, edge b){
    return (a.w > b.w);
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

void reset()
{
    for(int i = 0; i <= MAXN; i++)
        makeset(i);
}

void mst(int n, int& cost, int vSize){
    edge e;

    for(int i = 0, taken = 0; i < vSize && taken < n; i++){
        e = vect[i];
        if(find_representative(e.u) != find_representative(e.v)){
            uni(e.u, e.v);
            cost += e.w;
            taken++;
        }
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int t, u, v, w, n, bcost, wcost, vSize;
    edge e;
    cin >> t;

    for(int i = 1; i <= t; i++){
        vect.clear();
        bcost = 0;
        wcost = 0;
        cin >> n;

        while(cin >> u >> v >> w){
            if(u == 0 && v == 0 && w == 0) break;
            e.u = u; e.v = v; e.w = w;
            vect.push_back(e);
        }

        vSize = vect.size();
        sort(vect.begin(), vect.end(), ascending);

        reset();
        mst(n, bcost, vSize);
        //cout << bcost << endl;
        sort(vect.begin(), vect.end(), descending);
        reset();
        mst(n, wcost, vSize);
        //cout << wcost << endl;
        bcost += wcost;
        cout << "Case " << i << ": ";
        if(bcost % 2 == 0){cout << bcost / 2 << endl;}
        else {
            cout << bcost << "/" << 2 << endl;
        }
    }

    return 0;
}
