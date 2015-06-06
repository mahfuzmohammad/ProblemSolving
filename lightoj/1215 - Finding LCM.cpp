#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>

#define size 1000000
#define MAXPRIMES 664580

using namespace std;

int arr[size + 1];
int prime[MAXPRIMES + 10];

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

long long gcd(long long a, long long b){
    if(!b) return a;
    return gcd(b, a % b);
}

long long lcm(long long a, long long b){
    return ((a / gcd(a, b)) * b);
}

long long pow(long long a, long long b){
    if(b == 0) return 1;
    int x = pow(a, b / 2);
    x = (x * x);
    if(b % 2 == 1) x *= a;
    return x;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    genPrimes();
    int       T, p;
    long long a, b, L, L1, ans, lc, l1c;

    cin >> T;

    for(int i = 1; i <= T; i++){
        cin >> a >> b >> L;
        p = 0;
        ans = 1;
        L1 = lcm(a, b);

        if(L % L1 != 0){
            cout << "Case " << i << ": impossible" << endl;
        } else {
            while(L1 != 1 || L != 1){
                lc = 0; l1c = 0;

                while(L % prime[p] == 0 && L != 0){
                    lc++;
                    L /= prime[p];
                }

                while(L1 % prime[p] == 0 && L1 != 0){
                    l1c++;
                    L1 /= prime[p];
                }

                if(lc > l1c){
                    ans *= pow(prime[p], lc);
                }

                p++;
            }

            cout << "Case " << i << ": " << ans << endl;
        }
    }

    return 0;
}
