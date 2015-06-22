/* There are 664580 primes till 10^7 */

#include <iostream>
#include <cmath>
#include <vector>
#define MAXSIZE 10000000
#define MAXPRIMES 664580

using namespace std;

int arr[MAXSIZE + 1];
int prime[MAXPRIMES + 10];
int primePow[MAXPRIMES + 10];

void sieve(){
    int sqofSize = sqrt(MAXSIZE);

    for(int i = 3; i <= sqofSize; i += 2){

        if(arr[i] == 0){
            int ii = i * i;
            int i2 = 2 * i;
            for(int j = ii; j <= MAXSIZE; j += i2){
                arr[j] = 1;
            }
        }
    }//end of outer for
}//end of sieve()

bool isPrime(int n){
    if(n == 2) return true;

    if(n % 2 == 1 && arr[n] == 0)
        return true;

    return false;
}//end of isPrime()

void genPrimes(){
    sieve();
    int j = -1;
    for(int i = 2; i <= MAXSIZE; i++){
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
            if(prime[i] == n) primePow[i] += 1;
        }
    }
}//end of primeFactorize()

int main(){
    genPrimes();
    primeFactorize(100);

    for(int i = 0; i <= 100; i++){
        if(primePow[i] != 0)
            cout << i << " " << primePow[i] << endl;
    }

    //cout << j << endl;

    return 0;
}

