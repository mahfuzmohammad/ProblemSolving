#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
    if(!b) return a;
    return gcd(b, a % b);
}

int divc(int a, int x) {
    if(!a) return 0;
    int ans = 0;

    while((a % x) == 0) {
        a /= x;
        ans++;
    }

    return ans;
}

int main() {

    int a, b, g, ans = 0;
    cin >> a >> b;

    if(a == b) {
        cout << 0 << endl;
    } else {

        g = gcd( max(a, b), min(a, b) );
        a /= g, b /= g;

        int temp = 0;

        temp = divc(a, 2);
        ans += temp;
        if(temp > 0) {
            g = gcd(a, 2);
            while((a % g) == 0) {
                a /= g;
            }
        }

        temp = divc(a, 3);
        ans += temp;
        if(temp > 0) {
            g = gcd(a, 3);
            while((a % g) == 0) {
                a /= g;
            }
        }

        temp = divc(a, 5);
        ans += temp;
        if(temp > 0) {
            g = gcd(a, 5);
            while((a % g) == 0) {
                a /= g;
            }
        }

        //cout << b << endl;
        temp = divc(b, 2);
        ans += temp;
        if(temp > 0) {
            g = gcd(b, 2);
            while((b % g) == 0) {
                b /= g;
            }
        }

        //cout << b << endl;

        temp = divc(b, 3);
        ans += temp;
        if(temp > 0) {
            g = gcd(b, 3);
            while((b % g) == 0) {
                b /= g;
            }
        }

        temp = divc(b, 5);
        ans += temp;
        if(temp > 0) {
            g = gcd(b, 5);
            while((b % g) == 0) {
                b /= g;
            }
        }

        //cout << a << " " << b << " " << ans << endl;
        if(a == b) {
            cout << ans << endl;
        } else {
            cout << -1 << endl;
        }
    }

    return 0;
}
