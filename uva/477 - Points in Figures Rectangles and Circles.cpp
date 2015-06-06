#include <bits/stdc++.h>

using namespace std;

struct obj {
    char type;
    double ux, uy, lx, ly, cx, cy, r;
    obj(char t, double _ux, double _uy, double _lx, double _ly) {
        type = t;
        ux = _ux, uy = _uy, lx = _lx, ly = _ly;
    }

    obj(char t, double _cx, double _cy, double _r) {
        type = t;
        cx = _cx, cy = _cy, r = _r;
    }

    bool isinsideRec(double x, double y) {
        return ((x > ux && x < lx) && (y > ly && y < uy));
    }

    bool isinsideCir(double x, double y) {
        return ((fabs(cx-x)*fabs(cx-x) + fabs(cy-y)*fabs(cy-y)) < r*r);
    }

    bool isInside(double x, double y) {
        if(type == 'r') return isinsideRec(x, y);
        return isinsideCir(x, y);
    }
};

vector<obj> v;

int main() {
    char in;
    double ux, uy, lx, ly, cx, cy, r;

    while(cin >> in && (in != '*')) {
        if(in == 'r') {
            cin >> ux >> uy >> lx >> ly;
            v.push_back(obj(in, ux, uy, lx, ly));
        } else if(in == 'c') {
            cin >> cx >> cy >> r;
            v.push_back(obj(in, cx, cy, r));
        }
    }

    int pnt = 0;
    while(cin >> cx >> cy) {
        if(cx == 9999.9 && cy == 9999.9) break;
        ++pnt;

        bool flag = false;
        for(int i = 0; i < v.size(); i++) {
            if(v[i].isInside(cx, cy)) {
                flag = true;
                cout << "Point " << pnt << " is contained in figure " << i+1 << "\n";
            }
        }

        if(!flag) {
            cout << "Point " << pnt << " is not contained in any figure\n";
        }
    }

    return 0;
}
