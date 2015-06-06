//UVA 160 - Factors and Factorials.cpp
/* There are 664580 primes till 10^7 */

#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#define size 10000000
#define MAXPRIMES 664580

using namespace std;

bool arr[size + 1];
int prime[MAXPRIMES + 10];
int primePow[MAXPRIMES + 10];
int maxPrime;

void resetPrimePow(){
    for(int i = 0; i <= MAXPRIMES; i++){
        primePow[i] = 0;
    }
}//end of resetPrimePow()

void sieve(){
    int sqofSize = sqrt(size);

    for(int i = 3; i <= sqofSize; i += 2){
        if(arr[i] == false){
            int ii = i * i;
            int i2 = 2 * i;
            for(int j = ii; j <= size; j += i2){
                arr[j] = true;
            }
        }
    }//end of outer for
}//end of sieve()

bool isPrime(int n){
    if(n == 2) return true;

    if(n % 2 == 1 && arr[n] == false)
        return true;

    return false;
}//end of isPrime()

void genPrimes(){
    sieve();
    int j = -1;
    for(int i = 2; i <= size; i++){
        if(isPrime(i)){prime[++j] = i;}
    }//end of for loop
}//end of genPrimes()


void primeFactorize( int n ) {
    //int listSize = 0;   // Initially the List is empty, we denote that size = 0
    int sqrtN = int( sqrt(n) ); // find the sqrt of the number
    for( int i = 0; prime[i] <= sqrtN; i++ ) { // we check up to the sqrt
        if( n % prime[i] == 0 ) { // n is multiple of prime[i]
            // So, we continue dividing n by prime[i] as long as possible
            while( n % prime[i] == 0 ) {
                n /= prime[i]; // we have divided n by prime[i]
                primePow[i] += 1; // added the ith prime in the list
                //listSize++; // added a prime, so, size should be increased
            }
            // we can add some optimization by updating sqrtN here, since n
            // is decreased. think why it's important and how it can be added
        }
    }
    if( n > 1 ) {
        // n is greater than 1, so we are sure that this n is a prime
        //primePow[listSize] = n; // added n (the prime) in the list
        //listSize++; // increased the size of the list
        for(int i = 0; i <= n; i++){
            if(prime[i] == n) {
                //cout << "TEST " << n << endl;
                primePow[i] += 1;
                if(maxPrime != 0){
                    //cout << i << endl;
                    maxPrime = max(i, maxPrime);
                    //flag = true;
                } else {
                    maxPrime = i;
                }
            }
        }
    }
}//end of primeFactorize()

void process(int n){
    if(n == 1){
        primeFactorize(1);
    } else {
        primeFactorize(n);
        process(n - 1);
    }
}

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    genPrimes();

    int N;
    cin >> N;

    while(N != 0){
        //flag = false;
        resetPrimePow();
        maxPrime = 0;
        process(N);
        printf("%3d! =", N);

        for(int i = 0; i <= maxPrime; i++){
            if((i > 0) && (i % 15 == 0)){
                cout << endl;
                cout << "      ";
            }
            printf("%3d", primePow[i]);
        }

        cout << endl;
        cin >> N;
    }

    return 0;
}
