//UVA 272 - TeX Quotes

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);
    string input, pattern;
    bool flag = true;
    pattern = "\"";
    int inputSize, patSize, j;

    while(getline(cin, input)){
        inputSize = input.size();
        patSize = pattern.size();

        for(int i = 0; i < inputSize; i++){
            if(input[i] == pattern[0]){
                if(flag){
                    cout << "``";
                    flag = false;
                } else {
                    cout << "''";
                    flag = true;
                }
            } else {
                cout << input[i];
            }
        }// end of for
        cout << endl;
    }//end of while

    return 0;
}

