#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>

#define maxn  1000000
#define range 100000000

using namespace std;

double arr[maxn + 2];

void preGen()
{
    double ans = 0.0;
    int idx = 0;

    for(int i = 1; i <= range; i += 100){
        //cout << i << endl;
        for(int j = i; j < i + 100; j++){
            ans += (double(1) / double(j));
        }

        arr[++idx] = ans;
    }
}

double calc(int n){
    double ans = arr[n / 100];
    int from = ((n / 100) * 100) + 1;
    for(int i = from; i <= n; i++){
        ans += (double(1) / double(i));
    }

    return ans;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    preGen();
    int T, n;
    cin >> T;

    for(int i = 1; i <= T; i++){
        cin >> n;
        cout << "Case " << i << ": ";
        printf("%0.9lf\n", calc(n));
    }

    return 0;
}
