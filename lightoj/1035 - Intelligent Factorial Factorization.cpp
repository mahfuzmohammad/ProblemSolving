#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>

#define size 100
#define MAXPRIMES 100

using namespace std;

int arr[size + 3];
int prime[MAXPRIMES + 3];
int primePow[MAXPRIMES + 3];
int val[103][103];

void sieve(){
    int sqofSize = sqrt(size);

    for(int i = 3; i <= sqofSize; i += 2){

        if(arr[i] == 0){
            int ii = i * i;
            int i2 = 2 * i;
            for(int j = ii; j <= size; j += i2){
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
            if(prime[i] == n) primePow[i] += 1;
        }
    }
}//end of primeFactorize()

void genValue()
{
    genPrimes();
    for(int i = 2; i <= 100; i++){
        primeFactorize(i);
        for(int j = 0; j <= 100; j++){
            val[i][j] = val[i - 1][j] + primePow[j];
            primePow[j] = 0;
        }
    }
}

int main()
{
    genValue();
    int T, N;
    cin >> T;

    for(int i = 1; i <= T; i++){
        cin >> N;
        cout << "Case " << i << ": " << N << " = 2 (" << val[N][0] << ")";
        for(int j = 1; j <= 100; j++){
            if(val[N][j] != 0){
                cout << " * " << prime[j] << " (" << val[N][j] << ")";
            }
        }

        cout << endl;
    }

    return 0;
}
