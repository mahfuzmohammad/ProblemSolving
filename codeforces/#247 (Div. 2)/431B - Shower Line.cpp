//In the name of Allah, most Gracious, most Compassionate
#include <bits/stdc++.h>

using namespace std;

vector< vector<int> > perm;
int arr[10][10];

int calc(int x) {
    int ret = 0;
    ret =   (arr[perm[x][0]][perm[x][1]] + arr[perm[x][1]][perm[x][0]] + arr[perm[x][2]][perm[x][3]] + arr[perm[x][3]][perm[x][2]]) +
            (arr[perm[x][1]][perm[x][2]] + arr[perm[x][2]][perm[x][1]] + arr[perm[x][3]][perm[x][4]] + arr[perm[x][4]][perm[x][3]]) +
            (arr[perm[x][2]][perm[x][3]] + arr[perm[x][3]][perm[x][2]]) + (arr[perm[x][3]][perm[x][4]] + arr[perm[x][4]][perm[x][3]]);

    return ret;
}

int main() {

    vector<int> v;
    for(int i = 1; i <= 5; i++) {
        v.push_back(i);
    }

    do {
        perm.push_back(v);
    } while (next_permutation(v.begin(), v.end()));

    for(int i = 1; i <= 5; i++) {
        for(int j = 1; j <= 5; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    int ans = 0;
    for(int i = 0; i < 120; i++) {
        ans = max(ans, calc(i));
    }

    printf("%d\n", ans);

    return 0;
}
