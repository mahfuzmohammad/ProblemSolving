#include <iostream>
using namespace std;

int main(){
    int x1, x2, y1, y2, x, y, t, m;

    cin >> t;

    for(int i = 1; i <= t; i++){
        cin >> x1 >> y1 >> x2 >> y2;
        cin >> m;
        cout << "Case " << i << ":" << endl;

        for(int j = 0; j < m; j++){
            cin >> x >> y;

            if((x > x1 && x < x2) && (y > y1 && y < y2)){
                cout << "Yes" << endl;
            }else{
                cout << "No" << endl;
            }
        }

    }
}
