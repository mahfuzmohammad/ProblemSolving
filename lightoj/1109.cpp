#include <iostream>
using namespace std;

int main(){
    int dataArr[1000], sortedData[1000], large, divisor, si, t, input;

    for(int i = 1; i <= 1000; i++){
        divisor = 0;

        for(int j = 1; j <= i; j++){

            if(i % j == 0){
                divisor++;
            }

        }
        dataArr[i - 1] = divisor;
    }

    large = dataArr[0];

    for(int j = 1; j < 1000; j++){

        if(dataArr[j] > large){
            large = dataArr[j];
        }

    }

    si = -1;

    for(int k = 1; k <= large; k++){
        for(int l = 999; l >= 0; l--){

            if(dataArr[l] == k){
                sortedData[++si] = l + 1;
            }

        }
    }

    cin >> t;

    for(int m = 1; m <= t; m++){
        cin >> input;
        cout << "Case " << m << ": " << sortedData[input - 1] << endl;
    }


}
