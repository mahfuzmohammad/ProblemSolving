//UVA 657 - The die is cast.cpp

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>

#define MAXWH 50
#define BACKGROUND 0
#define DIE 1
#define DOT 2
#define VISIT -1

using namespace std;

typedef struct {
    int x;
    int y;
} Point;

queue<Point> q;
vector<int> v;
vector<int> :: iterator vit;

int img[MAXWH + 5][MAXWH + 5];
int imgTravelled[MAXWH + 5][MAXWH + 5];

int dots;

void reset(){
    while(!v.empty()){
        v.pop_back();
    }

    while(!q.empty()){
        q.pop();
    }

    for(int i = 0; i <= MAXWH; i++){
        for(int j = 0; j <= MAXWH; j++){
            img[i][j] = BACKGROUND;
            imgTravelled[i][j] = 0;
        }
    }
}//end of reset

void countDot(int r, int c){
    if(img[r][c] != DOT || imgTravelled[r][c] != 0) return;

    imgTravelled[r][c] = dots;
    countDot(r, c + 1);//right
    countDot(r, c - 1);//left
    countDot(r - 1, c);//top
    countDot(r + 1, c);//bottom
}

void checkImg(int r, int c, int w, int h){
    if(r < 0 || c < 0 || r >= h || c >= w) return;
    if(imgTravelled[r][c] == VISIT || img[r][c] == BACKGROUND) return;

    if(img[r][c] == DOT && imgTravelled[r][c] == 0){
        ++dots;
        countDot(r, c);
    } else {
        imgTravelled[r][c] = VISIT;}

        checkImg(r, c + 1, w, h);//right
        checkImg(r, c - 1, w, h);//left
        checkImg(r - 1, c, w, h);//top
        checkImg(r + 1, c, w, h);//bottom

}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int r, c, Tcase = 0;
    char ch;

    cin >> c >> r;

    while(r != 0 && c != 0){
        reset();
        //if(Tcase != 0) cout << endl;
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                cin >> ch;
                if(ch == '*'){
                    img[i][j] = DIE;
                    Point p;
                    p.x = i;
                    p.y = j;
                    q.push(p);
                }

                if(ch == 'X'){
                    Point p;
                    p.x = i;
                    p.y = j;
                    q.push(p);
                    img[i][j] = DOT;
                }
            }
        }//end of input

        Point temp;

        while(!q.empty()){
            temp = q.front();
            q.pop();

            if(imgTravelled[temp.x][temp.y] == 0){
                /*for(int i = 0; i < r; i++){
                    for(int j = 0; j < c ; j++){
                        cout << imgTravelled[i][j] << " ";
                    }
                    cout << endl;
                }
                cout << endl;*/
                dots = 0;
                checkImg(temp.x, temp.y, c, r);
                v.push_back(dots);
            }
        }//end of while

        sort(v.begin(), v.end());

        cout << "Throw " << ++Tcase << endl;
        for(vit = v.begin(); vit < v.end(); vit++){
            cout << *vit;
            if(vit < v.end() - 1) cout << " ";
        }

        cout << endl << endl;

        /*for(int i = 0; i < r; i++){
            for(int j = 0; j < c ; j++){
                cout << imgTravelled[i][j] << " ";
            }
            cout << endl;
        }*/

        cin >> c >> r;
    }//end of while

    return 0;
}
