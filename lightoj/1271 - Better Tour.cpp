#include <bits/stdc++.h>

using namespace std;

vector<int> edge[50005];
int cost[50005];
bool visited[50005];
int par[50005];

void bfs(int s) {
    queue<int> q;
    q.push(s);
    cost[s] = 0;
    visited[s] = true;
    par[s] = -1;

    while(!q.empty()) {
        int u = q.front();
        q.pop();

        for(int i = 0; i < edge[u].size(); i++) {
            if(!visited[edge[u][i]]) {
                cost[edge[u][i]] = cost[u]+1;
                visited[edge[u][i]] = true;
                q.push(edge[u][i]);
                par[edge[u][i]] = u;
            }
        }
    }
}

void print(int node) {
    if(par[node] == -1) {
        printf("%d", node);
        return;
    }

    print(par[node]);
    printf(" %d", node);
}

void reset() {
    for(int i = 0; i <= 50000; i++) {
        edge[i].clear();
        cost[i] = 0;
        visited[i] = 0;
        par[i] = -1;
    }
}

int main() {
    //freopen("in.txt", "r", stdin);
    int t, n, u, v, s, e;
    scanf("%d", &t);

    for(int i = 1; i <= t; i++) {
        reset();
        scanf("%d", &n);
        scanf("%d %d", &u, &v);
        s = u, edge[u].push_back(v), edge[v].push_back(u);
        u = v;

        for(int j = 2; j < n; j++) {
            scanf("%d", &v);
            edge[u].push_back(v), edge[v].push_back(u);
            u = v;
        }

        e = u;

        for(int j = 0; j <= 50000; j++)
            sort(edge[j].begin(), edge[j].end());

        bfs(s);
        printf("Case %d:\n", i);
        print(e);
        printf("\n");
    }

    return 0;
}
