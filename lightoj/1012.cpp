#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <vector>

#define MAXRC 20


using namespace std;


int tbl[MAXRC][MAXRC];


void reset(){
    for(int i = 0; i < MAXRC; i++)
    {
        for(int j = 0; j < MAXRC; j++)
        {
            tbl[i][j] = -1;
        }
    }
}//end of reset


int getRow(int x, int col)
{
    if(x % col == 0)
        return (x / col) - 1;


    return x / col;
}


int getCol(int x, int col)
{
    return (x % col) - 1;
}

int queueReady(int r, int c, int col)
{
    return ((r * col) + (c + 1));
}


int BFS(int source, int col, int row)
{
    int num = 1;
    int currentC, currentR, left, right, top, bottom;

    queue<int> q;
    q.push(source);

    while(!q.empty())
    {
        int u = q.front();
        //cout << "test" << endl;
        q.pop();
        //cout << "test2" << endl;
        //cout << u << endl;

        currentC = (getCol(u, col) == -1)? col - 1 : getCol(u, col);
        currentR = getRow(u, col);
        left = max(currentC - 1, 0);
        //cout << "left " << left << "u " << u << endl;
        right = min(currentC + 1, col - 1);
        top = max(currentR - 1, 0);
        bottom = min(currentR + 1, row - 1);

        if(tbl[currentR][left] != -1 && tbl[currentR][left] == 0)
        {
            tbl[currentR][left] = 1;
            q.push(queueReady(currentR, left, col));
            //cout << queueReady(currentR, left, col) << endl;
            //cout << "1" << endl;
            ++num;
        }

        if(tbl[currentR][right] != -1 && tbl[currentR][right] == 0)
        {
            tbl[currentR][right] = 1;
            q.push(queueReady(currentR, right, col));
            //cout << queueReady(currentR, right, col) << endl;
            //cout << "2" << endl;
            ++num;
        }

        if(tbl[top][currentC] != -1 && tbl[top][currentC] == 0)
        {
            tbl[top][currentC] = 1;
            q.push(queueReady(top, currentC, col));
            //cout << queueReady(top, currentC, col) << endl;
            //cout << "3" << endl;
            ++num;
        }

        if(tbl[bottom][currentC] != -1 && tbl[bottom][currentC] == 0)
        {
            tbl[bottom][currentC] = 1;
            q.push(queueReady(bottom, currentC, col));
            //cout << queueReady(bottom, currentC, col) << endl;
            //cout << "4" << endl;
            ++num;
        }

        //cout << q.empty() << endl;
    }


    return num;
}// BFS


int main()
{
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t, width, height, source;
    char input;
    //cout << "test" << endl;
    cin >> t;


    for(int k = 1; k <= t; k++)
    {
        //cout << "test" << endl;
        cin >> width >> height;
        //cout << width << " " << height << endl;
        reset();
        //cout << "test" << endl;

        for(int l = 0; l < height; l++)
        {
            //cout << "testfor1" << endl;
            for(int m = 0; m < width; m++)
            {
                //cout << "testfor2" << endl;
                cin >> input;

                if(input == '.')
                {
                    tbl[l][m] = 0;
                }

                if(input == '@')
                {
                    tbl[l][m] = 1;
                    source = queueReady(l, m, width);
                }
            }
        }

        cout << "Case " << k << ": " << BFS(source, width, height) << endl;


        /*for(int l = 0; l < height; l++)
        {
            for(int m = 0; m < width; m++)
            {
                cout << tbl[l][m] << "\t";
            }
            cout << endl;
        }*/
    }

    return 0;
}
