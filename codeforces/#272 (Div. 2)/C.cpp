#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll _MOD = 1000000007L;

int main() {
    ios_base::sync_with_stdio(0);
    ll a, b, x = 0, r = 0, tempb;
    cin >> a >> b;

    r = (b-1)*b;
    r /= 2L;
    r %= _MOD;

    tempb = b % _MOD;
    for(int i = 1; i <= a; i++) {
        x += (((((i * tempb) % _MOD) * r) % _MOD) + r) % _MOD;
        x %= _MOD;
    }

    cout << x << "\n";

    return 0;
}
