#include <bits/stdc++.h>

using namespace std;

vector<int> v;

int main() {
    ios_base::sync_with_stdio(false);
    int n, l, r, ql, qr, temp;

    cin >> n >> l >> r >> ql >> qr;
    v.push_back(0);

    for(int i = 1; i <= n; i++) {
        cin >> temp;
        v.push_back(temp);
        v[i] += v[i - 1];
    }

    int ans = 1 << 30;

    for(int i = 0; i <= n; i++) {
        int curr = v[i] * l + (v[n] - v[i]) * r;

        if(i > (n - i)) curr += (2 * i - n - 1) * ql;
        if(i < (n - i)) curr += (n - 2 * i - 1) * qr;

        ans = min(ans, curr);
    }

    cout << ans << endl;

    return 0;
}
