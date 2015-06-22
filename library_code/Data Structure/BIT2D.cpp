//Data Structure: 2D BIT
//BIT can be n dimensional
//All are 1 - indexed
#include <bits/stdc++.h>

using namespace std;

#define _MAXX 200
#define _MAXY 200

int tree[_MAXX + 5][_MAXY + 5];

int query( int x, int y ) {
    int ret = 0;
    while( x > 0 ) {
        int yy = y;
        while( yy > 0 ) ret += tree[x][yy] , yy -= (yy & -yy) ;
        x -= (x & -x) ;
    }
    return ret ;
}

void update(int x , int y , int val) {//adds val at pos tree[x][y]
    int y1;
    while (x <= _MAXX) {
        y1 = y;
        while (y1 <= _MAXY) {
            tree[x][y1] += val;
            y1 += (y1 & -y1);
        }
        x += (x & -x);
    }
}

//returns rectangular sum from (x1, y1) to (x2, y2)
//where (x1, y1) is the lower left corner and
//(x2, y2) is the upper right corner
int sum( int x1 , int y1 , int x2 , int y2 ){
    int res  = query( x2   , y2   ) ;
        res -= query( x1-1 , y2   ) ;
        res -= query( x2   , y1-1 ) ;
        res += query( x1-1 , y1-1 ) ;
    return res ;
}
