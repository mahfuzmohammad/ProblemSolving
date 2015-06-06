#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

#define MAXN 200

using namespace std;

typedef struct {
    int x, y;
} Point;

stack<Point> fires;
vector<int> v;

char map[MAXN + 2][MAXN + 2];
int fireT[MAXN + 2][MAXN + 2];
int janeT[MAXN + 2][MAXN + 2];

void reset()
{
    v.clear();
    while(!fires.empty()){
        fires.pop();
    }

    for(int i = 0; i <= MAXN; i++){
        for(int j = 0; j <= MAXN; j++){
            fireT[i][j] = 1000000;
            janeT[i][j] = -1;
        }
    }
}

void bfsfire(Point pt, int R, int C)
{
    Point temp;
    queue<Point> q;
    temp = pt;
    q.push(temp);
    fireT[temp.x][temp.y] = 0;

    while(!q.empty()){
        temp = q.front();
        q.pop();
        if(map[temp.x][temp.y + 1] != '#' && (fireT[temp.x][temp.y] + 1) < fireT[temp.x][temp.y + 1] && temp.y + 1 < C){
            fireT[temp.x][temp.y + 1] = fireT[temp.x][temp.y] + 1;
            temp.y += 1;
            q.push(temp);
            temp.y -= 1;
        }

        if(map[temp.x][temp.y - 1] != '#' && (fireT[temp.x][temp.y] + 1) < fireT[temp.x][temp.y - 1] && temp.y - 1 >= 0){
            fireT[temp.x][temp.y - 1] = fireT[temp.x][temp.y] + 1;
            temp.y -= 1;
            q.push(temp);
            temp.y += 1;
        }

        if(map[temp.x + 1][temp.y] != '#' && (fireT[temp.x][temp.y] + 1) < fireT[temp.x + 1][temp.y] && temp.x + 1 < R){
            fireT[temp.x + 1][temp.y] = fireT[temp.x][temp.y] + 1;
            temp.x += 1;
            q.push(temp);
            temp.x -= 1;
        }

        if(map[temp.x - 1][temp.y] != '#' && (fireT[temp.x][temp.y] + 1) < fireT[temp.x - 1][temp.y] && temp.x - 1 >= 0){
            fireT[temp.x - 1][temp.y] = fireT[temp.x][temp.y] + 1;
            temp.x -= 1;
            q.push(temp);
            temp.x += 1;
        }
    }
}

void bfs(Point pt, int R, int C){
    Point temp;
    temp = pt;
    queue<Point> q;
    q.push(temp);
    janeT[temp.x][temp.y] = 0;

    while(!q.empty()){
        temp = q.front();
        q.pop();
        if(temp.x == R - 1 || temp.y == C - 1 || temp.x == 0 || temp.y == 0){v.push_back(janeT[temp.x][temp.y]); /*cout << "BFS " << temp.x << " " << temp.y << endl;*/}

        if(map[temp.x][temp.y + 1] != '#' && janeT[temp.x][temp.y + 1] == -1 && (janeT[temp.x][temp.y] + 1 < fireT[temp.x][temp.y + 1]) && temp.y + 1 < C){
            janeT[temp.x][temp.y + 1] = janeT[temp.x][temp.y] + 1;
            temp.y += 1;
            q.push(temp);
            temp.y -= 1;
        }

        if(map[temp.x][temp.y - 1] != '#' && janeT[temp.x][temp.y - 1] == -1 && (janeT[temp.x][temp.y] + 1 < fireT[temp.x][temp.y - 1]) && temp.y - 1 >= 0){
            janeT[temp.x][temp.y - 1] = janeT[temp.x][temp.y] + 1;
            temp.y -= 1;
            q.push(temp);
            temp.y += 1;
        }

        if(map[temp.x + 1][temp.y] != '#' && janeT[temp.x + 1][temp.y] == -1 && (janeT[temp.x][temp.y] + 1 < fireT[temp.x + 1][temp.y]) && temp.x + 1 < R){
            janeT[temp.x + 1][temp.y] = janeT[temp.x][temp.y] + 1;
            temp.x += 1;
            q.push(temp);
            temp.x -= 1;
        }

        if(map[temp.x - 1][temp.y] != '#' && janeT[temp.x - 1][temp.y] == -1 && (janeT[temp.x][temp.y] + 1 < fireT[temp.x - 1][temp.y]) && temp.x - 1 >= 0){
            janeT[temp.x - 1][temp.y] = janeT[temp.x][temp.y] + 1;
            temp.x -= 1;
            q.push(temp);
            temp.x += 1;
        }
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int T, R, C;
    char ch;
    Point pt, start;

    cin >> T;

    for(int i = 1; i <= T; i++){
        reset();
        cin >> R >> C;

        for(int m = 0; m < R; m++){
            for(int n = 0; n < C; n++){
                cin >> ch;
                map[m][n] = ch;
                if(ch == 'J'){
                    start.x = m;
                    start.y = n;
                } else if(ch == 'F'){
                    pt.x = m;
                    pt.y = n;
                    fires.push(pt);
                }
            }
        }

        while(!fires.empty()){
            bfsfire(fires.top(), R, C);
            fires.pop();
        }

        bfs(start, R, C);
        sort(v.begin(), v.end());

        cout << "Case " << i << ": ";
        if(v.empty()) cout << "IMPOSSIBLE" << endl;
        else cout << v[0] + 1 << endl;
    }

    return 0;
}
