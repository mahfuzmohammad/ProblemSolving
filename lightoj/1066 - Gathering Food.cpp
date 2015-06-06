#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
#include <list>
#include <stack>
#include <sstream>
#include <algorithm>

#define MAXN 11
#define print for(int m = 0; m < n; m++){for(int l = 0; l < n; l++){cout << visit[m][l] << " ";}cout << endl;}cout << endl;
#define printmap for(int m = 0; m < n; m++){for(int l = 0; l < n; l++){cout << map[m][l] << " ";}cout << endl;}cout << endl;

using namespace std;

struct Point {
    int r, c;
};

char map[MAXN + 2][MAXN + 2];
int visit[MAXN + 2][MAXN + 2];
Point arr[27];

void reset()
{
    for(int i = 0; i <= MAXN; i++)
        for(int j = 0; j <= MAXN; j++)
            visit[i][j] = -1;
}

bool equalPoint(int r, int c, Point& p)
{
    if(map[r][c] >= 'A' && map[r][c] <= 'Z')
        if((r == p.r) && (c == p.c)){
            map[r][c] = '.';
            return true;
        } else return false;

    return true;
}

void BFS(int no, int& n){
    reset();
    Point node = arr[no];
    queue<Point> q;
    Point u, temp; int nextP = no + 1;
    q.push(node);
    visit[node.r][node.c] = 0;
    map[node.r][node.c] = '.';

    while(!q.empty()){
        u = q.front();
        q.pop();

        if(map[u.r][u.c + 1] != '#' && visit[u.r][u.c + 1] == -1 && u.c + 1 < n && equalPoint(u.r, u.c + 1, arr[nextP])){
            visit[u.r][u.c + 1] = visit[u.r][u.c] + 1;
            temp.r = u.r; temp.c = u.c + 1;
            if(map[u.r][u.c + 1] >= 'A' && map[u.r][u.c + 1] <= 'Z') nextP++;
            q.push(temp);
        }

        if(map[u.r][u.c - 1] != '#' && visit[u.r][u.c - 1] == -1 && u.c - 1 >= 0 && equalPoint(u.r, u.c - 1, arr[nextP])){
            visit[u.r][u.c - 1] = visit[u.r][u.c] + 1;
            temp.r = u.r; temp.c = u.c - 1;
            if(map[u.r][u.c - 1] >= 'A' && map[u.r][u.c - 1] <= 'Z') nextP++;
            q.push(temp);
        }

        if(map[u.r + 1][u.c] != '#' && visit[u.r + 1][u.c] == -1 && u.r + 1 < n && equalPoint(u.r + 1, u.c, arr[nextP])){
            visit[u.r + 1][u.c] = visit[u.r][u.c] + 1;
            temp.r = u.r + 1; temp.c = u.c;
            if(map[u.r + 1][u.c] >= 'A' && map[u.r + 1][u.c] <= 'Z') nextP++;
            q.push(temp);
        }

        if(map[u.r - 1][u.c] != '#' && visit[u.r - 1][u.c] == -1 && u.r - 1 >= 0 && equalPoint(u.r - 1, u.c, arr[nextP])){
            visit[u.r - 1][u.c] = visit[u.r][u.c] + 1;
            temp.r = u.r - 1; temp.c = u.c;
            if(map[u.r - 1][u.c] >= 'A' && map[u.r - 1][u.c] <= 'Z') nextP++;
            q.push(temp);
        }
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int T, n, food, ans;
    bool flag;
    Point p;
    cin >> T;

    for(int i = 1; i <= T; i++){
        cin >> n;
        food = 0; ans = 0; flag = true;

        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                cin >> map[j][k];
                if(map[j][k] >= 'A' && map[j][k] <= 'Z'){p.r = j; p.c = k; arr[map[j][k] - 'A'] = p; food++;}
            }
        }

        BFS(0, n);
        for(int j = 1; j < food; j++){
            if(visit[arr[j].r][arr[j].c] == -1) {flag = false; break;}
            ans += abs(visit[arr[j].r][arr[j].c] - visit[arr[j - 1].r][arr[j - 1].c]);
            BFS(j, n);
        }

        cout << "Case " << i << ": ";
        if(flag) cout << ans;
        else cout << "Impossible";
        cout << endl;
    }

    return 0;
}
