#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

#define maxn 50
#define maxk 1000

using namespace std;

int coin[maxn + 2],
    numcoin[maxn + 2];

int dp[maxn + 2][22][maxk + 2];

int solve(int i, int taken, int amount, int& n)
{
    if(amount == 0) return 1;
    if(i < 0) return 0;

    if(dp[i][taken][amount] != -1) return dp[i][taken][amount];

    int tval1 = 0, tval2 = 0;
    if(amount >= coin[i] && taken < numcoin[i])
        tval1 = solve(i, taken + 1, amount - coin[i], n);

    tval2 = solve(i - 1, 0, amount, n);
    dp[i][taken][amount] = ( (tval1 % 100000007) + (tval2 % 100000007) ) % 100000007;

    return dp[i][taken][amount];
}

int main()
{
    int T, n, k;
    cin >> T;

    for(int i = 1; i <= T; i++){
        cin >> n >> k;
        for(int j = 0; j < n; j++) {
            cin >> coin[j];
        }

        for(int j = 0; j < n; j++) {
            cin >> numcoin[j];
        }

        memset(dp, -1, sizeof(dp));
        cout << "Case " << i << ": " << solve(n - 1, 0, k, n) << endl;
    }

    return 0;
}
