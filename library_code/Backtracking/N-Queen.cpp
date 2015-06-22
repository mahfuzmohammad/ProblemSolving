#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>

#define MAXROWCOL 100

using namespace std;

typedef struct {
    int r, c;
} point;

bool rowtaken[MAXROWCOL + 2],
     coltaken[MAXROWCOL + 2];

vector<point> v;
point temp;
int test = 0;

bool diagtaken(int r, int c){
    int vsize = v.size();

    for(int i = 0; i < vsize; i++){
        if(fabs(v[i].r - r) == fabs(v[i].c - c)){return true;}
    }

    return false;
}

void nqueen(int q, int& totalq){
    if(q == totalq){
        test++;
    } else {
        for(int j = 0; j < totalq; j++){
            if(!rowtaken[q] && !coltaken[j] && !diagtaken(q, j)){
                rowtaken[q] = true;
                coltaken[j] = true;
                temp.r = q; temp.c = j;
                v.push_back(temp);
                nqueen(q + 1, totalq);
                rowtaken[q] = false;
                coltaken[j] = false;
                v.pop_back();
            }
        }
    }
}

int main()
{
    int q;
    cin >> q;

    while(q != 0){
        test = 0;
        nqueen(0, q);
        cout << "Possible arrangement: " << test << endl;
        cin >> q;
    }

    return 0;
}
