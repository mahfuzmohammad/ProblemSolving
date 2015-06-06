#include <iostream>
#include <cstdio>
#include <queue>
#define maxN 11
#define notPossible -1

using namespace std;

char inputTbl[maxN + 2][maxN + 2];
int temp[maxN + 2][maxN + 2];
/*int result;*/

void reset(){
    //result = 0;
    for(int i = 0; i <= maxN; i++){
        for(int j = 0; j <= maxN; j++){
            temp[i][j] = notPossible;
        }
    }
}

struct Point {
    int r;
    int c;
    Point(){}
    Point(int row, int col) {r = row; c = col;}
};

Point foodList[30];

//queue<char> foods;

bool canGo(int N, int r, int c, char food){
    if(r >= 1 && r <= N && c >= 1 && c <= N && temp[r][c] == notPossible){
        if(inputTbl[r][c] == '.')
            return true;

        if(inputTbl[r][c] == food)
            return true;
    }

    return false;
}

int BFS(int foods, int N, Point start){
    if(foods == 0) return notPossible;
    if(foods == 1) return 0;

    char nextFood = 'B';
    //int minDist = 0;
    queue<Point> q;
    q.push(start);
    temp[start.r][start.c] = 0;
    Point pt;
    //bool flag;

    while(!q.empty()){
        pt = q.front();
        q.pop();

        //right
        if(canGo(N, pt.r, pt.c + 1, nextFood)){
            q.push(Point(pt.r, pt.c + 1));
            temp[pt.r][pt.c + 1] = temp[pt.r][pt.c] + 1;
            if(inputTbl[pt.r][pt.c + 1] == nextFood){
                ++nextFood;
            }
        }

        //left
        if(canGo(N, pt.r, pt.c - 1, nextFood)){
            q.push(Point(pt.r, pt.c - 1));
            temp[pt.r][pt.c - 1] = temp[pt.r][pt.c] + 1;
            if(inputTbl[pt.r][pt.c - 1] == nextFood){
                ++nextFood;
            }
        }

        //up
        if(canGo(N, pt.r - 1, pt.c, nextFood)){
            q.push(Point(pt.r - 1, pt.c));
            temp[pt.r - 1][pt.c] = temp[pt.r][pt.c] + 1;
            if(inputTbl[pt.r - 1][pt.c] == nextFood){
                ++nextFood;
            }
        }

        //down
        if(canGo(N, pt.r + 1, pt.c, nextFood)){
            q.push(Point(pt.r + 1, pt.c));
            temp[pt.r + 1][pt.c] = temp[pt.r][pt.c] + 1;
            if(inputTbl[pt.r + 1][pt.c] == nextFood){
                ++nextFood;
            }
        }
    }//end of while

    return temp[foodList[foods].r][foodList[foods].c];
}


int main()
{
    freopen("input.txt", "r", stdin);
    int T, N, foods, result;
    Point* start;
    //Point* end = new Point(0, 0);
    cin >> T;

    for(int i = 1; i <= T; i++) {
        reset();
        cin >> N;
        foods = 0;

        for(int j = 1; j <= N; j++) {
            for(int k = 1; k <= N; k++) {
                cin >> inputTbl[j][k];
                if(inputTbl[j][k] >= 'A' && inputTbl[j][k] <= 'Z'){
                    foods += 1;
                    /*delete end;
                    end = new Point(j, k);*/
                    int foodInd = inputTbl[j][k] % 64;
                    foodList[foodInd].r = j;
                    foodList[foodInd].c = k;
                    if(inputTbl[j][k] == 'A'){start = new Point(j, k);}
                }
            }
        }//end of input

        //cout << foods << endl;

        //output
        result = BFS(foods, N, *start);
        cout << "Case " << i << ": ";
        if(result == -1){
            cout << "Impossible";
        } else {
            cout << result;
        }

        cout << endl;

        /*for(int a = 1; a <= N; a++){
            for(int b = 1; b <= N; b++){
                cout << temp[a][b] << " ";
            }
            cout << endl;
        }*/
    }


    return 0;
}
