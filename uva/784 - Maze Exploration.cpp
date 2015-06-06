//UVA 784 - Maze Exploration.cpp

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

#define MAXWH 80

using namespace std;

char maze[MAXWH + 5][MAXWH + 5];

void reset(){
    for(int i = 0; i <= MAXWH; i++){
        for(int j = 0; j <= MAXWH; j++){
            maze[i][j] = ' ';
        }
    }
}//end of reset()

void paint(int r, int c, int w, int h){
    if(r < 0 || c < 0 || r >= h || c >= w){return;}
    if(maze[r][c] != ' ' || maze[r][c] == '#'){return;}

    maze[r][c] = '#';

    paint(r, c + 1, w, h);
    paint(r, c - 1, w, h);
    paint(r - 1, c, w, h);
    paint(r + 1, c, w, h);
    /*paint(r + 1, c + 1, w, h);
    paint(r + 1, c - 1, w, h);
    paint(r - 1, c + 1, w, h);
    paint(r - 1, c - 1, w, h);*/
}//end of paint()


int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int row, col, mazeNo, strSize, startr, startc;
    string str, clr, dividor;
    int colLength[35];

    cin >> mazeNo;
    getline(cin, clr);//clears newline character from input stream

    for(int i = 0; i < mazeNo; i++){
        reset();
        row = 0; col = 0;
        while(getline(cin, str)){
            if(str[0] == '_') {
                dividor = str;
                break;
            }

            strSize = str.size();
            colLength[row] = strSize;
            ++row;
            col = max(col, strSize);

            for(int j = 0; j < strSize; j++){
                if(str[j] == '*'){
                    startr = row - 1;
                    startc = j;
                } else {
                    maze[row - 1][j] = str[j];
                }
            }
        }//end of while

        paint(startr, startc, col, row);

        for(int j = 0; j < row; j++){
            for(int k = 0; k < colLength[j]; k++){
                cout << maze[j][k];
            }
            cout << endl;
        }

        cout << dividor << endl;
    }//

    return 0;
}//end of main()
