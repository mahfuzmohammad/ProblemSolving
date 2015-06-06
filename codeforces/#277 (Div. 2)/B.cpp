#include <bits/stdc++.h>

using namespace std;

bool B[105][105], A[105][105],
     coland[105], rowand[105],
     color[105], rowor[105];

int main() {
    ios_base::sync_with_stdio(0);
    int m, n;
    cin >> m >> n;

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> B[i][j];
        }
    }

    for(int i = 0; i < m; i++) {
        bool temp = true;
        for(int j = 0; j < n; j++) {
            temp &= B[i][j];
        }

        rowand[i] = temp;
    }

    for(int j = 0; j < n; j++) {
        bool temp = true;
        for(int i = 0; i < m; i++) {
            temp &= B[i][j];
        }

        coland[j] = temp;
    }

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            A[i][j] = coland[j] & rowand[i];
        }
    }

    for(int i = 0; i < m; i++) {
        bool temp = false;
        for(int j = 0; j < n; j++) {
            temp |= A[i][j];
        }

        rowor[i] = temp;
    }

    for(int j = 0; j < n; j++) {
        bool temp = false;
        for(int i = 0; i < m; i++) {
            temp |= A[i][j];
        }

        color[j] = temp;
    }

    bool ans = true;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            ans &= ((color[j] || rowor[i]) == B[i][j]);
        }

        if(!ans) break;
    }

    if(ans) {
        cout << "YES\n";
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(j > 0) cout << " ";
                cout << A[i][j];
            }
            cout << "\n";
        }
    } else {
        cout << "NO\n";
    }

    return 0;
}
