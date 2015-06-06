#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>

#define MAXN 100

using namespace std;

char map[MAXN + 5];
int mapmark[MAXN + 5];

int main()
{
    //freopen("input.txt", "r", stdin);
    int T, N = 0, count, dotcount;
    cin >> T;

    for(int i = 1; i <= T; i++){
        for(int j = 0; j < N; j++){mapmark[j] = 0;}
        count = 0; dotcount = 0;

        cin >> N;
        for(int j = 0; j < N; j++){
            cin >> map[j];
        }

        for(int j = 0; j < N; ){
            if(map[j] == '.'){
                count++;
                j+= 3;
            } else {j++;}
        }

        cout << "Case " << i << ": " << count << endl;
    }

    return 0;
}
