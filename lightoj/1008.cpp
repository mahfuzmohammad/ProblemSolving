#include <iostream>
#include <cmath>
using namespace std;

long long currentNum(long long x){
    long long sqroot = sqrt(x);

    if( pow(sqroot, 2) < x ){
        return sqroot + 1;
    }

    return sqroot;
}

long long chkNum(long long crrNum){
    return (crrNum * crrNum) - crrNum + 1;
}

int main(){
    long long num, r, c, cNum, chk, diff;
    int t;

    cin >> t;

    for(int k = 1; k <= t; k++){

    cin >> num;

    cNum = currentNum(num);
    r = cNum;
    c = cNum;
    chk = chkNum(cNum);
    diff = chk - num;

    if((cNum % 2) == 0){

        if(diff < 0){
            r += diff;
        } else {
            c -= diff;
        }

    } else {

        if(diff < 0){
            c += diff;
        } else {
            r -= diff;
        }

    }


    cout << "Case " << k << ": " << c << " " << r << endl;

    }

    return 0;
}
