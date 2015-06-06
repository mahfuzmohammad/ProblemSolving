//In the name of Allah, most Gracious, most Compassionate
#include <bits/stdc++.h>

using namespace std;

int main() {

    string str;
    int k, len;
    cin >> str >> k;

    len = str.size();

    for(int i = 0; i < len; i++) {
        char maxnum = str[i];
        int maxpos = -1;

        //cout << i << " " << k << endl;

        for(int j = i + 1; j < len; j++) {
            if( (maxnum < str[j]) && (j - i <= k) ) {
                maxnum = str[j];
                maxpos = j;
            }
        }

        if(maxpos == -1) continue;
        //cout << maxpos << endl;

        for(int j = maxpos; j > i; j--) {
            swap(str[j], str[j - 1]);
            k--;
        }
    }

    cout << str << endl;

    return 0;
}
