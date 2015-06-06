#include <bits/stdc++.h>
#define ll long long

using namespace std;

string str;
ll b, s, c, bc, sc, cc, bank, ans = 0;
ll bn = 0, sn = 0, cn = 0;

bool isPos(ll num) {
    ll bneed = bn * num;
    ll sneed = sn * num;
    ll cneed = cn * num;

    bneed = max(0LL, bneed - b);
    sneed = max(0LL, sneed - s);
    cneed = max(0LL, cneed - c);

    return (bank >= ( (bneed * bc)  + (sneed * sc) + (cneed * cc) ));
}

int main() {

    cin >> str;
    cin >> b >> s >> c;
    cin >> bc >> sc >> cc;
    cin >> bank;

    for(int i = 0; i < str.size(); i++) {
        if(str[i] == 'B') {
            bn++;
        } else if (str[i] == 'S') {
            sn++;
        } else if (str[i] == 'C') {
            cn++;
        }
    }

    ll low = 0LL, high = 2000000000000LL;
    ll ans = 0;

    while (low <= high) {
        ll mid = (low + high) / 2;

        if(isPos(mid)) {
            ans = max(ans, mid);
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << ans << endl;

    return 0;
}
