#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <sstream>
#include <algorithm>

#define maxsize 1000000
#define maxrange 1000000

using namespace std;

int arr[maxsize + 1];
vector<int> digitPrimes;

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

int digitSum(int i) {
    stringstream ss;
    ss << i;
    string num = ss.str();
    int nsize = num.size(), sum = 0;

    for(int i = 0; i < nsize; i++) {
        sum += (num[i] - '0');
    }

    return sum;
}

void genDigitPrimes() {
    sieve();
    int temp;

    for(int i = 2; i <= maxrange; i++) {
        temp = digitSum(i);
        if(isPrime(temp) && isPrime(i))
            digitPrimes.push_back(i);
    }
}

int main(){
    genDigitPrimes();

    /*for(int i = 0; i <= 20; i++) {
        cout << digitPrimes[i] << endl;
    }*/

    int N, t1, t2, s, e;

    scanf("%d", &N);

    for(int i = 0; i < N; i++) {
        scanf("%d %d", &t1, &t2);
        s = lower_bound(digitPrimes.begin(), digitPrimes.end(), t1) - digitPrimes.begin();
        e = upper_bound(digitPrimes.begin(), digitPrimes.end(), t2) - digitPrimes.begin();

        printf("%d\n", e - s);
    }

    return 0;
}

