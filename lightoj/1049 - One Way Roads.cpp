#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <cmath>
#include <algorithm>

#define MAXN 100

using namespace std;

vector<int> biroad[MAXN + 2];
int road[MAXN + 2][MAXN + 2];
int nodes[MAXN + 2][MAXN + 2];

typedef struct {
    int from, to, cost;
} Info;

bool sortfunc(Info a, Info b){
    return (a.cost > b.cost);
}

vector<Info> v;

void reset(){
    v.clear();

    for(int i = 0; i <= MAXN; i++){
        biroad[i].clear();
        for(int j = 0; j <= MAXN; j++){
            nodes[i][j] = -1;
            road[i][j] = -1;
        }
    }
}

int process(int s, int d){
    int cost = 0;
    nodes[s][d] = 1;
    nodes[d][s] = 1;
    queue<int> q;
    q.push(d);

    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int i = 0; i < biroad[u].size(); i++){
            if(nodes[u][biroad[u][i]] == -1){
                nodes[u][biroad[u][i]] = 1;
                nodes[biroad[u][i]][u] = 1;
                if(road[u][biroad[u][i]] == -1){
                    cost += road[biroad[u][i]][u];
                }

                q.push(biroad[u][i]);
            }
        }
    }

    return cost;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int T, n, a, b, c, total, cost;
    Info temp;

    cin >> T;

    for(int i = 1; i <= T; i++){
        reset();
        total = 0;
        cin >> n;
        for(int j = 0; j < n; j++){
            cin >> a >> b >> c;
            total += c;
            biroad[a].push_back(b);
            biroad[b].push_back(a);
            road[a][b] = c;
            temp.from = a; temp.to = b; temp.cost = c;
            v.push_back(temp);
        }

        sort(v.begin(), v.end(), sortfunc);
        cost = process(v[0].from, v[0].to);
        cout << "Case " << i << ": ";
        if(total - cost > cost){
            cout << cost;
        } else {cout << total - cost;}
        cout << endl;
    }

    return 0;
}
