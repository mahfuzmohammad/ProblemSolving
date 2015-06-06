#include <bits/stdc++.h>

#define MAX 1000000

using namespace std;

typedef long long ll;

template<typename T>
T bigmod(T a, T p, T mod) { // calculates (a^p % mod) in log p
    if(p == 0) return 1;
    ll ret = bigmod(a, p/2);
    ret *= ret;
    if(p % 2 == 1) ret *= (ll)a;
    return ret % mod;
}

template<typename T>
T power(T a, T p) { // calculates (a^p) in log p
    if(p == 0) return 1;
    ll ret = power(a, p/2);
    ret *= ret;
    if(p % 2 == 1) ret *= (ll)a;
    return ret;
}

template<typename T>
T gcd(T a, T b) { // to handle negative number use a = abs(a)
    if(!b) return a;
    return gcd(b, a%b);
}

template<typename T>
T lcm(T a, T b) { // to handle negative number use a = abs(a)
    return (a / gcd(a, b)) * b;
}

bool arr[MAX + 5];
vector<int> primes;

void seive() {
    int sqSize = sqrt(MAX);
    arr[1] = true;

    for(int i = 3; i <= sqSize; i += 2) {
        int ii = i * i, i2 = i * 2;
        for(int j = ii; j <= MAX; j += i2) {
            arr[j] = true;
        }
    }
}

bool isPrime(int n) {
    if (n == 2) return true;
    if(n % 2 == 1 && arr[n] == false) return true;
    return false;
}

void primeGen(int a, int b) { // Generates all prime numbers in [a, b]
    seive();
    primes.push_back(2);

    for(int i = a; i <= b; i += 2) {
        if(isPrime(i))
            primes.push_back(i);
    }
}

map<int, ll> fact; // contains prime factorized number
void factorize(int n) {
    fact.clear();
    int indx = 0;
    while((primes[indx] * primes[indx] <= n) && (indx < primes.size())) {
        while(n % primes[indx] == 0) {
            n /= primes[indx];
            fact[primes[indx]]++;
        }

        indx++;
    }

    if(n > 1) fact[n]++;
}

ll num_of_div(int n) {
    factorize(n);
    ll ret = 1;
    map<int, ll>::iterator it;
    for(it = fact.begin(); it != fact.end(); it++) {
        ret *= (it->second+1);
    }

    return ret;
}

ll sum_of_div() {
    ll t = 1, b = 1;
    map<int, ll>::iterator it;

    for(it = fact.begin(); it != fact.end(); it++) {
        t *= (power((ll)it->first, it->second+1) - 1);
        b *= (it->first - 1);
        ll g = gcd(max(t, b), min(t, b));
        t /= g, b /= g;
    }

    return t;
}

template <typename T>
T powerinfact(T n, T p) { // returns the highest power of p in n!
    T power = p, cnt = 0;
    while(power <= n) {
        cnt += (n/power);
        power *= p;
    }

    return cnt;
}

int main() {
    primeGen(3, MAX);
    int l, u, t;

    cin >> t;

    for(int i = 0; i < t; i++) {
        cin >> l >> u;
        int maxDiv = 0, num = 0;
        for(int j = l; j <= u; j++) {
            int divNum = num_of_div(j);
            if(divNum > maxDiv) {
                maxDiv = divNum;
                num = j;
            }
        }

        cout << "Between " << l << " and " << u << ", " << num << " has a maximum of " << maxDiv << " divisors.\n";
    }

    return 0;
}
