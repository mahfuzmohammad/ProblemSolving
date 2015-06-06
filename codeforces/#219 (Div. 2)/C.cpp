#include <bits/stdc++.h>

using namespace std;

#define _MAXN 500000

int arr[_MAXN + 5];
bool vis[_MAXN + 5];
int n;
stack<int> st;

bool cmp (int a, int b) {
    return a > b;
}

int main() {
    //freopen("in.txt", "r", stdin);
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    sort(arr, arr + n, cmp);

    int l, r, ans = 0, temp = 0, nota = 0;
    l = 0, r = n / 2;

    while(l < n && r < n) {

        for(; l < r; l++) {
            if((arr[l] >= arr[r] * 2)) {
                if(!vis[l]) st.push(l);
            } else {
                break;
            }
        }

        if(!st.empty() && (arr[st.top()] >= arr[r] * 2)) {
            ans++;
            st.pop();
            vis[r] = true;
        }

        r++;
    }

    printf("%d\n", n - ans);

    return 0;
}
