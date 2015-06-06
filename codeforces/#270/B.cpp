#include <bits/stdc++.h>

using namespace std;

vector<int> v;

bool cmp(int a, int b) {
    return (a > b);
}

int main() {
    ios_base::sync_with_stdio(0);
    int n, k, x, ans = 0;
    cin >> n >> k;

    for(int i = 0; i < n; i++) {
        cin >> x;
        v.push_back(x);
    }

    sort(v.begin(), v.end(), cmp);
    int indx = 0;

    while(indx < n) {
        ans += ((v[indx] - 1) * 2);
        indx += k;
    }

    cout << ans << "\n";

    return 0;
}
