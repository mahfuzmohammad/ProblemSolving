#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    //freopen("input.txt", "r", stdin);
    string num1, num2, large;
    int carry, rCarry;

    while(true){
        carry = 0;
        rCarry = 0;
        cin >> num1 >> num2;
        if(num1 == "0" && num2 == "0"){
            break;
        }

        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        large = (num1.size() > num2.size())? num1 : num2;

        int length = min(num1.size(), num2.size());
        int largeLen = large.size();

        for(int i = 0; i < length; i++){
            int temp1 = num1[i] - '0';
            int temp2 = num2[i] - '0';
            if(temp1 + temp2 + rCarry >= 10){
                ++carry;
                rCarry = 1;
            } else {
                rCarry = 0;
            }
        }

        for(int i = length; i < largeLen; i++){
            int temp = large[i] - '0';

            if(temp + rCarry >= 10){
                ++carry;
                rCarry = 1;
            } else {
                rCarry = 0;
            }
        }

        if(carry == 0){
            cout << "No carry operation." << endl;
        } else if(carry == 1) {
            cout << "1 carry operation." << endl;
        } else {
            cout << carry << " carry operations." << endl;
        }
    }

    return 0;
}
