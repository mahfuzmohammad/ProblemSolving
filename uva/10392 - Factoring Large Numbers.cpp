#include <bits/stdc++.h>
#define MAX 1000000

using namespace std;

bool arr[MAX + 5];
vector<long long> primes;

void seive()
{
    int sqSize = sqrt(MAX);
    arr[1] = true;

    for(int i = 3; i <= sqSize; i += 2)
    {
        int ii = i * i;
        int i2 = i * 2;

        for(int j = ii; j <= MAX; j += i2)
        {
            arr[j] = true;
        }
    }
}


bool isPrime(int n)
{
    if (n == 2) return true;

    if(n % 2 == 1 && arr[n] == false) return true;

    return false;
}


void primeGen(int a, int b)
{
    seive();
    primes.push_back(2);

    for(int i = a; i <= b; i += 2)
    {
        if(isPrime(i))
        {
            primes.push_back(i);
        }
    }
}

vector<long long> fact;
void factorize(long long n) {
    fact.clear();
    long long sqrtN = sqrt(n);
    int indx = 0;
    while((primes[indx] * primes[indx] <= n) && (indx < primes.size())) {
        while(n % primes[indx] == 0) {
            n /= primes[indx];
            fact.push_back(primes[indx]);
        }

        indx++;
    }

    if(n > 1) fact.push_back(n);
}

int main() {

    primeGen(3, MAX);
    long long n;

    while(scanf("%lld", &n) && (n != -1)) {
        factorize(n);
        for(int i = 0; i < fact.size(); i++) {
            printf("    %lld\n", fact[i]);
        }
        printf("\n");
    }

    return 0;
}
