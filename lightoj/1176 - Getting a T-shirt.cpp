//In the name of Allah, most Gracious, most Compassionate
#include <bits/stdc++.h>

#define INF 1 << 30

using namespace std;

int res[65][65];
int mf, s, t, f;
vector<int> p;
map<string, int> sizemap;

void augment(int v, int minEdge) {
    if (v == s) { f = minEdge; return; }
    else if (p[v] != -1) {
        augment(p[v], min(minEdge, res[p[v]][v]));
        res[p[v]][v] -= f; res[v][p[v]] += f;
    }
}

int main() {
    //freopen("in", "r", stdin);
    int T, n, m, u;
    //string size1, size2;
    char size1[4], size2[4];

    sizemap["XXL"] = 1;
    sizemap["XL"] = 2;
    sizemap["L"] = 3;
    sizemap["M"] = 4;
    sizemap["S"] = 5;
    sizemap["XS"] = 6;

    scanf("%d", &T);

    for(int i = 1; i <= T; i++) {
        memset(res, 0, sizeof res);
        scanf("%d %d", &n, &m);
        s = 0; t = m + 7;

        for(int j = 0; j < m; j++) {
            scanf("%s %s", size1, size2);
            //cin >> size1 >> size2;
            res[s][j + 7] = 1;
            res[j + 7][sizemap[size1]] = 1;
            res[j + 7][sizemap[size2]] = 1;
        }

        for(int j = 1; j <= 6; j++) {
            res[j][t] = n;
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

                for (int v = 1; v <= t; v++) {
                    if (res[u][v] > 0 && dist[v] == INF) {
                        dist[v] = dist[u] + 1, q.push(v), p[v] = u;
                    }
                }
            }

            augment(t, INF);
            if (f == 0) break;
            mf += f;
        }

        if(mf >= m) {
            printf("Case %d: YES\n", i);
        } else {
            printf("Case %d: NO\n", i);
        }
    }

    return 0;
}
