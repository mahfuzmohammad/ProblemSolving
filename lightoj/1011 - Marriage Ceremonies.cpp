#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>

#define maxn 16
#define dpsz 1 << maxn
#define INF  1 << 31

using namespace std;

int arr[maxn + 2][maxn + 2],
    dp[maxn + 2][dpsz + 2];

int solve(int men, int women, int& n)
{
    if(men >= n) {return 0;}

    if(dp[men][women] != -1) return dp[men][women];

    for(int i = 0; i < n; i++){
        if((women & (1 << i)) == 0) {
            dp[men][women] = max(dp[men][women], arr[men][i] + solve(men + 1, women | (1 << i), n));
        }
    }

    return dp[men][women];
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int T, N, ans;
    cin >> T;

    for(int i = 1; i <= T; i++){
        //reset();
        memset(dp, -1, sizeof(dp));
        ans = -1;
        cin >> N;
        for(int j = 0; j < N; j++){
            for(int k = 0; k < N; k++){
                cin >> arr[j][k];
            }
        }

        cout << "Case " << i << ": " << solve(0, 0, N) << endl;
    }

    return 0;
}
