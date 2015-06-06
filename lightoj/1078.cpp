#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);
    int T;
    long long n, digit, temp, result;

    cin >> T;

    for(int i = 1; i <= T; i++){
        cin >> n >> digit;
        temp = digit;
        result = 1;

        int digitsN = log10(n) + 1;
        int digitsD = log10(digit) + 1;

        if(digit < n && digitsD < digitsN ){
            result = digitsN;
            for(int j = 0; j < digitsN - 1; j++){
                temp = (temp * 10) + digit;
            }
            //cout << result << " " << temp << endl;
        }

        if(digit < n && digitsD == digitsN){
            result = 2;
            temp = (digit * 10) + digit;
        }

        temp = temp % n;

        while(temp != 0){
            temp = (temp * 10) + digit;
            result += 1;
            temp = temp % n;
        }

        cout << "Case " << i << ": " << result << endl;
    }

    return 0;
}
