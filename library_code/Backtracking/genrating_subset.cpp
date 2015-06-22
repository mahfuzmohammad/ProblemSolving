#include <iostream>
#include <cstdio>
#include <algorithm>

#define MAXLEN 10
#define datatype char

using namespace std;

bool taken[MAXLEN + 2];
datatype data[MAXLEN + 2];
datatype gendata[MAXLEN + 2];

void combination(int& n, int i, int& len, int lasttaken){
    if(i == len){
        for(int j = 0; j < len; j++)
            cout << gendata[j] << " ";
        cout << endl;
    } else {
        for(int j = lasttaken; j < n; j++){
            if(!taken[j]){
                taken[j] = true;
                gendata[i] = data[j];
                combination(n, i + 1, len, j + 1);
                taken[j] = false;
            }
        }
    }
}


int main(){
    int size;
    cin >> size;
    for(int i = 0; i < size; i++) cin >> data[i];

    for(int i = 1; i <= size; i++){combination(size, 0, i, 0);}

    return 0;
}
