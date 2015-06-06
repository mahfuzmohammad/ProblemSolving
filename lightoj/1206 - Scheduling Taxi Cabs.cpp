#include <bits/stdc++.h>

using namespace std;

#define _MAXN 500

struct ride {
    int start, reach, a, b, c, d;
    ride(){}
    ride(int _s, int _a, int _b, int _c, int _d) {
        start = _s;
        a = _a, b = _b, c = _c, d = _d;
        reach = abs(a-c) + abs(b-d) + start;
    }

    inline int minuteNeedToGo(ride& obj) const {
        return abs(this->c - obj.a) + abs(this->d - obj.b);
    }

    bool canGo(ride& obj) const {
        return ((minuteNeedToGo(obj) + reach) < obj.start);
    }
};

int T, m, hh, mm, a, b, c, d, n;
vector<ride> rides;
vector<int> edges[_MAXN + 5]; // left side adjacency list
bool visited[_MAXN + 5];
int Left[_MAXN + 5], Right[_MAXN + 5]; // keeps the matching

bool dfs(int u) { // returns if it is possible to match u
    if(visited[u]) return false;
    visited[u] = true;

    for(int i = 0; i < (int)edges[u].size(); i++) {
        int v = edges[u][i];
        if(Right[v-m] == -1 || dfs(Right[v-m])) {
            Right[v-m] = u, Left[u] = v;
            return true;
        }
    }

    return false;
}

int match() { // returns the number of maximum matching
    memset(Left, -1, sizeof Left);
    memset(Right, -1, sizeof Right);
    int matchCnt = 0;
    bool done;

    do {
        done = true;
        memset(visited, 0, sizeof visited);
        for(int i = 0; i < _MAXN; i++)
            if(Left[i] == -1 && dfs(i))
                done = false;
    } while(!done);

    for(int i = 0; i < _MAXN; i++) matchCnt += (Left[i] != -1);
    return matchCnt;
}

void reset() {
    rides.clear();
    for(int i = 0; i <= _MAXN; i++)
        edges[i].clear();
}

int main() {
    //freopen("in", "r", stdin);
    scanf("%d", &T);

    for(int i = 1; i <= T; i++) {
        reset();
        scanf("%d", &m);

        // input rides
        for(int j = 0; j < m; j++) {
            scanf("%d:%d %d %d %d %d", &hh, &mm, &a, &b, &c, &d);
            rides.push_back(ride(hh*60+mm, a, b, c, d));
        }

        // build the bipartite graph
        for(int j = 0; j < m; j++) {
            for(int k = 0; k < m; k++) {
                if(j == k) continue;
                if(rides[j].canGo(rides[k])) {
                    edges[j].push_back(k+m);
                }
            }
        }

        printf("Case %d: %d\n", i, (int)rides.size() - match());
    }

    return 0;
}
