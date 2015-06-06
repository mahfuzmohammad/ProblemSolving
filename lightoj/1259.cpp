#include <iostream>
#include <cmath>
#include <vector>
#define MAX 10000000

using namespace std;

bool arr[MAX + 5];
vector<int> primes;

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


int main()
{
    primeGen(3, MAX);

    int t, n, a, b, res, j;

    cin >> t;

    for(int i = 1; i <= t; i++)
    {
        cin >> n;
        res = 0;
        j = 0;

        a = primes[j];
        b = n - a;

        while(a <= b) {
            if(isPrime(b)){
                ++res;
            }

            ++j;

            a = primes[j];
            b = n - a;
        }

        cout << "Case " << i << ": " << res << endl;
    }

    return 0;
}
