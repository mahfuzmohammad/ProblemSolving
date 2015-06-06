#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

vector<double> v;
double dp[105];

void reset()
{
    for(int i = 0; i <= 100; i++)
        dp[i] = -1;
}

double E(int i, int n)
{
    if(i == n) return v[i];

    if(dp[i] != -1) {return dp[i];}
    dp[i] = v[i];


    double temp = 0;
    for(int j = i + 1; j <= min(n, i + 6); j++) {
        temp += E(j, n);
    }

    dp[i] += ( temp / double(min(n - i, 6)) );

    return dp[i];
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int T, n;
    double x;
    cin >> T;

    for(int i = 1; i <= T; i++) {
        cin >> n;
        v.clear();
        for(int j = 0; j < n; j++) {
            cin >> x;
            v.push_back(x);
        }

        reset();

        printf("Case %d: %0.7lf\n", i, E(0, n - 1));
    }

    return 0;
}
