#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    int n, ans, temp, x;

    while(cin >> n) {
        if(n == 0) break;
        ans = 0, temp = 0;
        for(int i = 0; i < n; i++) {
            cin >> x;
            temp += x;
            ans = max(ans, temp);

            if(temp < 0) {
                temp = 0;
            }
        }

        if(ans == 0) {
            cout << "Losing streak.\n";
        } else {
            cout << "The maximum winning streak is " << ans << ".\n";
        }
    }

    return 0;
}
