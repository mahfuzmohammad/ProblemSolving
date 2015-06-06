#include <bits/stdc++.h>
#define MAX 10000000

using namespace std;

typedef long long ll;

bool arr[MAX + 5];
vector<ll> primes;

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

map<ll, ll> fact;
void factorize(ll n) {
    fact.clear();
    //cout << n << endl;
    ll sqrtN = sqrt(n);
    int indx = 0;
    while((primes[indx] * primes[indx] <= n) && (indx < primes.size())) {
        while(n % primes[indx] == 0) {
            n /= primes[indx];
            if(fact.find(primes[indx]) != fact.end())
                fact[primes[indx]]++;
            else fact[primes[indx]] = 1;
        }

        indx++;
    }

    if(n > 1)
        if(fact.find(n) != fact.end())
            fact[n]++;
        else fact[n] = 1;
}

template<typename T>
T gcd(T a, T b) { // to handle negative number use a = abs(a)
    if(!b) return a;
    return gcd(b, a%b);
}

int main() {

    primeGen(3, MAX);
    ll n;

    while(scanf("%lld", &n) && (n != 0)) {
        factorize(abs(n));
        map<ll, ll>::iterator it;
        ll old = 1;
        for(it = fact.begin(); it != fact.end(); it++) {
            if(it == fact.begin()) {
                old = it->second;
                continue;
            } else {
                old = gcd(max(it->second, old), min(it->second, old));
            }
        }

        if((n < 0) && (old % 2 == 0)) {
            for(int i = 63; i > 0; i-=2) {
                if(old % i == 0) {
                    cout << i << "\n";
                    break;
                }
            }
        } else
            cout << old << "\n";
    }

    return 0;
}
