#include <bits/stdc++.h>

using namespace std;

int arr[10];

int main() {
    int x;
    bool legfound = false;
    for(int i = 0; i < 6; i++) {
        cin >> x;
        arr[x]++;
    }

    // find legs
    for(int i = 1; i < 10; i++) {
        if(arr[i] >= 4) {
            arr[i] -= 4;
            legfound = true;
            break;
        }
    }

    if(!legfound) {
        cout << "Alien\n";
    } else {
        bool ele = false;
        for(int i = 1; i < 10; i++) {
            if(arr[i] == 2) {
                cout << "Elephant\n";
                ele = true;
                break;
            }
        }

        if(!ele) cout << "Bear\n";
    }

    return 0;
}
