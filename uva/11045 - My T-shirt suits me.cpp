// Runtime Complexity: O(VE^2)

#include <bits/stdc++.h>

#define INF 1 << 30
#define _MAXV 50

using namespace std;

int res[_MAXV][_MAXV]; // stores the index of v in linklist of resG[u]
vector<int> resG[_MAXV], resC[_MAXV];
int mf, s, t, f;
vector<int> p;
map<string, int> shirtMap;

void augment(int v, int minEdge) {
    if (v == s) { f = minEdge; return; }
    else if (p[v] != -1) {
        augment(p[v], min(minEdge, resC[p[v]][res[p[v]][v]]));
        resC[p[v]][res[p[v]][v]] -= f; resC[v][res[v][p[v]]] += f;
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    int T, c, u, v, w, n, shirt, vol;
    string str1, str2;

    shirtMap["XXL"] = 0;
    shirtMap["XL"] = 1;
    shirtMap["L"] = 2;
    shirtMap["M"] = 3;
    shirtMap["S"] = 4;
    shirtMap["XS"] = 5;

    cin >> T;

    for(int i = 0; i < T; i++) {

        memset(res, -1, sizeof res);
        for(int i = 0; i < _MAXV; i++)
            resG[i].clear(), resC[i].clear();

        cin >> shirt >> vol;
        n = 50;
        shirt /= 6;

        s = 44, t = 45;

        for(int j = 0; j < 6; j++) {
            if(res[s][j] == -1) {
                resG[s].push_back(j);
                resC[s].push_back(shirt);
                res[s][j] = resG[s].size() - 1;
            }

            if(res[j][s] == -1) {
                resG[j].push_back(s);
                resC[j].push_back(shirt);
                res[j][s] = resG[j].size() - 1;
            }
        }

        for(int j = 0; j < vol; j++) {
            if(res[t][j+10] == -1) {
                resG[t].push_back(j+10);
                resC[t].push_back(1);
                res[t][j+10] = resG[t].size() - 1;
            }

            if(res[j+10][t] == -1) {
                resG[j+10].push_back(t);
                resC[j+10].push_back(1);
                res[j+10][t] = resG[j+10].size() - 1;
            }
        }

        for(int j = 0; j < vol; j++) {
            cin >> str1 >> str2;
            u = shirtMap[str1], v = j + 10, w = 1;

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

            u = shirtMap[str2], v = j + 10, w = 1;

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

        if(mf == vol) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
