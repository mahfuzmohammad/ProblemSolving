#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <set>
#include <algorithm>

#define elem 100000

using namespace std;

struct edge {
    int u, v, w;
    edge(){}
    edge(int u, int v, int w):u(u), v(v), w(w){}
};

vector<edge> edgelist;

int par[elem + 5];
set<int> pSet;

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
    pSet.clear();
}

bool ascending(edge a, edge b){return a.w < b.w;}

int mst(int vSize)
{
    int cost = 0;
    for(int i = 0; i < vSize; i++){
        if(find_representative(edgelist[i].u) != find_representative(edgelist[i].v)){
            cost += edgelist[i].w;
            uni(edgelist[i].u, edgelist[i].v);
        }
    }

    return cost;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int T, N, M, A, X, Y, C, tempC, vSize, setSize;
    cin >> T;

    for(int i = 1; i <= T; i++){
        reset();
        cin >> N >> M >> A;
        for(int j = 0; j < M; j++){
            cin >> X >> Y >> C;

            if(C < A)
                edgelist.push_back(edge(X, Y, C));
        }

        sort(edgelist.begin(), edgelist.end(), ascending);
        vSize = edgelist.size();
        tempC = mst(vSize);

        for(int j = 1; j <= N; j++){
            pSet.insert(find_representative(j));
        }

        setSize = pSet.size();

        cout << "Case " << i << ": " << tempC + (A * setSize) << " " << setSize << endl;
    }

    return 0;
}
