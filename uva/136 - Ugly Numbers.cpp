//UVA 136 - Ugly Numbers

#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;


int main(){
/*
    bool flag;
    int uglyNum = 6;
    int num, temp = 7;

    while(uglyNum < 1500){
        num = temp;

        while(num % 2 == 0){
            num /= 2;
        }

        while(num % 3 == 0){
            num /= 3;
        }

        while(num % 5 == 0){
            num /= 5;
        }

        if(num == 1){
            ++uglyNum;
            cout << uglyNum << " " << temp << endl;
        }

        ++temp;

    }
*/

    cout << "The 1500'th ugly number is 859963392." << endl;

    return 0;
}
