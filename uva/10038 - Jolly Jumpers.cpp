#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <cstdlib>
#define MAXN 3000

using namespace std;

int temp[MAXN + 5];

void reset(){
    for(int i = 1; i <= MAXN; i++){
        temp[i] = 0;
    }
}//end of reset

int main(){
    //freopen("input10038.txt", "r", stdin);
    int n, input1, input2, diff;
    bool flag;

    while(cin >> n){
        reset();
        diff = 0;
        flag = true;

        if(n == 1){
            cin >> input1;
            cout << "Jolly" << endl;
            continue;
        }

        for(int i = 1; i < n; i++){
            if(i == 1){
                cin >> input1 >> input2;
            } else {
                cin >> input2;
            }

            diff = abs(input2 - input1);
            if(diff == 0 || diff >= n){
                flag &= false;
            } else {
                temp[diff] = 1;
                input1 = input2;
            }
        }//end of input

        for(int i = 1; i < n; i++){
            if(temp[i] == 0){
                flag &= false;
            }
        }

        if(flag){
            cout << "Jolly" << endl;
        } else {
            cout << "Not jolly" << endl;
        }
    }

    return 0;
}
