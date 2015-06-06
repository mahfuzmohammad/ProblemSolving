#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll arr[100005], cum[100005];

int main() {

    int n, k;
    scanf("%d %d", &n, &k);

    for (int i = 0; i < n; i++) {
        scanf("%I64d", &arr[i]);
    }

    sort(arr, arr + n);
    ll kneed = 0;
    pair<int, int> ans(0, 0);

    cum[0] = arr[0];
    for (int i = 1; i < n; i++) {cum[i] = arr[i] + cum[i - 1];}

    for (int i = 0, j = 0; i < n && j < n; ) {
        if (kneed > k) {
            kneed -= (arr[j] - arr[i]);
            i++;
        } else {
            if (ans.first < (j - i + 1)) {
                ans.first = j - i + 1, ans.second = arr[j];
            }

            j++;
            kneed = (arr[j] * (j - i + 1)) - (cum[j] - ((i == 0)?0:cum[i - 1]));
        }
    }

    printf("%d %d\n", ans.first, ans.second);

    return 0;
}
