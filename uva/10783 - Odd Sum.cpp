//UVA 10783 - Odd Sum.cpp

#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);
    int T, a, b, res;

    cin >> T;

    for(int i = 1; i <= T; i++){
        cin >> a >> b;
        if(a % 2 == 0){
            a += 1;
        }

        if(b % 2 == 0){
            b -= 1;
        }

        res = ((a + b) * (b - a + 2)) / 4;
        cout << "Case " << i << ": " << res << endl;
    }

    return 0;
}
