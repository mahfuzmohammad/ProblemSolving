#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int a, int b)
{
    if(b == 0) return a;
    return gcd(b, a % b);
}

int main()
{
    int T, x, n, num, denum;

    cin >> T;

    for(int i = 1; i <= T; i++) {
        cin >> n;
        num = 0; denum = n;
        for(int j = 0; j < n; j++) {
            cin >> x;
            if(x >= 0) {
                num += x;
            } else {
                denum--;
                num += abs(x);
            }
        }

        cout << "Case " << i << ": ";
        if(denum <= 0)
            cout << "inf" << endl;
        else {
            int temp = gcd(num, denum);
            num /= temp; denum /= temp;
            cout << num << "/" << denum << endl;
        }
    }

    return 0;
}
