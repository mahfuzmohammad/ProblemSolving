#include <bits/stdc++.h>

using namespace std;

int arr[15];

int main() {
    int k;
    char a;
    cin >> k;

    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            cin >> a;
            if(a >= '1' && a <= '9') {
                //cout << a - '0' << endl;
                arr[a - '0']++;
            }
        }
    }

    bool f = true;

    /*for(int i = 1; i <= 9; i++) {
        cout << arr[i] << endl;
    }*/

    for(int i = 1; i <= 9; i++) {
        if(arr[i] > (2 * k))
            f = false;
    }

    if(f) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}
