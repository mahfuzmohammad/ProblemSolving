#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll calcMOD(ll b, ll p, ll m) {
    if(p == 0L) return 1L;
    ll ret = calcMOD(b, p/2L, m);
    ret *= ret;
    if(p % 2L == 1L)
        ret *= b;

    return ret % m;
}

int main() {
    ll B, P, M;

    while(cin >> B >> P >> M) {
        cout << calcMOD(B, P, M) << "\n";
    }

    return 0;
}
