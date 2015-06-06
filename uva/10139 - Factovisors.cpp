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

map<int, long long> fact;
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

long long powerinfact(long long n, long long p) {
    long long power = p;
    long long cnt = 0;
    while(power <= n) {
        cnt += (n/power);
        power *= p;
    }

    return cnt;
}

int main() {
    //cout << powerinfact(2147483647, 2) << endl;
    primeGen(3, MAX);
    int n, m;

    while(scanf("%d %d", &n, &m) != EOF) {
        factorize(m);
        bool flag = true;
        map<int, long long>::iterator it;
        for(it = fact.begin(); it != fact.end(); it++) {
            //cout << it->first << " " << it->second << "\n";
            flag &= (powerinfact(n, it->first) >= it->second);
        }

        if(flag && m != 0) {
            printf("%d divides %d!\n", m, n);
        } else {
            printf("%d does not divide %d!\n", m, n);
        }
    }

    return 0;
}
