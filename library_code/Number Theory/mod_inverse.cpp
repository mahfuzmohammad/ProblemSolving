//Modular Multiplicative Inverse
//Little Fermates Algorithm
//Complexity: O(log m) , where
//m is the MODP

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>

#define MODP  1000003
#define MAXN 1000000

using namespace std;

long long fact[MAXN + 2];
long long factmod[MAXN + 2];

/* This function calculates (a^b)%MOD */
long long pow(int a, int b, int MOD) {
long long x = 1, y = a;
	while(b > 0) {
		if(b%2 == 1) {
			x= ((x % MOD) * (y % MOD)) % MOD;
		}

		y = ((y % MOD) * (y % MOD)) % MOD;
		b /= 2;
	}
	return x;
}

int modInverse(int a, int m) {
    return pow(a,m-2,m);
}

void gen(){
    fact[0] = 1;
    factmod[0] = modInverse(1, MODP);
    for(int i = 1; i <= MAXN; i++){
        fact[i] = (i * fact[i - 1]) % MODP;
        factmod[i] = modInverse(fact[i], MODP);
    }
}

int main()
{

    return 0;
}
