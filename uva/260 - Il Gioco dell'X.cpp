//UVA 260 - Il Gioco dell'X.cpp

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>

#define MAXN 200
#define WHITE 1
#define BLACK 2

using namespace std;

int graph[MAXN + 5][MAXN + 5];//stores input data
int temp[MAXN + 5][MAXN + 5];//stores dfs results
stack<int> blacks;//blacks in the last row
bool blackWin;

void resetGraph(){
    blackWin = false;
    for(int i = 0; i <= MAXN; i++){
        for(int j = 0; j <= MAXN; j++){
            graph[i][j] = 0;
            temp[i][j] = 0;
        }
    }
}//end of resetGraph


void dfs(int i, int j, int N){
    if(i < 1 || j < 1 || i > N || j > N) return;
    if(temp[i][j] != 0) return;

    if(i == 1 && graph[i][j] == BLACK){
        blackWin = true;
        temp[i][j] = 1;
    } else if(graph[i][j] == WHITE){
        return;
    } else {
        temp[i][j] = 1;
        dfs( i-1 , j-1 , N );
        dfs( i-1 ,  j , N );
        dfs( i, j-1 , N );
        dfs( i, j+1 , N );
        dfs( i+1 ,  j , N );
        dfs( i+1 , j+1 , N );
    }
}//end of dfs

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int N, cas = 0;
    string input;

    cin >> N;

    while(N != 0){
        resetGraph();

        for(int i = 1; i <= N; i++){
            cin >> input;
            for(int j = 1; j <= N; j++){
                if(input[j-1] == 'w'){
                    graph[i][j] = WHITE;
                } else {
                    graph[i][j] = BLACK;
                    if(i == N) blacks.push(j);
                }
            }
        }//end of for

        cout << ++cas << " ";
        while(!blacks.empty()){
            int x = blacks.top();
            blacks.pop();

            if(temp[N][x] == 0){
                dfs(N, x, N);
            }
        }
        if(blackWin){
            cout << "B" << endl;
        } else {
            cout << "W" << endl;
        }

        cin >> N;
    }//end of while

    return 0;
}
