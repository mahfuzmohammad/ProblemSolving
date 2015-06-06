#include <bits/stdc++.h>

using namespace std;

int arr[5];

int main() {

    int t;
    scanf("%d", &t);

    for(int i = 1; i <= t; i++) {
        memset(arr, 0, sizeof arr);
        for(int j = 0; j < 3; j++) {
            scanf("%d", &arr[j]);
        }

        sort(arr, arr+3);
        printf("Case %d: %d\n", i, arr[1]);
    }

    return 0;
}
