//UVA 591 - Box of Bricks.cpp

#include <iostream>
#include <cstdio>
#include <algorithm>

#define MAXN 50

using namespace std;

int arr[MAXN + 5];

int main(){
    //freopen("input.txt", "r", stdin);
    int n, move, l, r, need, have, h, set = 0;

    cin >> n;

    while(n != 0){
        move = 0;
        h = 0;

        for(int i = 0; i < n; i++){
            cin >> arr[i];
            h += arr[i];
        }

        sort(arr, arr + n);

        h /= n;
        l = 0;
        r = n - 1;

        while(l <= r){
            need = h - arr[l];
            have = arr[r] - h;

            if( need <= have ){
                arr[l] += need;
                arr[r] -= need;
                move += need;
            } else {
                arr[l] += have;
                arr[r] -= have;
                move += have;
            }

            if(arr[l] == h){
                ++l;
            }

            if(arr[r] == h){
                --r;
            }
        }

        cout << "Set #" << ++set << endl << "The minimum number of moves is " << move << "." << endl << endl;
        cin >> n;
    }

    return 0;
}
