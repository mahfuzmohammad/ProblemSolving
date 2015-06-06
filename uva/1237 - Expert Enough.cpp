#include <bits/stdc++.h>

using namespace std;

struct data {
    string name;
    int l, h;
};

vector<data> v;

int main() {
    ios_base::sync_with_stdio(0);
    int t, n, q, p;
    data temp;

    cin >> t;

    for(int i = 0; i < t; i++) {
        if(i > 0) cout << "\n";
        v.clear();
        cin >> n;
        for(int j = 0; j < n; j++) {
            cin >> temp.name >> temp.l >> temp.h;
            v.push_back(temp);
        }

        cin >> q;
        for(int j = 0; j < q; j++) {
            cin >> p;
            int cnt = 0, indx = -1;
            for(int k = 0; k < n; k++) {
                if(v[k].l <= p && v[k].h >= p) {
                    cnt++;
                    indx = k;
                }
            }

            if(cnt == 1) {
                cout << v[indx].name << "\n";
            } else {
                cout << "UNDETERMINED\n";
            }
        }
    }

    return 0;
}
