#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    freopen("strinput.txt", "r", stdin);
    string str, input, pattern;
    pattern = "it";
    int inputSize, patSize, j;

    while(getline(cin, input)){
        cout << input << endl;
        inputSize = input.size();
        patSize = pattern.size();

        for(int i = 0; i < (inputSize - patSize); i++){
            if(input[i] == pattern[0]){
                j = 0;
                while(j < patSize){
                    if(input[i + j] == pattern[j]){
                        ++j;
                    } else {
                        break;
                    }
                }// end of while

                if(j == patSize){
                    cout << i << " ";
                }
            }
        }// end of for
        cout << endl;
    }//end of while

    return 0;
}
