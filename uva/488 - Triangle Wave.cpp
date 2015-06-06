//UVA 488 - Triangle Wave.cpp

#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);
    int t, ampl, freq, height, wide;
    bool flag = false;

    cin >> t;

    for(int c = 0; c < t; c++){
        cin >> ampl >> freq;

        for(int i = 0; i < freq; i++){
            height = 2*ampl - 1;
            wide = 1;
            for(int j = 0; j < height; j++){
                for(int k = 0; k < wide; k++){
                    cout << wide;
                }

                if(flag){
                    wide -= 1;
                } else {
                    wide += 1;
                    if(wide == ampl){
                        flag = true;
                    }
                }

                cout << endl;
            }

            if(c == t - 1 && i == freq - 1){
                //
            } else {
                cout << endl;
            }
            //cout << "Test " << c << endl;

            flag = false;
        }
    }

    return 0;
}
