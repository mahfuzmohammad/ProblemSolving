#include <bits/stdc++.h>

using namespace std;

#define FIN(a) freopen(a, "r", stdin)
#define IN(a) scanf("%d", &a)
#define INchar(a) scanf("%c", &a)
#define INnewline() scanf("\n");

int movx[] = {1, 1, 2, 2, -1, -1, -2, -2};
int movy[] = {2, -2, 1, -1, 2, -2, 1, -1};

int cost[102][12][12];
bool visited[102][12][12];

int t, n, m;
char temp;

int board[12][12];

struct cord {
    int x, y;
    cord(){}
    cord(int _x, int _y) : x(_x), y(_y) {}
};

vector<cord> klist;

void reset() {
    memset(cost, 0, sizeof cost);
    memset(visited, false, sizeof visited);
    klist.clear();
}

void fill(int x, int y, int& id) {
    queue<cord> q;
    visited[id][x][y] = true;
    cost[id][x][y] = 0;
    q.push(cord(x, y));
    cord u;

    while(!q.empty()) {
        u = q.front();
        q.pop();

        for(int i = 0; i < 8; i++) {
            int newx = u.x + movx[i], newy = u.y + movy[i];
            if(newx < 0 || newy < 0 || newx >= m || newy >= n) continue;
            if(!visited[id][ newx ][ newy ]) {
                visited[id][ newx ][ newy ] = true;
                cost[id][ newx ][ newy ] = 1 + cost[id][ u.x ][ u.y ];
                q.push(cord(newx, newy));
            }
        }
    }

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            int tempc = cost[id][i][j];
            if(visited[id][i][j]) {
                cost[id][i][j] = (tempc / board[klist[id].x][klist[id].y])
                               + ((tempc % board[klist[id].x][klist[id].y] == 0)?0:1);
            }
        }
    }
}

int main() {
    //FIN("in.txt");
    IN(t);

    for(int i = 1; i <= t; i++) {
        reset();
        IN(m), IN(n);

        for(int j = 0; j < m; j++) {
            INnewline();
            for(int k = 0; k < n; k++) {
                INchar(temp);

                if(temp >= '1' && temp <= '9') {
                    board[j][k] = temp - '0';
                    klist.push_back(cord(j, k));
                } else {
                    board[j][k] = 0;
                }
            }
        }

        for(int j = 0; j < klist.size(); j++) {
            fill(klist[j].x, klist[j].y, j);
        }

        int ans = 1 << 30;

        bool possible = false;
        for(int r = 0; r < m; r++) {
            for(int c = 0; c < n; c++) {
                int tempsum = 0;
                bool allvisited = true;
                for(int k = 0; k < klist.size(); k++) {
                    allvisited &= visited[k][r][c];
                }

                for(int k = 0; k < klist.size(); k++) {
                    tempsum += cost[k][r][c];
                }

                if(allvisited)
                    ans = min(ans, tempsum);

                possible |= allvisited;
            }
        }

        if(!possible)
            printf("Case %d: %d\n", i, -1);
        else
            printf("Case %d: %d\n", i, ans);
    }

    return 0;
}
