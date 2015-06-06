//UVA 10696 - f91

#include <iostream>
#include <cstdio>

using namespace std;

int f91(int N){
    /*if(N >= 101){
        return N - 10;
    }

    return f91(f91(N + 11));*/

    if( N > 101){
        return N - 10;
    }

    return 91;
}

int main(){
    int N;

    cin >> N;

    while(N != 0){
        cout << "f91(" << N << ") = " << f91(N) << endl;
        cin >> N;
    }

    return 0;
}
