#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

#define MAXN 20
#define debug for(int o = 1; o <= MAXN; o++){for(int p = 1; p <= MAXN; p++){cout << color[o][p] << " ";} cout << endl;}

using namespace std;

struct point {
    int x, y;
} arr[4];//0 - a, 1 - b, 2 - c, 3 - h

char map[MAXN + 2][MAXN + 2];
int color[MAXN + 2][MAXN + 2];

void reset(){
    for(int i = 0; i <= MAXN; i++){
        for(int j = 0; j <= MAXN; j++){
            color[i][j] = 0;
        }
    }
}

void BFS(int x, int y){
    queue<point> q;
    point u;
    u.x = x; u.y = y;
    color[x][y] = 0;
    q.push(u);

    while(!q.empty()){
        u = q.front();
        q.pop();

        if((map[u.x][u.y +1] == '.' || map[u.x][u.y +1] == 'a' || map[u.x][u.y +1] == 'b' || map[u.x][u.y +1] == 'c') && color[u.x][u.y + 1] == 0){
            color[u.x][u.y + 1] = color[u.x][u.y] + 1;
            u.y += 1; q.push(u); u.y -= 1;
        }

        if((map[u.x][u.y -1] == '.' || map[u.x][u.y -1] == 'a' || map[u.x][u.y -1] == 'b' || map[u.x][u.y -1] == 'c') && color[u.x][u.y - 1] == 0){
            color[u.x][u.y - 1] = color[u.x][u.y] + 1;
            u.y -= 1; q.push(u); u.y += 1;
        }

        if((map[u.x + 1][u.y] == '.' || map[u.x + 1][u.y] == 'a' || map[u.x + 1][u.y] == 'b' || map[u.x + 1][u.y] == 'c') && color[u.x + 1][u.y] == 0){
            color[u.x + 1][u.y] = color[u.x][u.y] + 1;
            u.x += 1; q.push(u); u.x -= 1;
        }

        if((map[u.x - 1][u.y] == '.' || map[u.x - 1][u.y] == 'a' || map[u.x - 1][u.y] == 'b' || map[u.x - 1][u.y] == 'c') && color[u.x - 1][u.y] == 0){
            color[u.x - 1][u.y] = color[u.x][u.y] + 1;
            u.x -= 1; q.push(u); u.x += 1;
        }
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int T, m, n;
    char ch;

    cin >> T;

    for(int i = 1; i <= T; i++){
        reset();
        cin >> m >> n;

        for(int j = 1; j <= m; j++){
            for(int k = 1; k <= n; k++){
                cin >> ch;
                map[j][k] = ch;
                if(ch == '.') color[j][k] = 0;
                else if(ch == 'a') {arr[0].x = j; arr[0].y = k;}
                else if(ch == 'b') {arr[1].x = j; arr[1].y = k;}
                else if(ch == 'c') {arr[2].x = j; arr[2].y = k;}
                else if(ch == 'h') {arr[3].x = j; arr[3].y = k;}
            }
        }

        BFS(arr[3].x, arr[3].y);
        cout << "Case " << i << ": " << max(color[arr[0].x][arr[0].y], max(color[arr[1].x][arr[1].y], color[arr[2].x][arr[2].y])) << endl;
        //debug;
    }

    return 0;
}
