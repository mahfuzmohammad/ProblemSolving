/*UVA 10189 - Minesweeper*/

#include <iostream>
#include <cstdio>
#include <vector>
#define MAXRC 100

using namespace std;

int dataTbl[MAXRC + 5][MAXRC + 5];

void reset(){
    for(int i = 0; i <= MAXRC; i++){
        for(int j = 0; j <= MAXRC; j++){
            dataTbl[i][j] = 0;
        }
    }
}//end of reset

void genRes(int r, int c){
    dataTbl[r][c] = -1; //-1 represents *
    if(dataTbl[r - 1][c - 1] != -1)
        dataTbl[r - 1][c - 1] += 1;

    if(dataTbl[r - 1][c] != -1)
        dataTbl[r - 1][c] += 1;

    if(dataTbl[r - 1][c + 1] != -1)
        dataTbl[r - 1][c + 1] += 1;

    if(dataTbl[r][c - 1] != -1)
        dataTbl[r][c - 1] += 1;

    if(dataTbl[r][c + 1] != -1)
        dataTbl[r][c + 1] += 1;

    if(dataTbl[r + 1][c - 1] != -1)
        dataTbl[r + 1][c - 1] += 1;

    if(dataTbl[r + 1][c] != -1)
        dataTbl[r + 1][c] += 1;

    if(dataTbl[r + 1][c + 1] != -1)
        dataTbl[r + 1][c + 1] += 1;
}//end of genRes function

void printRes(int r, int c){
    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= c; j++){
            if(dataTbl[i][j] == -1){
                cout << "*";
            } else {
                cout << dataTbl[i][j];
            }//end of if else
        }//end of inner for
        cout << endl;
    }//end of outer for
}//end of printRes function

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int m, n, kase = 0;
    char input;

    cin >> m >> n;

    while( m != 0 && n != 0){
        reset();//reset the dataTbl

        //input section
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                cin >> input;

                if(input == '*'){
                    genRes(i, j);
                }//end of if
            }//end of inner for
        }//end of outer for
        //end of input section

        //output section
        cout << "Field #" << ++kase << ":" << endl;
        printRes(m, n);
        //end of output section

        cin >> m >> n;
        if(m != 0 && n != 0){
            cout << endl;
        }
    }//end of while loop

    return 0;
}
