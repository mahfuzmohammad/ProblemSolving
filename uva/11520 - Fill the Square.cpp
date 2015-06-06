#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>

#define MAXN 10

using namespace std;

char grid[MAXN + 2][MAXN + 2];

bool isAdj(int i, int j, char ch, int n){
    if(i == 0 && j == 0){return ((grid[i][j + 1] == ch) || (grid[i + 1][j] == ch));}
    if(i == 0){return ((grid[i][j + 1] == ch) || (grid[i + 1][j] == ch) || (grid[i][j - 1] == ch));}
    if(j == 0){return ((grid[i][j + 1] == ch) || (grid[i + 1][j] == ch) || (grid[i - 1][j] == ch));}
    if(i == n - 1 && j == n - 1){return ((grid[i][j - 1] == ch) || (grid[i - 1][j] == ch));}
    if(i == n - 1){return ((grid[i][j + 1] == ch) || (grid[i - 1][j] == ch) || (grid[i][j - 1] == ch));}
    if(j == n - 1){return ((grid[i][j - 1] == ch) || (grid[i + 1][j] == ch) || (grid[i - 1][j] == ch));}

    return ((grid[i][j - 1] == ch) || (grid[i][j + 1] == ch) || (grid[i - 1][j] == ch) || (grid[i + 1][j] == ch));
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int  t, n;
    char ch;

    cin >> t;

    for(int i = 1; i <= t; i++){
        cin >> n;
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                cin >> grid[j][k];
            }
        }

        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                ch = 'A';
                if(grid[j][k] != '.') continue;
                while(isAdj(j, k, ch, n)){ch++;}
                grid[j][k] = ch;
            }
        }

        cout << "Case " << i << ":" << endl;
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                cout << grid[j][k];
            }
            cout << endl;
        }
    }

    return 0;
}
