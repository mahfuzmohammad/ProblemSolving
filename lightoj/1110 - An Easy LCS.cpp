#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <algorithm>

#define MAXN 110

using namespace std;

int arr[MAXN + 2][MAXN + 2];
string ds[MAXN + 2][MAXN + 2];

void reset()
{
    for(int i = 0; i <= MAXN; i++)
        for(int j = 0; j <= MAXN; j++) {
            arr[i][j] = -1;
            ds[i][j] = "";
        }
}

void LCSgen(string& X, string& Y, int i, int j){
    for(int m = 0; m <= i; m++){arr[m][0] = 0; ds[m][0] = "";}
    for(int n = 0; n <= j; n++){arr[0][n] = 0; ds[0][n] = "";}

    for(int m = 1; m <= i; m++){
        for(int n = 1; n <= j; n++){
            if(X[m - 1] == Y[n - 1]){
                arr[m][n] = 1 + arr[m - 1][n - 1];
                ds[m][n] = ds[m - 1][n - 1] + X[m - 1];
            } else if(arr[m -1][n] >= arr[m][n - 1]){
                arr[m][n] = arr[m - 1][n];
                if(arr[m - 1][n] == arr[m][n - 1]){
                    ds[m][n] = (ds[m - 1][n] < ds[m][n - 1])?ds[m - 1][n]:ds[m][n - 1];
                } else {
                    ds[m][n] = ds[m - 1][n];
                }
            } else {
                arr[m][n] = arr[m][n - 1];
                ds[m][n] = ds[m][n - 1];
            }
        }
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int T, xsize, ysize;
    string X, Y;

    scanf("%d", &T);
    for(int i = 1; i <= T; i++){
        reset();
        cin >> X >> Y;
        xsize = X.size(); ysize = Y.size();
        LCSgen(X, Y, xsize, ysize);

        printf("Case %d: ", i);
        if(arr[xsize][ysize] == 0) printf(":(");
        else {
            cout << ds[xsize][ysize];
        }

        printf("\n");
    }

    return 0;
}
