#include <iostream>
#include <cstdio>
#include <queue>
#define maxmn 500


using namespace std;


char array[maxmn + 5][maxmn + 5];
int temp[maxmn + 5][maxmn + 5];
int result[maxmn + 5];

int color;

struct point {
    int x, y;
    point(){}
    point(int a, int b){x = a; y = b;}
};

void reset()
{
    color = 0;
    for(int i = 0; i <= maxmn; i++) {
        for(int j = 0; j <= maxmn; j++) {
            array[i][j] = '\0';
            temp[i][j] = -1;
        }
        result[i] = 0;
    }
}

void resetTemp(int M, int N)
{
    for(int i = 0; i <= M; i++) {
        for(int j = 0; j <= N; j++) {
            temp[i][j] = 0;
        }
    }
}

void print(int M, int N)
{
    for(int i = 1; i <= M; i++) {
        for(int j = 1; j <= N; j++) {
            cout << temp[i][j] << " ";
        }
        cout << endl;
    }
}

int collect(int M, int N, point pt) {
    //resetTemp(M, N);
    //cout << array[pt.x][pt.y] << endl;
    temp[pt.x][pt.y] = color;
    int found = 0;
    point u;

    queue<point> q;
    q.push(pt);

    while(!q.empty()) {
        u = q.front();
        q.pop();
        //cout << array[u.x][u.y] << endl;

        if(array[u.x][u.y] == 'C'){
            ++found;
        }

        if(u.x + 1 > 0 && u.x + 1 <= M && array[u.x + 1][u.y] != '#') {
            if(temp[u.x + 1][u.y] == -1) {
                q.push(point(u.x + 1, u.y));
                temp[u.x + 1][u.y] = color;
                //cout << "r " << array[u.x + 1][u.y] << endl;
            }
        }

        if(u.x - 1 > 0 && u.x - 1 <= M && array[u.x - 1][u.y] != '#') {
            if(temp[u.x - 1][u.y] == -1) {
                q.push(point(u.x - 1, u.y));
                temp[u.x - 1][u.y] = color;
                //cout << "l " << array[u.x - 1][u.y] << endl;
            }
        }

        if(u.y + 1 > 0 && u.y + 1 <= N && array[u.x][u.y + 1] != '#') {
            if(temp[u.x][u.y + 1] == -1) {
                q.push(point(u.x, u.y + 1));
                temp[u.x][u.y + 1] = color;
                //cout << "d " << array[u.x][u.y + 1] << endl;
            }
        }

         if(u.y - 1 > 0 && u.y - 1 <= N && array[u.x][u.y - 1] != '#') {
            if(temp[u.x][u.y - 1] == -1) {
                q.push(point(u.x, u.y - 1));
                temp[u.x][u.y - 1] = color;
                //cout << "u " << array[u.x][u.y - 1] << endl;
            }
        }
    }

    result[color] = found;
    color += 1;

    return found;
}


int main()
{
    //freopen("input.txt", "r", stdin);
    int T, M, N, Q, x, y;
    char input;

    cin >> T;

    for(int i = 1; i <= T; i++) {
        reset();

        cin >> M >> N >> Q;

        for(int k = 1; k <= M; k++) {
            for(int l = 1; l <= N; l++) {
                cin >> array[k][l];
            }
        }


        cout << "Case " << i << ":" << endl;

        for(int k = 0; k < Q; k++) {
            cin >> x >> y;
            //cout << temp[x][y] << endl;
            if(temp[x][y] == -1){
                //cout << "test" << endl;
                cout << collect(M, N, point(x, y)) << endl;
            }
            else {
                cout << result[temp[x][y]] << endl;
            }
        }

        //print(M, N);

    }

    return 0;
}
