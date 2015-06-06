#include <bits/stdc++.h>

using namespace std;

vector<int> task[2005];
int arrh[2005];
vector<int> temp;
bool taken[2005];
int anscnt = 0;
int n, h;

void printans(int i) {
    //cout << "TEST " << i << endl;
    if(i > 2000) return;
    if(anscnt == 3) return;
    if(temp.size() == n) {
        for(int j = 0; j < n; j++) {
            if(j > 0) cout << " ";
            cout << temp[j];
        }
        cout << "\n";
        anscnt++;
        return;
    }

    for(int j = 0; j < task[i].size(); j++) {
        if(!taken[task[i][j]]) {
            taken[task[i][j]] = true;
            temp.push_back(task[i][j]);
            printans(i);
            taken[task[i][j]] = false;
            temp.pop_back();
        }
    }

    printans(i + 1);
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    bool pos = false;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> h;
        task[h].push_back(i);
        arrh[h]++;
    }

    int mul = 1;
    for(int i = 1; i <= 2000; i++) {
        if(arrh[i]) mul *= arrh[i];
        if(mul >= 3) {
            pos = true;
            break;
        }
    }

    if(pos) {
        cout << "YES\n";
        printans(1);
    } else {
        cout << "NO\n";
    }

    return 0;
}
