/* Generalized recurrence relation
   for finding the lcs among 3 strings

	if A[i] = B[j] = C[k]
	   dp[i, j, k] = 1 + dp[i - 1, j - 1, k - 1]
	else
           max(dp[i - 1, j, k], dp[i, j - 1, k], dp[i, j, k - 1])

*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <algorithm>

#define MAXN 2000

using namespace std;

typedef enum {NIL, UP, LEFT, CORNER} DIRECTION;
typedef struct {
    int len;
    DIRECTION dir;
} Obj;

Obj arr[MAXN + 2][MAXN + 2];

void reset()
{
    Obj o; o.len = -1; o.dir = NIL;
    for(int i = 0; i <= MAXN; i++)
        for(int j = 0; j <= MAXN; j++)
            arr[i][j] = o;
}

void LCSgen(string& X, string& Y, int i, int j){
    for(int m = 0; m <= i; m++){arr[m][0].len = 0;}
    for(int n = 0; n <= j; n++){arr[0][n].len = 0;}

    for(int m = 1; m <= i; m++){
        for(int n = 1; n <= j; n++){
            if(X[m - 1] == Y[n - 1]){
                arr[m][n].len = 1 + arr[m - 1][n - 1].len;
                arr[m][n].dir = CORNER;
            } else if(arr[m -1][n].len >= arr[m][n - 1].len){
                arr[m][n].len = arr[m - 1][n].len;
                arr[m][n].dir = UP;
            } else {
                arr[m][n].len = arr[m][n - 1].len;
                arr[m][n].dir = LEFT;
            }
        }
    }
}

void LCSprint(string& X, int i, int j){
    if(i == 0 || j == 0) return;
    if(arr[i][j].dir == CORNER){
        LCSprint(X, i - 1, j - 1);
        cout << X[i - 1];
    } else if(arr[i][j].dir == UP){
        LCSprint(X, i - 1, j);
    } else {
        LCSprint(X, i, j - 1);
    }
}

int main()
{
    string X, Y;
    cin >> X >> Y;
    reset();
    LCSgen(X, Y, X.size(), Y.size());
    cout << arr[X.size()][Y.size()].len << endl;
    LCSprint(X, X.size(), Y.size());
    cout << endl;

    return 0;
}
