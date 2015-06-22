#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

#define MAXLEN 26
#define datatype char

using namespace std;

bool taken[MAXLEN + 2];
datatype number[MAXLEN + 2];
datatype x[MAXLEN];

void permute(int& n, int i){
    if(i == n){
        for(int j = 0; j < n; j++)
            cout << x[j] << " ";
        cout << endl;
    } else {
        for(int j = 0; j < n; j++){
            if(!taken[j]){
                taken[j] = true;
                x[i] = number[j];
                permute(n, i + 1);
                taken[j] = false;
            }
        }
    }
}


int main()
{
    int size;
    cin >> size;

    for(int i = 0; i < size; i++){cin >> number[i];}
    permute(size, 0);

    return 0;
}
