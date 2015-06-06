#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

int main(){
    //freopen("input.txt", "r", stdin);
    vector<string> stk;
    vector<string>::iterator start;
    vector<string>::iterator end;
    int t, index;
    string input;

    cin >> t;

    for(int i = 1; i <= t; i++){

        cin >> input;
	    stk.clear();
        index = 0;
        stk.push_back("http://www.lightoj.com/");
        cout << "Case " << i << ":" << endl;

        while(input != "QUIT"){

            if(input == "VISIT"){

                if(index != stk.size() - 1){
                    start = stk.begin() + index + 1;
                    end = stk.end();
                    stk.erase(start, end);
                }

                cin >> input;
                stk.push_back(input);
                cout << stk.back() << endl;
                ++index;

            } else if(input == "BACK"){

                if(index > 0)
                    cout << stk[--index] << endl;
                else
                    cout << "Ignored" << endl;

            } else if(input == "FORWARD"){

                if(index == stk.size() - 1)
                    cout << "Ignored" << endl;
                else
                    cout << stk[++index] << endl;

            }

            cin >> input;


        }


    }

    return 0;
}
