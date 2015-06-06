#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

#define maxn 100

using namespace std;

int xs[maxn + 1], xe[maxn + 1],
    ys[maxn + 1], ye[maxn + 1],
    zs[maxn + 1], ze[maxn + 1];

int main()
{
    //freopen("input.txt", "r", stdin);
    int T, n, ans;
    cin >> T;

    for(int i = 1; i <= T; i++){
        cin >> n;
        for(int j = 0; j < n; j++){
            cin >> xs[j] >> ys[j] >> zs[j] >> xe[j] >> ye[j] >> ze[j];
        }

        ans = (*min_element(xe, xe + n) - *max_element(xs, xs + n)) * (*min_element(ye, ye + n) - *max_element(ys, ys + n)) * (*min_element(ze, ze + n) - *max_element(zs, zs + n));
        cout << "Case " << i << ": " << ((ans < 0)?0:ans) << endl;
    }

    return 0;
}
