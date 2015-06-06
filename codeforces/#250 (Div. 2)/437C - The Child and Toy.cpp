//In the name of Allah, most Gracious, most Compassionate
#include <bits/stdc++.h>

using namespace std;

#define _MAXN 1005

int tcost[_MAXN];
vector<int> vect;
vector<int> graph[_MAXN];
int incost[_MAXN];

bool cmp(int a, int b) {
    if(incost[a] == incost[b]) return (tcost[a] < tcost[b]);
    return (incost[a] > incost[b]);
}

int main() {

    int n, m, u, v, ans = 0;

    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++) {
        scanf("%d", &incost[i + 1]);
        vect.push_back(i + 1);
    }

    for(int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);

        tcost[u] += incost[v];
        tcost[v] += incost[u];
    }

    sort(vect.begin(), vect.end(), cmp);
    for(int i = 0; i < n; i++) {
        ans += tcost[vect[i]];
        for(int j = 0; j < graph[vect[i]].size(); j++) {
            tcost[graph[vect[i]][j]] -= incost[vect[i]];
        }

        //cout << vect[i] << endl;
        //sort(vect.begin() + i + 1, vect.end(), cmp);
    }

    printf("%d\n", ans);

    return 0;
}
