#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

long long g(int n, long long k)
{
    if(n == 1) return 1;
    return (((g(n -1, k) + k - 1) % n) + 1);
}

int main()
{
    int T, N;
    long long k;
    cin >> T;

    for(int i = 1; i <= T; i++){
        cin >> N >> k;
        cout << "Case " << i << ": " << g(N, k) << endl;
    }

    return 0;
}
