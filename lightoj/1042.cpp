#include <iostream>
using namespace std;

int main(){
    long n, count, count2, current;
    long long j, j2;
    int t;

    cin >> t;

    for(int i = 1; i <= t; i++){
        count = 0;
        cin >> n;

        current = n;

        while (current != 0){

            if(current % 2 != 0){
                count++;
                current /= 2;
            } else {
                current /= 2;
            }

        }//end of while

        for(j = n + 1;  ; j++){

            //cout << j << endl;
            count2 = 0;
            j2 = j;
            //cout << j << endl;
            while (j2 != 0){

                if(j2 % 2 != 0){
                    ++count2;
                    j2 /= 2;
                } else {
                    j2 /= 2;
                }

            }//end of while

            if(count == count2){
                cout << "Case " << i << ": " << j << endl;
                break;
            } else {
                continue;
            }

        }//end of for

    }//end of for
}
