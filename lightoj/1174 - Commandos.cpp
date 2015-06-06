#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <algorithm>

#define MAXN 100
#define INF 10000000

using namespace std;

int cost[MAXN + 5][MAXN + 5];

void reset(int N)
{
    for(int i = 0; i <= N; i++)
        for(int j = 0; j <= N; j++)
            if(i == j) cost[i][j] = 0;
            else cost[i][j] = INF;
}

void floydWarshall(int N)
{
    for(int k = 0; k < N; k++)
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);

}

int main()
{
    int T, N = MAXN, R, u, v, s, d, ans;
    cin >> T;

    for(int i = 1; i <= T; i++){
        reset(N);
        ans = 0;
        cin >> N >> R;
        for(int j = 0; j < R; j++){
            cin >> u >> v;
            cost[u][v] = 1;
            cost[v][u] = 1;
        }

        cin >> s >> d;
        if(s > d) swap(s, d);
        floydWarshall(N);

        ans = 0;
        for(int j = 0; j < N; j++){
            ans = max(ans, cost[s][j] + cost[j][d]);
        }

        cout << "Case " << i << ": " << ans << endl;
    }

    return 0;
}
