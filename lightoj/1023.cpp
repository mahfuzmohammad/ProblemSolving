#include <iostream>
#include <stdio.h>

using namespace std;

long long factorial (int a)
{
    //cout << "Entered";
  if (a > 1)
   return (a * factorial (a-1));
  else
   return (1);
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    char eng[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    char action[26];
    int t, n, k, I, J, right, left, counter, poss, d, diff;
    long long fact;

    cin >> t;

    for(I = 1; I <= t; I++){

        cin >> n >> k;

        for(J = 0; J < n; J++){
            action[J] = eng[J];
        }


        right = n - 1;
        diff = 2;
        left = right - diff;
        counter = 0;

        //cout << fact;

        while( left >= 0 && counter <= k ){
            fact = factorial(diff);
            //cout << "first while" << endl;
            while( counter < fact && counter <= k ){
                //cout << "Second while" << endl;
                d = left + 2;
                //cout << d << endl;

                while( d <= right ){
                    //cout << "Third while" << endl;

                    poss = left + 1;
                    //counter++;

                    while ( poss <= right ){
                    //cout << "forth while" << endl;

                        if(poss != d){
                            ++action[poss];
                        } else {
                            action[poss] -= 2;
                        }

                        ++poss;

                    }

                    for(int i = 0; i < k; i++){
                        cout << action[i];
                    }
                    cout << endl;
                    counter++;
                    ++d;

                }

                ++diff;
                --left;

            }
            ++diff;
            //left = right - diff;

            --left;

            //cout << left << endl;
        }


    }

    return 0;
}
