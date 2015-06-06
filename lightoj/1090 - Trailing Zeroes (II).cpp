#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>

#define maxrange 1000000

using namespace std;

struct info {
    int i5, i2;
};

info arr[maxrange + 2];

inline int noOf0(int x, int a){
    int ans = 0;
    while(x % a == 0){
        ans++;
        x /= a;
    }

    return ans;
}

void preGenFact()//generates the numbers of 5's in factorials
{
    for(int i = 1; i <= maxrange; i++){
        arr[i].i5 = arr[i - 1].i5 + noOf0(i, 5);
        arr[i].i2 = arr[i - 1].i2 + noOf0(i, 2);
    }
}

info pq(int p, int q){
    info temp;
    temp.i5 = noOf0(p, 5) * q;
    temp.i2 = noOf0(p, 2) * q;
    return temp;
}

int trailingZero(int n, int r, int p, int q){
    info temp = pq(p, q);

    return min(arr[n].i5 - arr[r].i5 - arr[n - r].i5 + temp.i5, arr[n].i2 - arr[r].i2 - arr[n - r].i2 + temp.i2);
}

int main()
{
    //freopen("input.txt", "r", stdin);
    preGenFact();
    int t, n, r, p, q;

    cin >> t;

    for(int i = 1; i <= t; i++){
        cin >> n >> r >> p >> q;
        cout << "Case " << i << ": " << trailingZero(n, r, p, q) << endl;
    }

    return 0;
}
