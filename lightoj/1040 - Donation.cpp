#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>

#define elem 50

using namespace std;

struct edge {
    int u, v, w;
    edge(){}
    edge(int u, int v, int w):u(u), v(v), w(w){}
};

vector<edge> edgelist;

int par[elem + 5];

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

void reset(){
    for(int i = 0; i <= elem; i++) makeset(i);
    edgelist.clear();
}

bool ascending(edge a, edge b){return a.w < b.w;}

int mst(int n, int vSize)
{
    int cost = 0;
    for(int i = 0, taken = 0; i < vSize && taken < n - 1; i++){
        if(find_representative(edgelist[i].u) != find_representative(edgelist[i].v)){
            cost += edgelist[i].w;
            uni(edgelist[i].u, edgelist[i].v);
            taken++;
        }
    }

    return cost;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int t, n, w, vSize, c, tc, chkp;
    cin >> t;

    for(int i = 1; i <= t; i++){
        reset();
        tc = 0;

        cin >> n;
        for(int u = 1; u <= n; u++){
            for(int v = 1; v <= n; v++){
                cin >> w;
                tc += w;
                if(w != 0)
                    edgelist.push_back(edge(u, v, w));
            }
        }

        sort(edgelist.begin(), edgelist.end(), ascending);
        vSize = edgelist.size();
        c = mst(n, vSize);
        chkp = find_representative(1);
        for(int j = 1; j <= n; j++){
            if(chkp != find_representative(j)){c = -1; break;}
        }

        cout << "Case " << i << ": " << ((c < 0)?c:tc-c) << endl;
    }

    return 0;
}
