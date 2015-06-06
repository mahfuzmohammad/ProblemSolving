#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

#define MAXN 200

using namespace std;

int inputtbl[MAXN + 5][MAXN + 5];
int dptbl[MAXN + 5][MAXN + 5];

void reset(){
    for(int i = 0; i <= MAXN; i++){
        for(int j = 0; j <= MAXN; j++){dptbl[i][j] = -1; inputtbl[i][j] = 0;}
    }
}

int dp(int r, int c, int N)
{
    if(r >= 2 * N - 1 || c < 0 || r < 0 || (r >= N && c >= 2 * N - r)) return 0;
    if(r == 2 * N - 2){dptbl[r][0] = inputtbl[r][0]; return dptbl[r][0];}

    if(dptbl[r][c] != -1) return dptbl[r][c];
    else {
        if(r < N - 1){
            dptbl[r][c] = inputtbl[r][c] + max(dp(r + 1, c, N), dp(r + 1, c + 1, N));
        } else {
            dptbl[r][c] = inputtbl[r][c] + max(dp(r + 1, c, N), dp(r + 1, c - 1, N));
        }
    }

    return dptbl[r][c];
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int T, N;
    cin >> T;

    for(int i = 1; i <= T; i++){
        reset();
        cin >> N;

        for(int j = 0; j < N; j++){
            for(int k = 0; k <= j; k++){
                cin >> inputtbl[j][k];
            }
        }

        for(int j = N; j < 2 * N - 1; j++){
            for(int k = 0; k < (2 * N - 1) - j; k++){
                cin >> inputtbl[j][k];
            }
        }

        cout << "Case " << i << ": " << dp(0, 0, N) << endl;
    }

    return 0;
}
