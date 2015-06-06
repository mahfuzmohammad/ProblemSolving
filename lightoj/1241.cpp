#include <iostream>

using namespace std;

int main(){

    int t, n, a, lies, temp, nose;

    cin >> t;

    for(int i = 1; i <= t; i++){

        cin >> n;

        lies = 0;
        temp = 2;

        while(n > 0){

            cin >> a;

            if(a > temp){
                nose = a - temp;

                check:

                //cout << "Nose : " << nose << endl;

                switch(nose){

                    case 5:
                        ++lies;
                        nose -= 5;
                        //cout << "case 5" << endl;
                        goto check;
                        break;

                    case 4:
                        ++lies;
                        nose -= 4;
                        //cout << "case 4" << endl;
                        goto check;
                        break;

                    case 3:
                        ++lies;
                        nose -= 3;
                        //cout << "case 3" << endl;
                        goto check;
                        break;

                    case 2:
                        ++lies;
                        nose -= 2;
                        //cout << "case 2" << endl;
                        goto check;
                        break;

                    case 1:
                        ++lies;
                        nose -= 1;
                        //cout << "case 1" << endl;
                        goto check;
                        break;

                    case 0:
                        break;

                    default:
                        ++lies;
                        nose -= 5;
                        goto check;
                        break;

                }
            }

            temp = a;

            --n;
        }

        cout << "Case " << i << ": " << lies << endl;

    }

    return 0;
}
