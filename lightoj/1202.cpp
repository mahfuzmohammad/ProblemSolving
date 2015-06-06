#include <iostream>
#include <stdlib.h>
using namespace std;

int main(){
    long long r1, r2, c1, c2;
    int t;

    cin >> t;

    for(int i = 1; i <= t; i++){
        cin >> r1 >> c1 >> r2 >> c2;

        if ((((r2 - r1) % 2 == 0) && ((c2 - c1) % 2 == 0)) || (((r2 - r1) % 2 != 0) && ((c2 - c1) % 2 != 0))){

            if(abs((r2 - r1)) == abs((c2 - c1))){
                cout << "Case " << i << ": 1" << endl;
            } else {
                cout << "Case " << i << ": 2" << endl;
            }

        } else {
            cout << "Case " << i << ": impossible" << endl;
        }

    }

    return 0;
}
