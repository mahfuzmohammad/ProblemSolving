#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

#define maxn 10000
#define maxm 100000

using namespace std;

vector<int> edge[maxn + 3],
            edgeT[maxn + 3];

bool visited1[maxn + 2],
     visited2[maxn + 2];

stack<int> st;

void reset()
{
    for(int i = 0; i <= maxn; i++) {
        edge[i].clear();
        edgeT[i].clear();
        visited1[i] = false;
        visited2[i] = false;
    }
}

void dfs1(int x) {
    visited1[x] = true;
    int esize = edge[x].size();
    for(int i = 0; i < esize; i++) {
        if(!visited1[edge[x][i]]) {
            dfs1(edge[x][i]);
        }
    }

    st.push(x);
}

void dfs2(int x) {
    visited2[x] = true;
    int esize = edge[x].size();
    for(int i = 0; i < esize; i++) {
        if(!visited2[edge[x][i]])
            dfs2(edge[x][i]);
    }
}


int main()
{
    //freopen("input.txt", "r", stdin);
    int T, N, M, u, v, ans;

    cin >> T;

    for(int i = 1; i <= T; i++) {
        reset();
        ans = 0;
        cin >> N >> M;

        for(int j = 0; j < M; j++) {
            cin >> u >> v;
            edge[u].push_back(v);
            edgeT[v].push_back(u);
        }

        for(int j = 1; j <= N; j++) {
            if(!visited1[j]) {
                dfs1(j);
            }
        }

        while(!st.empty()) {
            int u = st.top();
            st.pop();

            if(!visited2[u]) {
                dfs2(u);
                ans++;
            }
        }

        cout << "Case " << i << ": " << ans << endl;
    }

    return 0;
}
