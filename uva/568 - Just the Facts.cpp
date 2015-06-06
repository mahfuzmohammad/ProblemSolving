#include <bits/stdc++.h>

using namespace std;

long long arr[10005];

int main() {
    /*freopen("test.txt", "w", stdout);*/
    arr[1] = 1;
    for(int i = 2; i <= 10000; i++) {
        long long temp = arr[i-1]*(long long)i;
        while(temp % 10L == 0) temp /= 10L;
        arr[i] = temp % 1000000000000L;
    }

    /*long long test = 1;
    for(int i = 2; i <= 3125; i++) {
        test *= (long long)i;
        while(test % 10L == 0) test /= 10L;
        test %= 1000000000000L;
    }

    cout << test << endl;*/

    int n;
    while(scanf("%d", &n) != EOF) {
        printf("%5d -> %d\n", n, arr[n]%10);
    }

    return 0;
}
