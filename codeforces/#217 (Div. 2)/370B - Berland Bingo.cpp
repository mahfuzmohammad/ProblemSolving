#include <bits/stdc++.h>

using namespace std;

bool wins[105];
vector<int> v[105];

int main() {

    int n, m, a;
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &m);
        for(int j = 0; j < m; j++) {
            scanf("%d", &a);
            v[i].push_back(a);
        }

        sort(v[i].begin(), v[i].end());
    }

    memset(wins, true, sizeof wins);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == j) continue;
            int has = 0;
            for(int k = 0; k < v[j].size(); k++) {
                has += binary_search(v[i].begin(), v[i].end(), v[j][k]);
            }

            if ( (v[i].size() >= v[j].size() && v[j].size() == has) ) {
                wins[i] = false;
                break;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        if(wins[i]) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
