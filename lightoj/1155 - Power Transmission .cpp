//In the name of Allah, most Gracious, most Compassionate

#include <bits/stdc++.h>

#define INF 1 << 30

using namespace std;

int res[205][205];
int mf, s, t, f;
vector<int> p;

void augment(int v, int minEdge) {
    if (v == s) { f = minEdge; return; }
    else if (p[v] != -1) {
        augment(p[v], min(minEdge, res[p[v]][v]));
        res[p[v]][v] -= f; res[v][p[v]] += f;
    }
}

int main() {
    //freopen("in", "r", stdin);
    int T, u, v, w, n, edgeno, b, d, gate;
    scanf("%d", &T);

    for(int i = 1; i <= T; i++) {
        memset(res, 0, sizeof res);
        scanf("%d", &n);

        for(int j = 1; j <= n; j++) {
            scanf( "%d", &res[(j << 1) - 1][(j << 1)] );
        }

        scanf("%d", &edgeno);

        for(int j = 0; j < edgeno; j++) {
            scanf("%d %d %d", &u, &v, &w);
            res[(u << 1)][(v << 1) - 1] += w;
        }

        scanf("%d %d", &b, &d);
        s = 0; t = ((n + 1) << 1) - 1;

        for(int j = 0; j < b; j++) {
            scanf("%d", &gate);
            res[s][(gate << 1) - 1] = INF;
        }

        for(int j = 0; j < d; j++) {
            scanf("%d", &gate);
            res[(gate << 1)][t] = INF;
        }

        mf = 0;

        while (true) {
            f = 0;
            vector<int> dist(t + 2, INF);
            dist[s] = 0;
            queue<int> q; q.push(s);
            p.assign(t + 2, -1);

            while (!q.empty()) {
                u = q.front(); q.pop();
                if (u == t) break;

                for (v = 1; v <= t; v++) {
                    if (res[u][v] > 0 && dist[v] == INF) {
                        dist[v] = dist[u] + 1, q.push(v), p[v] = u;
                    }
                }
            }

            augment(t, INF);
            if (f == 0) break;
            mf += f;
        }

        printf("Case %d: %d\n", i, mf);
    }

    return 0;
}
