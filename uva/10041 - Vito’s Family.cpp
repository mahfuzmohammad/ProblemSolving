//UVA 10041 - Vito's Family.cpp

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <algorithm>

#define MAXR 500

using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);
    int t, r, s, ans, mid;
    int v[MAXR + 5];

    cin >> t;

    for(int i = 0; i < t; i++){
        ans = 0;
        cin >> r;
        for(int j = 0; j < r; j++){
            cin >> v[j];
        }

        sort(v, v + r);
        mid = v[(r - 1) / 2];
        //cout << "Mid " << mid << endl;

        for(int j = 0; j < r; j++){
            ans += abs(v[j] - mid);
            //cout << "Test" << ans << endl;
        }

        cout << ans << endl;
    }

    return 0;
}
