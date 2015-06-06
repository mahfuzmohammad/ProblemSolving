#include <bits/stdc++.h>

using namespace std;

int arr[105], change[105];

int main() {

    int n, k, ans = 0;
    cin >> n >> k;

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int one, two;
    for(int i = 0; i < k; i++) {
        one = 0, two = 0;
        for(int j = 0; i + j * k < n; j++) {
            if(arr[i + j * k] == 1) one++;
            else two++;

            //cout << i + j * k << " " << arr[i + j * k] << endl;
        }

        change[i] = min(one, two);
        //cout << "t " << one << " " << two << endl;
    }

    cout << accumulate(change, change + k, ans) << endl;

    return 0;
}
