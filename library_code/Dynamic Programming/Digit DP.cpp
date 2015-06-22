// Given a and b
// Calculate the summation
// of all the digits between a and b inclusive


#include <bits/stdc++.h>

using namespace std;

#define ll long long

pair<ll, ll> dp[4][20][12];
int arr[20];

pair<ll, ll> calc (int flag, int curPos, int digit, int& digitSize) {

    if(curPos == digitSize) return pair<ll, ll>(1, digit); // first = numOfWays, second = sum

    if(dp[flag][curPos][digit] != pair<ll, ll>(-1, -1)) {
        return dp[flag][curPos][digit];
    }

    pair<ll, ll> temp, ans;
    temp = pair<ll, ll>(0, 0);
    ans  = pair<ll, ll>(0, 0);

    if(flag == 1) {
        for(int i = 0; i <= arr[curPos]; i++) {
            if(i == arr[curPos])
                temp = calc(1, curPos + 1, i, digitSize);
            else temp = calc(0, curPos + 1, i, digitSize);

            ans.second += (digit * temp.first) + temp.second;
            ans.first += temp.first;
        }
    } else {
        for(int i = 0; i <= 9; i++) {
            temp = calc(0, curPos + 1, i, digitSize);
            ans.second += (digit * temp.first) + temp.second;
            ans.first += temp.first;
        }
    }

    dp[flag][curPos][digit] = ans;
    return dp[flag][curPos][digit];
}

int main() {



    int T, cnt;
    ll  hi, low,
        temphi, templow;

    cin >> T;

    for(int i = 0; i < T; i++) {
        cin >> low >> hi;
        temphi = hi;
        templow = low - 1;

        cnt = 0;
        while(temphi > 0) {
            cnt++;
            temphi /= 10;
        }

        temphi = hi;

        for(int j = cnt - 1; j >= 0; j--) {
            arr[j] = temphi % 10;
            temphi /= 10;
        }

        for(int j = 0; j < 2; j++) {
            for(int k = 0; k < 20; k++) {
                for(int l = 0; l < 12; l++) {
                    dp[j][k][l] = pair<ll, ll>(-1, -1);
                }
            }
        }


        pair<ll, ll> hiC, lowC;
        hiC = calc(1, 0, 0, cnt);

        cnt = 0;
        while(templow > 0) {
            cnt++;
            templow /= 10;
        }

        templow = low - 1;
        for(int j = cnt - 1; j >= 0; j--) {
            arr[j] = templow % 10;
            templow /= 10;
        }

        for(int j = 0; j < 2; j++) {
            for(int k = 0; k < 20; k++) {
                for(int l = 0; l < 12; l++) {
                    dp[j][k][l] = pair<ll, ll>(-1, -1);
                }
            }
        }

        lowC = calc(1, 0, 0, cnt);
        cout << hiC.second - lowC.second << endl;
    }

    return 0;
}
