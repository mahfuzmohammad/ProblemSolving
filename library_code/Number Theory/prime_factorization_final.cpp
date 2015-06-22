#include <bits/stdc++.h>

using namespace std;

#define _MAXN 1000000

bool temp[_MAXN + 5]; // is used for prime generation
vector<int> prime;
vector<int> primeFactor[_MAXN + 5];

void sieve() {
    int sq = sqrt(_MAXN);
    for(int i = 3; i <= sq; i += 2) {
        if(!temp[i]) {
            int ii = i * i;
            int i2 = 2 * i;
            for(int j = ii; j <= _MAXN; j += i2){
                temp[j] = 1;
            }
        }
    }
} // end of sieve()

bool isPrime(int n){
    if(n == 2) return true;
    if(n % 2 == 1 && !temp[n])
        return true;
    return false;
}//end of isPrime()

void genPrimes(){
    sieve();
    prime.push_back(2);
    for(int i = 3; i <= _MAXN; i+=2){
        if(isPrime(i)) prime.push_back(i);
    }//end of for loop
}//end of genPrimes()

void primeFactorize(int n) { // calculates only primes not powers
    int sq = sqrt(n);
    int tempN = n;
    for(int i = 0; prime[i] <= sq; i++) {
        if(tempN % prime[i] == 0) {
            primeFactor[n].push_back(prime[i]);
            while (tempN % prime[i] == 0) {
                tempN /= prime[i];
            }
        }
    }

    if(tempN > 1) {
        primeFactor[n].push_back(tempN);
    }
}

int main() {
    genPrimes();
    primeFactorize(100);
    for(int i = 0; i < primeFactor[100].size(); i++) {
        cout << primeFactor[100][i] << " ";
    }
    cout << endl;
    return 0;
}
