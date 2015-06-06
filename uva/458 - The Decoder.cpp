#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>

using namespace std;

int main()
{
    string input;
    int inputsize;

    while(cin >> input){
        inputsize = input.size();

        for(int i = 0; i < inputsize; i++){
            cout << char(input[i] - 7);
        }

        cout << endl;
    }

    return 0;
}
