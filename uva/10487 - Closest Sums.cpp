#include <bits/stdc++.h>

using namespace std;

vector<int> v;

int main() {
    ios_base::sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);
    int n, a, m, q, mx, mn, cas = 0;

    while(cin >> n) {
        cas++;
        v.clear();
        if(n == 0) break;
        for(int i = 0; i < n; i++) {
            cin >> a;
            v.push_back(a);
        }

        //mx = *max_element(v.begin(), v.end());
        //mn = *min_element(v.begin(), v.end());

        cout << "Case " << cas << ":\n";
        cin >> m;
        for(int i = 0; i < m; i++) {
            cin >> q;
            int diff = 1000000000, sum, temp;
            for(int j = 0; j < n; j++) {
                for(int k = 0; k < n; k++) {
                    if(j == k) continue;
                    temp = v[j] + v[k];
                    if(diff > abs(temp - q)) {
                        diff = abs(temp - q);
                        sum = temp;
                    }
                }
            }

            cout << "Closest sum to " << q << " is " << sum << ".\n";
        }
    }

    return 0;
}
