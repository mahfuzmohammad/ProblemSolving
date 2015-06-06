#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool pos(ll v, ll cnt1, ll cnt2, ll x, ll y) {
    bool ret = false;
    ll xpabe = v - (v / x);
    ll x_ythekenibe = max(cnt1 - (v / y) + (v / (x*y)), (ll)0);
    ll ypabe = v - (v / y);
    ypabe -= x_ythekenibe;

    return ((xpabe >= cnt1) && (ypabe >= cnt2));
}

int main() {
    ll cnt1, cnt2, x, y;
    cin >> cnt1 >> cnt2 >> x >> y;

    ll lo = 1L, hi = 100000000000000L;

    while(lo <= hi) {
        //cout << lo << " " << endl;
        ll mid = (lo + hi) / 2L;
        if(pos(mid, cnt1, cnt2, x, y)) {
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    cout << lo << "\n";

    return 0;
}
