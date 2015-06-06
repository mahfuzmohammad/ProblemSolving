#include <bits/stdc++.h>

using namespace std;

int main() {
    int r1, c1, r2, c2;
    scanf("%d %d %d %d", &r1, &c1, &r2, &c2);

    int rook = !(r1 == r2) + !(c1 == c2);
    int king = max(abs(r1 - r2), abs(c1 - c2));

    int bis = 0;

    if( (abs(r1 - r2) + abs(c1 - c2)) == 0 || (abs(r1 - r2) + abs(c1 - c2)) % 2 == 0 ) {
        if (abs(r1 - r2) == abs(c1 - c2)) {
            bis = 1;
        } else bis = 2;
    }

    cout << rook << " " << bis << " " << king << endl;

    return 0;
}
