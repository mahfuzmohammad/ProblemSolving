#include <iostream>


using namespace std;


int main()
{
    long long w, n, m;
    int t, i;

    cin >> t;
    //i = 0;

    for(i = 1; i <= t; i++) {

        cin >> w;
        n = w;

        if(w % 2 != 0) {
            cout << "Case " << i << ": Impossible" << endl;
            continue;
        }

        while( n % 2 == 0) {
            n /= 2;
        }

        if(n % 2 != 0){
            m = w / n;
            cout << "Case " << i << ": " << n << " " << m << endl;
        }


    }

    return 0;
}
