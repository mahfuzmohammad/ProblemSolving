#include <bits/stdc++.h>

using namespace std;

int arr[10];

int main() {
    int t, n;
    scanf("%d", &t);

    for(int i = 0; i < t; i++) {
        memset(arr, 0, sizeof arr);
        scanf("%d", &n);
        int tn = n;
        string ans = "";

        for(int j = 9; j > 1; j--) {
            while(n % j == 0) {
                arr[j]++;
                n /= j;
            }
        }

        if(tn == 1) {
            printf("1\n");
        } else {
            int temp = 1;
            for(int j = 2; j <= 9; j++) {
                for(int k = 0; k < arr[j]; k++) {
                    temp *= j;
                    ans += char('0'+j);
                }
            }

            if(temp == tn) {
                cout << ans << "\n";
            } else {
                printf("-1\n");
            }
        }
    }

    return 0;
}
