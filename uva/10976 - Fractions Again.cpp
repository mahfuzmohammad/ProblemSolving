#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
vector< ii > v;

bool cmp (ii a, ii b) {
    if(a.first == b.first) {
        return a.second < b.second;
    }

    return a.first > b.first;
}

int main() {
    ios_base::sync_with_stdio(0);
    int k, x, ky, y_k;

    while(cin >> k) {
        v.clear();
        for( int y = k + 1; ;y++ ) {
            ky = k*y, y_k = y - k;
            x = ky/y_k;

            if( (ky%y_k) == 0 ) {
                if(x >= y) {
                    v.push_back(ii(x, y));
                } else {
                    break;
                }
            }

            if(x < y) {
                break;
            }
        }

        sort(v.begin(), v.end(), cmp);
        cout << v.size() << "\n";
        for(int i = 0; i < v.size(); i++) {
            cout << "1/" << k << " = " << "1/" << v[i].first << " + " << "1/" << v[i].second << "\n";
        }
    }

    return 0;
}
