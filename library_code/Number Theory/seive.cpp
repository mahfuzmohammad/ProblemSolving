#include <iostream>
#include <cmath>
#define maxsize 10000000

using namespace std;

bool arr[maxsize + 1];

void sieve(){
    int sqofSize = sqrt(maxsize);
    for(int i = 3; i <= sqofSize; i += 2){
        if(arr[i] == 0){
            int ii = i * i;
            int i2 = 2 * i;
            for(int j = ii; j <= maxsize; j += i2){
                arr[j] = 1;
            }
        }
    }
}

bool isPrime(int n){
    if(n == 2) return true;
    if(n % 2 == 1 && arr[n] == 0)
        return true;
    return false;
}

int main(){
    sieve();

    int j = 0;

    for(int i = 1; i <= 20; i++){
        if(isPrime(i)){
            cout << i << endl;
            j++;
        }
    }

    cout << j << endl;

    return 0;
}

