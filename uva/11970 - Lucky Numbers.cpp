#include <bits/stdc++.h>

using namespace std;

int main() {
    int t, n;

    scanf("%d", &t);

    for(int i = 1; i <= t; i++) {
        scanf("%d", &n);

        int m = sqrt(n - 1);
        printf("Case %d:", i);
        //cout << m << endl;
        for(int j = m; j >= 1; j--) {
            int j2 = j * j;
            int X = n - j2;
            //cout << X << " " << j2 << endl;
            if(X % j == 0) {
                printf(" %d", X);
            }
        }

        printf("\n");
    }

    return 0;
}
