#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int T, aSize;
    long long b, temp;
    string a;

    cin >> T;

    for(int i = 1; i <= T; i++) {
        cin >> a >> b;
        aSize = a.size();
        temp = 0;
        b = abs(b);

        for(int j = 0; j < aSize; j++) {
            if(a[j] == '-') continue;

            temp *= 10;
            temp += (a[j] - '0');

            if(temp >= b) {
                temp %= b;
            }
        }

        cout << "Case " << i << ": ";
        if(temp == 0) {
            cout << "divisible" << endl;
        } else {
            cout << "not divisible" << endl;
        }
    }

    return 0;

}
