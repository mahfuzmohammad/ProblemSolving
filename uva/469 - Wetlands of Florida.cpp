//UVA 469 - Wetlands of Florida.cpp

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <sstream>
#include <cstdlib>
#include <algorithm>

#define MAXFIELD 99
#define MAXCOLOR 10000

using namespace std;

bool graph[MAXFIELD + 3][MAXFIELD + 3];
int travelled[MAXFIELD + 3][MAXFIELD + 3];
int area[MAXCOLOR];

int color;

void reset(){
    color = -1;
    for(int i = 0; i <= MAXFIELD; i++){
        for(int j = 0; j <= MAXFIELD; j++){
            graph[i][j] = false;
            travelled[i][j] = color;
            area[(i+1) * j] = 0;
        }
    }
}//end of reset

void visit(int r, int c, int width, int height)
{
    if(r < 0 || c < 0 || c >= width || r >= height){
        return;
    }

    if(travelled[r][c] != -1 || !graph[r][c]){
        return;
    }

    travelled[r][c] = color;
    area[color] += 1;

    visit(r, c + 1, width, height);
    visit(r, c - 1, width, height);
    visit(r - 1, c, width, height);
    visit(r + 1, c, width, height);
    visit(r - 1, c + 1, width, height);
    visit(r + 1, c + 1, width, height);
    visit(r + 1, c - 1, width, height);
    visit(r - 1, c - 1, width, height);
}//end of visit


int main()
{
    //freopen("input.txt", "r", stdin);
    int testcase, r, c, width, height;
    string str, clr;

    cin >> testcase;
    getline(cin, clr);
    getline(cin, clr);

    for(int i = 0; i < testcase; i++){
        reset();
        width = 0;
        height = 0;

        while(getline(cin, str)){
            if(str.size() == 0) break;
            if(isalpha(str[0])){
                width = str.size();
                ++height;

                for(int j = 0; j < width; j++){
                    if(str[j] == 'W'){
                        graph[height - 1][j] = true;
                    }
                }
            } else {
                stringstream ss;
                ss << str;
                string splt;
                ss >> splt;
                r = atoi(splt.c_str());
                ss >> splt;
                c = atoi(splt.c_str());

                if(travelled[r][c] == -1){
                    ++color;
                    visit(r - 1, c - 1, width, height);
                }

                cout << area[travelled[r - 1][c - 1]] << endl;
            }

        }//end of while

        if(i < testcase - 1){
            cout << endl;
        }
    }//end of testcase for

    return 0;
}
