#include <iostream>
using namespace std;

int main(){
    int side1, side2, side3, t;
    cin >> t;

    for(int i = 1; i <= t; i++){
        cin >> side1 >> side2 >> side3;

        if(((side1 * side1) + (side2 * side2) == (side3 * side3)) || ((side3 * side3) + (side2 * side2) == (side1 * side1)) || ((side1 * side1) + (side3 * side3) == (side2 * side2))){
            cout << "Case " << i << ": yes" << endl;
        }else{
            cout << "Case " << i << ": no" << endl;
        }
    }

    return 0;
}
