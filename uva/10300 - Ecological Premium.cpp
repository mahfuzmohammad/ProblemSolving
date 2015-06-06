//UVA 10300 - Ecological Premium

#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);
    int t, f, l, a, e;
    int res;

    cin >> t;

    for(int i = 0; i < t; i++){
        res = 0;
        cin >> f;

        for(int j = 0; j < f; j++){
            cin >> l >> a >> e;
            res += (l * e);
        }

        cout << res << endl;

        /*if( i < (t - 1)){
            cout << endl;
        }*/
    }

    return 0;
}
