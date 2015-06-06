#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
    int T;
    double AB, AC, BC, AD, ratio;

    cin >> T;

    for(int i = 1; i <= T; i++) {
        cin >> AB >> AC >> BC >> ratio;

        AD = AB * sqrt(ratio / (ratio + 1));

        //cout << "Case " << i << ": " << AD << endl;
        printf("Case %d: %.7lf\n", i, AD);
    }

    return 0;
}
