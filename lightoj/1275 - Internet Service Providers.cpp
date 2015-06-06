#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

long long f(long long T, long long N, long long C){
    return (T * C - T * T * N);
}

long long Tmin(long long N, long long C){
    if(N == 0) return 0;
    double temp = (1.0 * C) / (2.0 * N);
    long long ans = ceil(temp), profit = f(ans, N, C);

    while(f(ans - 1, N, C) >= profit) ans--;
    return ans;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int T, N, C;
    cin >> T;

    for(int i = 1; i <= T; i++){
        cin >> N >> C;
        cout << "Case " << i << ": " << Tmin(N, C) << endl;
    }

    return 0;
}
