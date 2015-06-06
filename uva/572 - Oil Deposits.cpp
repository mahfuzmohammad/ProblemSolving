//UVA 572 - Oil Deposits.cpp

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

#define MAXMN 100

using namespace std;

typedef struct {
    int x;
    int y;
} Point;

queue<Point> q;

bool map[MAXMN + 5][MAXMN + 5];
int travelledMap[MAXMN + 5][MAXMN + 5];

int oildeposits;

void reset(){
    oildeposits = 0;
    while(!q.empty()){
        q.pop();
    }

    for(int i = 0; i <= MAXMN; i++){
        for(int j = 0; j <= MAXMN; j++){
            map[i][j] = false;
            travelledMap[i][j] = 0;
        }
    }
}//end of reset

void travel(int m, int n, int width, int height){
    if(m <= 0 || n <= 0 || m > height || n > width) return;

    if(travelledMap[m][n] != 0 || !map[m][n]) return;

    travelledMap[m][n] = oildeposits;

    travel(m, n + 1, width, height);//right
    travel(m, n - 1, width, height);//left
    travel(m - 1, n, width, height);//top
    travel(m + 1, n, width, height);//bottom
    travel(m - 1, n + 1, width, height);//top right
    travel(m - 1, n - 1, width, height);//top left
    travel(m + 1, n + 1, width, height);//bottom right
    travel(m + 1, n - 1, width, height);//bottom left
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int m, n;
    char ch;

    cin >> m >> n;

    while(m != 0){
        reset();

        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                cin >> ch;
                if(ch == '@'){
                    map[i][j] = true;
                    Point p;
                    p.x = i;
                    p.y = j;
                    q.push(p);
                }
            }
        }//end of input

        Point temp;

        while(!q.empty()){
            temp = q.front();
            q.pop();

            if(travelledMap[temp.x][temp.y] == 0){
                ++oildeposits;
                travel(temp.x, temp.y, n, m);
            }
        }

        cout << oildeposits << endl;

        cin >> m >> n;
    }//end of while

    return 0;
}//end of main()
