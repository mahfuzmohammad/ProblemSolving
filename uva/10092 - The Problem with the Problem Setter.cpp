// Runtime Complexity: O(VE^2)

#include <bits/stdc++.h>

#define INF 1 << 30
#define _MAXV 1030

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
    int nk, np, pnumber, cat, n, u, v, total;

    while (scanf("%d %d", &nk, &np) && nk != 0 && np != 0) {

        total = 0;
        memset(res, -1, sizeof res);
        for(int i = 0; i < _MAXV; i++)
            resG[i].clear(), resC[i].clear();

        t = np + nk + 1;

        for(int i = 0; i < nk; i++) {
            scanf("%d", &pnumber);
            total += pnumber;

            if(res[i+1][t] == -1) {
                resG[i+1].push_back(t);
                resC[i+1].push_back(pnumber);
                res[i+1][t] = resG[i+1].size() - 1;
            } else {
                resC[i+1][res[i+1][t]] += pnumber;
            }

            if(res[t][i+1] == -1) {
                resG[t].push_back(i+1);
                resC[t].push_back(0);
                res[t][i+1] = resG[t].size() - 1;
            } else {
                resC[t][res[t][i+1]] += 0;
            }
        }

        for(int i = 0; i < np; i++) {
            scanf("%d", &pnumber);
            for(int j = 0; j < pnumber; j++) {
                scanf("%d", &cat);

                if(res[i+1+nk][cat] == -1) {
                    resG[i+1+nk].push_back(cat);
                    resC[i+1+nk].push_back(1);
                    res[i+1+nk][cat] = resG[i+1+nk].size() - 1;
                } else {
                    resC[i+1+nk][res[i+1+nk][cat]] += 1;
                }

                if(res[cat][i+1+nk] == -1) {
                    resG[cat].push_back(i+1+nk);
                    resC[cat].push_back(0);
                    res[cat][i+1+nk] = resG[cat].size() - 1;
                } else {
                    resC[cat][res[cat][i+1+nk]] += 0;
                }
            }

            if(res[0][i+1+nk] == -1) {
                resG[0].push_back(i+1+nk);
                resC[0].push_back(1);
                res[0][i+1+nk] = resG[0].size() - 1;
            } else {
                resC[0][res[0][i+1+nk]] += 1;
            }

            if(res[i+1+nk][0] == -1) {
                resG[i+1+nk].push_back(0);
                resC[i+1+nk].push_back(0);
                res[i+1+nk][0] = resG[i+1+nk].size() - 1;
            } else {
                resC[i+1+nk][res[i+1+nk][0]] += 0;
            }
        }

        s = 0;
        mf = 0;
        n = t;

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

        if(mf == total) {
            printf("1\n");
            for(int i = 1; i <= nk; i++) {
                bool flag = false;
                for(int j = 0; j < resG[i].size(); j++) {
                    if(resC[i][j] == 1) {
                        if(flag) printf(" ");
                        printf("%d", resG[i][j] - nk);
                        flag = true;
                    }
                }
                printf("\n");
            }
        } else {
            printf("0\n");
        }
    }

    return 0;
}
