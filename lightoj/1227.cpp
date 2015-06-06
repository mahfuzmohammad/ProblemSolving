//Bismillahir Rahmanir Rahim
//Author: Md Mahfuzur Rahman Siddiquee

#include <iostream>

using namespace std;

int main(){
    int eggsGM[30], t, n, p, q, i, j, eggCounter, result;

    cin >> t;

    for(i = 1; i <= t; i++){

        cin >> n >> p >> q;
        // take each eggs weight in array
        for(j = 0; j < n; j++){
            cin >> eggsGM[j];
        }

        eggCounter = 0;
        result = 0;
        j = 0;

        while(eggCounter < p && j <= n - 1){

            if((result + eggsGM[j]) <= q){
                result += eggsGM[j];
                ++eggCounter;
            }

            ++j;

        }// end of while

        cout << "Case " << i << ": " << eggCounter << endl; // output

    }// end of for

    return 0;
}
