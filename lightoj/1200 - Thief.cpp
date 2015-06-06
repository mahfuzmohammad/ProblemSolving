#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>

#define MAXN 100
#define MAXW 10000

using namespace std;

struct Obj {
    int p, c, w;
    Obj(){}
    Obj(int P, int C, int W):p(P), c(C), w(W){}
};

vector<Obj> v;

int profit[MAXW + 2];

int main() {
    #ifdef mahfuz
    freopen("input.txt", "r", stdin);
    #endif

    int T, N, W, p, c, w, totw;
    cin >> T;

    for(int i = 1; i <= T; i++) {

        memset(profit, 0, sizeof(profit));
        v.clear();
        totw = 0;
        cin >> N >> W;

        for(int j = 0; j < N; j++) {
            cin >> p >> c >> w;
            totw += (c * w);
            v.push_back( Obj(p, c, w) );
        }

        cout << "Case " << i << ": ";

        if(totw > W) {
            cout << "Impossible" << endl;
        } else {

            for(int weight = 1; weight <= W - totw; weight++) {
                for(int item = 0; item < N; item++) {
                    if(v[item].w <= weight) {
                        profit[weight] = max(profit[weight], v[item].p + profit[weight - v[item].w]);
                    }
                }
            }

            cout << profit[W - totw] << endl;

        }

    }

    return 0;
}
