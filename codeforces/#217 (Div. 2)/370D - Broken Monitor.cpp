//In the name of Allah, most Gracious, most Compassionate
#include <bits/stdc++.h>

using namespace std;

char in[2005][2005];
vector<int> x, y;

inline bool f_wNotInBorder(int minx, int miny, int maxx, int maxy) {
    bool wNotInBorder = false;

    for(int i = 0; i < x.size(); i++) {
        if( ((x[i] != minx) && (x[i] != maxx)) && ((y[i] != miny) && (y[i] != maxy)) ) {
            wNotInBorder = true;
        }
    }

    return wNotInBorder;
}

int main() {
    //freopen("in", "r", stdin);
    int n, m;
    scanf("%d %d", &n, &m);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            scanf("\n%c", &in[i][j]);
            if(in[i][j] == 'w') {
                x.push_back(i);
                y.push_back(j);
            }
        }
    }

    int minx = *min_element(x.begin(), x.end()),
        miny = *min_element(y.begin(), y.end()),
        maxx = *max_element(x.begin(), x.end()),
        maxy = *max_element(y.begin(), y.end()),
        tmaxx = maxx, tmaxy = maxy;

    int w = max((maxx - minx), (maxy - miny));

    while(minx > 0 || miny > 0) {
        if ( (minx + w >= n) && (minx > 0) ) {
            minx--;
        } else if ( (miny + w >= m) && (miny > 0) ) {
            miny--;
        } else if ( (minx + w > maxx) && (minx > 0) ) {

            bool wNotInBorder = f_wNotInBorder(minx, miny, minx + w, miny + w);

            if(wNotInBorder) minx--;
            else break;

        }  else if ( (miny + w > maxy) && (miny > 0) ) {

            bool wNotInBorder = f_wNotInBorder(minx, miny, minx + w, miny + w);

            if(wNotInBorder) miny--;
            else break;

        } else {
            break;
        }
    }

    bool wNotInBorder = f_wNotInBorder(minx, miny, minx + w, miny + w);

    if ( (minx + w >= n) || (miny + w >= m) || wNotInBorder ) {
        printf("-1\n");
    } else {
        maxx = minx + w;
        maxy = miny + w;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(in[i][j] == 'w') {
                    printf("w");
                } else {
                    if ( (i == minx || i == maxx) && (j >= miny && j <= maxy) ) {
                        printf("+");
                    } else if ( (j == miny || j == maxy) && (i >= minx && i <= maxx) ) {
                        printf("+");
                    } else {
                        printf(".");
                    }
                }
            }

            printf("\n");
        }
    }

    return 0;
}
