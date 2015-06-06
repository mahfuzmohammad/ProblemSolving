#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <sstream>

using namespace std;

string itr(string s){
    long long num = atoll(s.c_str());
    //cout << num << endl;
    reverse(s.begin(), s.end());
    long long rnum = atoll(s.c_str());
    //cout << rnum << endl;
    stringstream ss;
    ss << (num + rnum);

    return ss.str();
}

bool isPalindrome(string s){
    int ssize = s.size();
    int a = 0, b = ssize - 1;

    while(a <= b){
        if(s[a] != s[b]){
            return false;
        }
        ++a;
        --b;
    }

    return true;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int T, count;
    string num;

    cin >> T;

    for(int i = 0; i < T; i++){
        cin >> num;
        count = 0;
        string temp;
        temp = num;

        while(!isPalindrome(temp)){
            //cout << "Test" << endl;
            temp = itr(temp);
            ++count;
        }

        cout << count << " " << temp << endl;
    }

    return 0;
}
