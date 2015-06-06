//In the name of Allah, most Gracious, most Compassionate

#include <bits/stdc++.h>

using namespace std;

#define _MAXN 100000

int arr[_MAXN + 5];

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    sort(arr, arr + n);

    int maxtaken = 0;
    for(int i = 0; i < n; i++) {
        int lookfor = 2 * arr[i];
        int indx = upper_bound(arr, arr + n, lookfor) - arr;
        maxtaken = max(maxtaken, indx - i);
    }

    printf("%d\n", n - maxtaken);

    return 0;
}
