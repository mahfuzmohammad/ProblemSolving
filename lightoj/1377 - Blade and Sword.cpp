#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
char board[205][205];
vector<pii> star;
int dirR[] = {1, -1, 0, 0};
int dirC[] = {0, 0, 1, -1};
int pCost[205][205], dCost[205][205], cost[205][205];
int visited[205][205];
const int inf = 100000000;

void bfs(pii s, int arr[][205], int r, int c) {
    queue<pii> q;
    visited[s.first][s.second] = false;
    arr[s.first][s.second] = 0;
    q.push(s);

    while(!q.empty()) {
        pii u = q.front(); q.pop();
        for(int i = 0; i < 4; i++) {
            if( (board[u.first+dirR[i]][u.second+dirC[i]] != '#') && !visited[u.first+dirR[i]][u.second+dirC[i]]
                && (u.first+dirR[i] >= 0) && (u.second+dirC[i] >= 0) && (u.first+dirR[i] < r) && (u.second+dirC[i] < c) ) {
                arr[u.first+dirR[i]][u.second+dirC[i]] = 1 + arr[u.first][u.second];
                visited[u.first+dirR[i]][u.second+dirC[i]] = true;
                q.push(pii(u.first+dirR[i], u.second+dirC[i]));
            }
        }
    }
}

void reset() {
    star.clear();
    for(int i = 0; i <= 200; i++) {
        for(int j = 0; j <= 200; j++) {
            pCost[i][j] = dCost[i][j] = cost[i][j] = inf;
        }
    }
}

int main() {
    //freopen("in.txt", "r", stdin);
    int t, n, m;
    pii s, e;
    char ch;
    scanf("%d", &t);

    for(int i = 1; i <= t; i++) {
        reset();
        scanf("%d %d", &n, &m);
        for(int j = 0; j < n; j++) {
            scanf("%c", &ch);
            for(int k = 0; k < m; k++) {
                scanf("%c", &board[j][k]);
                if(board[j][k] == 'P') {
                    s = pii(j, k);
                } else if(board[j][k] == 'D') {
                    e = pii(j, k);
                } else if(board[j][k] == '*') {
                    star.push_back(pii(j, k));
                }
            }
        }

        memset(visited, 0, sizeof visited); bfs(s, pCost, n, m);
        memset(visited, 0, sizeof visited); bfs(e, dCost, n, m);

        for(int j = 0; j < star.size(); j++) {
            board[star[j].first][star[j].second] = '#';
        }

        memset(visited, 0, sizeof visited); bfs(s, cost, n, m);
        int ans = inf, minP = inf, minD = inf, cntP = 0, cntD = 0;
        pii minPS = pii(-1, -1), minDS = pii(-1, -1);

        if(star.size() <= 1) {
            ans = min(ans, cost[e.first][e.second]);
        } else {
            for(int j = 0; j < star.size(); j++) {
                if(pCost[star[j].first][star[j].second] < minP) {
                    minP = pCost[star[j].first][star[j].second];
                    minPS = star[j];
                }

                if(dCost[star[j].first][star[j].second] < minD) {
                    minD = dCost[star[j].first][star[j].second];
                    minDS = star[j];
                }
            }

            for(int j = 0; j < star.size(); j++) {
                if(pCost[star[j].first][star[j].second] == minP) {
                    cntP++;
                }

                if(dCost[star[j].first][star[j].second] == minD) {
                    cntD++;
                }
            }

            if(minP == inf && minD == inf) {
                ans = min(ans, cost[e.first][e.second]);
            } else if((minPS.first == minDS.first) && (minPS.second == minDS.second) && (cntP <= 1) && (cntD <= 1)) {
                ans = min(ans, 2 + minP + minD);
            } else {
                ans = min(ans, 1 + minP + minD);
            }

            ans = min(ans, cost[e.first][e.second]);
        }

        printf("Case %d: ", i);
        if(ans == inf) {
            printf("impossible\n");
        } else {
            printf("%d\n", ans);
        }
    }

    return 0;
}
