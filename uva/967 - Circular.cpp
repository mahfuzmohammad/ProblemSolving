#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <sstream>
#include <algorithm>

#define maxsize 1000000
#define maxprime 79000

using namespace std;

int arr[maxsize + 1];
vector<int> primes;
int circularPrimeNo[maxprime];

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

void genPrimes() {
    sieve();

    for(int i = 101; i < maxsize; i+= 2) {
        if(isPrime(i))
            primes.push_back(i);
    }
}

bool isCirculare(int n) {
    stringstream ss;
    ss << n;
    string num = ss.str(), tempn;
    int nsize = num.size();
    tempn = num;

    do {
        tempn = tempn.substr(1, nsize - 1) + tempn[0];
        if(!isPrime(atoi(tempn.c_str()))) {
            return false;
        }
    } while (tempn != num);

    return true;
}

void genCircularPrimes() {
    genPrimes();
    int primesSize = primes.size();

    if(isCirculare(primes[0])) circularPrimeNo[0] = 1;

    for(int i = 1; i < primesSize; i++) {
        if(isCirculare(primes[i])) {
            circularPrimeNo[i] = 1 + circularPrimeNo[i - 1];
        } else {
            circularPrimeNo[i] = circularPrimeNo[i - 1];
        }
    }
}


int main(){
    genCircularPrimes();
    int i, j, s, e, ans;

    cin >> i;

    while(i != -1) {
        cin >> j;
        s = lower_bound(primes.begin(), primes.end(), i) - primes.begin();
        e = upper_bound(primes.begin(), primes.end(), j) - primes.begin();

        ans = circularPrimeNo[e - 1] - circularPrimeNo[s - 1];

        if(ans == 0) {
            cout << "No Circular Primes." << endl;
        } else if (ans == 1) {
            cout << "1 Circular Prime." << endl;
        } else {
            cout << ans << " Circular Primes." << endl;
        }

        cin >> i;
    }

    return 0;
}
