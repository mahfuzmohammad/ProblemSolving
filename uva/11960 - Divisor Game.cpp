/* There are 664580 primes till 10^7 */

#include <bits/stdc++.h>

#define MAXSIZE 1000000
#define MAXPRIMES 1000
#define MAXN 1000000

using namespace std;

int arr[MAXSIZE + 1];
int prime[MAXPRIMES + 10];
int cntdiv[MAXN + 5];
int primesize;

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
    primesize = j;
}//end of genPrimes()


int primeFactorize( int n ) {
    int cnt = 1, tc = 0;

    for(int i = 0; prime[i] * prime[i] <= n && i < primesize; i++) {
        tc = 0;
        while(n % prime[i] == 0) {
            n /= prime[i];
            tc++;
        }

        cnt *= (tc + 1);
    }

    if(n > 1) cnt *= 2;
    return cnt;
}//end of primeFactorize()

int main(){
    genPrimes();

    cntdiv[1] = 1;
    int mx = 1, num = 1;
    for(int i = 2; i <= MAXSIZE; i++) {
        int temp = primeFactorize(i);

        /*if(i <= 20) {
            cout << i << " " << temp << endl;
        }*/

        if(mx <= temp) {
            mx = temp;
            num = i;
        }

        cntdiv[i] = num;
    }

    int t, x;
    scanf("%d", &t);

    for(int i = 0; i < t; i++) {
        scanf("%d", &x);
        printf("%d\n", cntdiv[x]);
    }

    return 0;
}

