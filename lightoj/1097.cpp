#include <iostream>
#include <cstdio>
#include <vector>
#define maxn 1429441

using namespace std;

vector<int> vctr;


void generateOdd() {

    int indx = 0;
    int counter = 0;

    for(long long i = 1; indx <= maxn; i+= 2){
        ++counter;
        //cout << counter << endl;

        if(counter == 3){
            counter = 0;
            continue;
        }

        vctr.push_back(i);
        ++indx;
    }

}

void generateLuckyNum(){
    generateOdd();

    for(int i = 2; i < vctr.size(); i++) {
        int diff = vctr.at(i);
        bool isFirst = true;
        int deleted = 0;

        for(int j = diff; j < vctr.size(); j+=diff) {

            if(isFirst){
                vctr.erase(vctr.begin() + j);
                isFirst = false;
                ++deleted;
            } else {
                vctr.erase(vctr.begin() + j - deleted);
            }

        }//end of inner for
    }
}


int main(){
    generateLuckyNum();
    int T, n;

    cin >> T;

    for(int i = 1; i <= T; i++)
    {
        cin >> n;

        cout << "Case " << i << ": " << vctr.at(n - 1) << endl;
    }

    return 0;
}
