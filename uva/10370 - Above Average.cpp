//UVA 10370 - Above Average.cpp

#include <iostream>
#include <cstdio>
#include <cmath>

#define MAXN 1000

using namespace std;

int arr[MAXN + 5];

int main()
{
    //freopen("input.txt", "r", stdin);
    int c, n, aAvg;
    double total, avg, res;
    cin >> c;

    for(int i = 0; i < c; i++){
        total = 0;
        aAvg = 0;
        cin >> n;

        for(int j = 0; j < n; j++){
            cin >> arr[j];
            total += arr[j];
        }

        avg = total / n;

        for(int j = 0; j < n; j++){
            if(arr[j] > avg){
                ++aAvg;
            }
        }

        res = ((double(100) / double(n)) * aAvg);
        printf("%.3f%c\n", res, '%');
    }

    return 0;
}
