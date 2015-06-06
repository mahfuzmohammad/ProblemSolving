#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
    int N, ans;

    while(cin >> N){
        ans = 0;
        while(N > 0){
            ans++;
            N /= 2;
        }

        cout << ans << endl;
    }

    return 0;
}
