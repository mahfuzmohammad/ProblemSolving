#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

#define maxn 100
#define maxk 10000

using namespace std;

int coin[maxn + 2],
    amnt[maxn + 2],
    dpmem[maxn + 2][maxk + 2];


int solve(int k, int& n)
{
    for(int i = 0; i <= n; i++)
        dpmem[i][0] = 1;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= k; j++){
            if(amnt[i] > 0){
                amnt[i]--;
                int tval1 = 0;
                if(j >= coin[i])
                    tval1 = dpmem[i][j - coin[i]] % 100000007;

                dpmem[i][j] = (tval1 + dpmem[i - 1][j]) % 100000007;
            }
        }
    }

    return dpmem[n][k];
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int T, n, k;
    cin >> T;

    for(int i = 1; i <= T; i++){
        cin >> n >> k;
        for(int j = 1; j <= n; j++){
            cin >> coin[j];
            amnt[j] = k;
        }

        memset(dpmem, 0, sizeof(dpmem));
        cout << "Case " << i << ": " << solve(k, n) << endl;
    }

    return 0;
}
