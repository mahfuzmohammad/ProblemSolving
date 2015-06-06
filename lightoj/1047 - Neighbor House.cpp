#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

#define MAXN 20
#define INF 10000000
#define debug for(int i = 0; i < n; i++){for (int j = 0; j < 3; j++) cout << inputtbl[i][j] << " "; cout << endl;}
#define debug1 for(int i = 0; i < n; i++){for (int j = 0; j < 3; j++) cout << dptbl[i][j] << " "; cout << endl;}

using namespace std;

int inputtbl[MAXN + 5][MAXN + 5];
int dptbl[MAXN + 5][MAXN + 5];

void reset()
{
    for(int i = 0; i <= MAXN; i++){
        for(int j = 0; j <= MAXN; j++){inputtbl[i][j] = 0; dptbl[i][j] = INF;}
    }
}

int dp(int r, int c, int N)
{
    if(r < 0 || c < 0 || r >= N || c >= 3) return 0;
    //cout << dptbl[r][c] << endl;
    if(dptbl[r][c] != INF) return dptbl[r][c];
    else {
        if(c == 0){
            dptbl[r][c] = inputtbl[r][c] + min(dp(r + 1, 1, N), dp(r + 1, 2, N));
        } else if(c == 1){
            dptbl[r][c] = inputtbl[r][c] + min(dp(r + 1, 0, N), dp(r + 1, 2, N));
        } else {
            dptbl[r][c] = inputtbl[r][c] + min(dp(r + 1, 0, N), dp(r + 1, 1, N));
        }
    }

    return dptbl[r][c];
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int T, n;
    cin >> T;

    for(int i = 1; i <= T; i++){
        reset();
        cin >> n;
        for(int j = 0; j < n; j++){
            for(int k = 0; k < 3; k++){
                cin >> inputtbl[j][k];
            }
        }

        cout << "Case " << i << ": " << min(dp(0, 0, n), min(dp(0, 1, n), dp(0, 2, n))) << endl;

        //debug;
        //debug1;
    }

    return 0;
}
