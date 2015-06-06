//In the name of Allah, most Gracious, most Compassionate
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    int cnt = 0;
    int r = 2;
    int i = 1, j = 1;
    for(; i <= n; ) {
        if(k == 1) break;

        cout << r;

        if(i % 2) {

            int loop = j + r - 1;

            if(loop <= m) {
                for(; j <= loop; j++) {
                    cout << " " << i << " " << j;
                }
            } else {
                for(; j <= m; j++) {
                    cout << " " << i << " " << j;
                }

                i++;
                loop -= m;
                loop = m - loop + 1;
                for(j = m; j >= loop; j--) {
                    cout << " " << i << " " << j;
                }
            }

        } else {

            int loop = j - r + 1;

            if(loop >= 1) {
                for(; j >= loop; j--) {
                    cout << " " << i << " " << j;
                }
            } else {
                for(; j >= 1; j--) {
                    cout << " " << i << " " << j;
                }

                i++;
                loop *= -1;
                loop++;

                for(j = 1; j <= loop; j++) {
                    cout << " " << i << " " << j;
                }
            }

        }

        k--;
        cnt += 2;
        cout << endl;
    }

    r = (n * m) - cnt;
    cout << r;

    for(; i <= n; i++) {
        //cout << "TEST " << i << " " << j << endl;

        if(i % 2) {

            if(j <= 0) {
                j *= -1;
                j++;
            }

//            if(j > m) {
//                j %= m;
//            }

            for(; j <= m; j++) {
                cout << " " << i << " " << j;
            }

        } else {

            if(j > m) {
                int t = j - m;
                j = m - t + 1;
                //cout << "HERE " << j << endl;
            }

            for(; j >= 1; j--) {
                cout << " " << i << " " << j;
            }

        }

    }
    cout << endl;

    return 0;
}
