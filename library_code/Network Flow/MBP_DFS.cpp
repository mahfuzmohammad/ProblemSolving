#include <bits/stdc++.h>

using namespace std;

#define _MAXN 100

vector<int> edges[_MAXN + 5]; // left side adjacency list
bool visited[_MAXN + 5];
int Left[_MAXN + 5], Right[_MAXN + 5]; // keeps the matching

bool dfs(int u) { // returns if it is possible to match u
    if(visited[u]) return false;
    visited[u] = true;

    for(int i = 0; i < (int)edges[u].size(); i++) {
        int v = edges[u][i];
        if(Right[v] == -1 || dfs(Right[v])) {
            Right[v] = u, Left[u] = v;
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
    for(int i = 0; i <= _MAXN; i++)
        edges[i].clear();
}

int main() {
    // take input
    // set edge using 'edges' array of vectors
    // remember! 'edges' only stores left side adjacency list
    return 0;
}
