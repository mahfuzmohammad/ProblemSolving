#include <iostream>


using namespace std;


int gcd(int a, int b)
{
    if(b == 0) return a;

    return gcd(b, a % b);
}


int lcm(int a, int b)
{
    return ( (a / gcd(a, b)) * b );
}


int main()
{
    int t, n, a, b, res;

    cin >> t;

    for(int i = 1; i <= t; i++)
    {

        cin >> n >> a;


        for(int j = 1; j < n; j++)
        {
            cin >> b;
            res = lcm(a, b);
            a = res;
        }

        cout << "Case " << i << ": " << res << endl;
    }

    return 0;
}
