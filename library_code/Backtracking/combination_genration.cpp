#include <iostream>
#include <cstdio>
#include <algorithm>

#define MAXLEN 10
#define datatype char

using namespace std;

bool taken[MAXLEN + 2];
datatype data[MAXLEN + 2];
datatype gendata[MAXLEN + 2];

void combination(int& n, int i, int& len){
    if(i == len){
        for(int j = 0; j < len; j++)
            cout << gendata[j] << " ";
        cout << endl;
    } else {
        for(int j = 0; j < n; j++){
            if(!taken[j]){
                taken[j] = true;
                gendata[i] = data[j];
                combination(n, i + 1, len);
                taken[j] = false;
            }
        }
    }
}


int main(){
    int size, len;
    cin >> size >> len;
    for(int i = 0; i < size; i++) cin >> data[i];

    while(len != 0){
        combination(size, 0, len);
        cin >> len;
    }

    return 0;
}
