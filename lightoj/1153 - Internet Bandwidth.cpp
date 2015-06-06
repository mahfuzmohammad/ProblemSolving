#include <bits/stdc++.h>

#define INF 1 << 30

using namespace std;

int res[105][105];
int mf, s, t, f;
vector<int> p;

void augment(int v, int minEdge) {
    if (v == s) { f = minEdge; return; }
    else if (p[v] != -1) { augment(p[v], min(minEdge, res[p[v]][v]));
                           res[p[v]][v] -= f; res[v][p[v]] += f; }
}

int main() {
    //freopen("input.txt", "r", stdin);
    int T, c, u, v, w, n;
    cin >> T;

    for(int i = 1; i <= T; i++) {
        memset(res, 0, sizeof res);
        cin >> n;
        cin >> s >> t >> c;

        for(int j = 0; j < c; j++) {
            cin >> u >> v >> w;
            res[u][v] += w;
            res[v][u] += w;
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

                for (v = 1; v <= n; v++) {
                    if (res[u][v] > 0 && dist[v] == INF) {
                        dist[v] = dist[u] + 1, q.push(v), p[v] = u;
                    }
                }
            }

            augment(t, INF);
            if (f == 0) break;
            mf += f;
        }

        cout << "Case " << i << ": " << mf << endl;
    }

    return 0;
}
