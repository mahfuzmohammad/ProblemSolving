#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <string>

using namespace std;

int main(){
    deque<int> dq;
    string input;
    int t, size, m, num;

    cin >> t;

    for(int i = 1; i <= t; i++){

        cin >> size >> m;
        dq.clear();

        cout << "Case " << i << ":" << endl;

        for(int j = 0; j < m; j++){

            cin >> input;

            if(input == "pushLeft"){

                if(dq.size() == size){
                    cin >> num;
                    cout << "The queue is full" << endl;
                } else {
                    cin >> num;
                    dq.push_front(num);
                    cout << "Pushed in left: " << num << endl;
                }

            } else if(input == "pushRight"){

                if(dq.size() == size){
                    cin >> num;
                    cout << "The queue is full" << endl;
                } else {
                    cin >> num;
                    dq.push_back(num);
                    cout << "Pushed in right: " << num << endl;
                }

            } else if(input == "popLeft"){

                if(dq.size() == 0){
                    cout << "The queue is empty" << endl;
                } else {
                    cout << "Popped from left: " << dq.front() << endl;
                    dq.pop_front();
                }

            } else if(input == "popRight"){

                if(dq.size() == 0){
                    cout << "The queue is empty" << endl;
                } else {
                    cout << "Popped from right: " << dq.back() << endl;
                    dq.pop_back();
                }

            }

        }//for j

    }// for i

    return 0;
}
