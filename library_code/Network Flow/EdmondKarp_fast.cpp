// Runtime Complexity: O(VE^2)

#include <bits/stdc++.h>

#define INF 1 << 30
#define _MAXV 5005

using namespace std;

int res[_MAXV][_MAXV]; // stores the index of v in linklist of resG[u]
vector<int> resG[_MAXV], resC[_MAXV];
int mf, s, t, f;
vector<int> p;

void augment(int v, int minEdge) {
    if (v == s) { f = minEdge; return; }
    else if (p[v] != -1) {
        augment(p[v], min(minEdge, resC[p[v]][res[p[v]][v]]));
        resC[p[v]][res[p[v]][v]] -= f; resC[v][res[v][p[v]]] += f;
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    int T = 0, c, u, v, w, n;

    while (scanf("%d", &n) && n != 0) {

        memset(res, -1, sizeof res);
        for(int i = 0; i < _MAXV; i++)
            resG[i].clear(), resC[i].clear();

        scanf("%d %d %d", &s, &t, &c);

        for(int j = 0; j < c; j++) {
            scanf("%d %d %d", &u, &v, &w);

            if(res[u][v] == -1) {
                resG[u].push_back(v);
                resC[u].push_back(w);
                res[u][v] = resG[u].size() - 1;
            } else {
                resC[u][res[u][v]] += w;
            }

            if(res[v][u] == -1) {
                resG[v].push_back(u);
                resC[v].push_back(w);
                res[v][u] = resG[v].size() - 1;
            } else {
                resC[v][res[v][u]] += w;
            }


        }

        mf = 0;

        while (true) {
            f = 0;
            vector<int> dist(n + 2, INF);
            dist[s] = 0;
            queue<int> q; q.push(s);
            p.assign(n + 2, -1);

            while (!q.empty()) {
                u = q.front(); q.pop();
                if (u == t) break;

                for(v = 0; v < resG[u].size(); v++) {
                    if(resC[u][v] > 0 && dist[resG[u][v]] == INF) {
                        dist[resG[u][v]] = dist[u] + 1;
                        q.push(resG[u][v]), p[resG[u][v]] = u;
                    }
                }
            }

            augment(t, INF);
            if (f == 0) break;
            mf += f;
        }

        printf("Network %d\nThe bandwidth is %d.\n\n", ++T, mf);
    }

    return 0;
}
