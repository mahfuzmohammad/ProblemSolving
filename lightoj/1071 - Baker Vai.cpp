#include <bits/stdc++.h>

using namespace std;

int dp[105][105][105];
int grid[105][105];

int f (int r, int c, int r1, int& m, int& n) {
    if (r >= m || c >= n || r1 >= m || (r == m -1 && c == n - 1)) return 0;
    if (r == r1) return 0;

    if (dp[r][c][r1] != -1) {return dp[r][c][r1];}

    int temp = 0;
    temp = max( max(f(r, c + 1, r1, m, n) , f(r, c + 1, r1 + 1, m, n)), max(f(r + 1, c, r1, m, n), f(r + 1, c, r1 + 1, m, n)) );
    dp[r][c][r1] = grid[r][c] + grid[r1][r + c - r1] + temp;

    return dp[r][c][r1];
}

int main() {
    #ifdef flagison
    freopen("in", "r", stdin);
    #endif

    int T, m, n;
    cin >> T;

    for (int i = 1; i <= T; i++) {

        memset(dp, -1, sizeof dp);
        memset(grid, 0, sizeof grid);

        cin >> m >> n;

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                cin >> grid[r][c];
            }
        }

        cout << "Case " << i << ": " << grid[0][0] + grid[m - 1][n - 1] + f(0, 1, 1, m, n) << endl;
    }

    return 0;
}
