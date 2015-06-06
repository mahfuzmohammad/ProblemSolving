#include <bits/stdc++.h>

using namespace std;

int t, n, x;
int arr[1000009];

int main() {
    //freopen("in.txt", "r", stdin);
    scanf("%d", &t);

    for(int i = 1; i <= t; i++) {
        memset(arr, 0, sizeof arr);
        scanf("%d", &n);
        for(int j = 0; j < n; j++) {
            scanf("%d", &x);
            arr[x]++;
        }

        bool flag = true;

        for(int j = 0; j < n; j++) {
            if(arr[j] > 0) {
                arr[j]--;
            } else if(arr[n - j - 1] > 0) {
                arr[n - j - 1]--;
            } else {
                flag = false;
                break;
            }
        }

        if(flag) {
            printf("Case %d: yes\n", i);
        } else {
            printf("Case %d: no\n", i);
        }
    }

    return 0;
}
