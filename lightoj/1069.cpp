#include <iostream>
using namespace std;

int main(){
    int liftPos, myPos, ocTime = 3, liftTime = 4, myEntTime = 5, t, total;

    cin >> t;

    for(int i = 1; i <= t; i++){
        cin >> myPos >> liftPos;
        total = ((liftPos - myPos) < 0) ? (liftPos - myPos) * (-1) : (liftPos - myPos);
        total = ((total + myPos) * liftTime) + (ocTime * 3) + (myEntTime * 2);
        cout << "Case " << i << ": " << total << endl;
    }

    return 0;
}
