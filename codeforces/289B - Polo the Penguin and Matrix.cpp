#include <bits/stdc++.h>
#define _MAXN 10000

using namespace std;

int arr[_MAXN + 5];
vector<int> mat;

int main() {
    int n, m, d, a;
    cin >> n >> m >> d;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a;
            mat.push_back(a);
        }
    }

    sort(mat.begin(), mat.end());
    bool flag = true;

    for(int i = 0; i < mat.size(); i++) {
        for(int j = 0; j < mat.size(); j++) {
            if( (abs(mat[i] - mat[j]) % d) == 0 ) {
                arr[i] += (abs(mat[i] - mat[j]) / d);
            } else {
                flag = false;
                break;
            }
        }
    }

    if(!flag) {
        cout << -1 << endl;
    } else {
        cout << *min_element(arr, arr + mat.size()) << endl;
    }

    return 0;
}
