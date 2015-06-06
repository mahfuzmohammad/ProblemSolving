#include <iostream>
using namespace std;

int main(){
    long n, count;
    int t;

    cin >> t;

    for(int i = 1; i <= t; i++){
        count = 0;
        cin >> n;

        while (n != 0){

            if(n % 2 != 0){
                count++;
                n /= 2;
            } else {
                n /= 2;
            }

        }//end of while

        cout << "Case " << i << ":";

        if(count % 2 == 0){
            cout << " even" << endl;
        } else {
            cout << " odd" << endl;
        }

    }//end of for
}
