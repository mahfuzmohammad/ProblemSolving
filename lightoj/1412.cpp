#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>

#define MAXN 100000
#define IMPOS -1
#define INF 0
#define YES 1

using namespace std;


vector<int> uvRel[MAXN + 1];
int array[MAXN + 5];


int reset()
{
    for(int i = 0; i <= MAXN; i++)
    {
        uvRel[i].clear();
    }
}


void check()
{
    for(int i = 0; i <= MAXN; i++)
    {
        array[i] = INF;
    }

    queue<int> q;
    q.push(1);
    array[1] = YES;

    while(!q.empty())
    {
        int u = q.front();
        q.pop();


        for(int i = 0; i < uvRel[u].size(); i++)
        {
            if(array[uvRel[u][i]] == INF)
            {
                array[uvRel[u][i]] = YES;
                q.push(uvRel[u][i]);
            }
        }
    }
}


int getPrice(int n)
{
    //cout << array[n] << endl;
    if(array[n] == INF) return IMPOS;

    return (n - 1);
}


int main()
{
    int t, n, m, u, v, q, k;

    cin >> t;


    for(int i = 1; i <= t; i++)
    {
        reset();
        cin >> n >> m;

        for(int j = 0; j < m; j++)
        {
            cin >> u >> v;

            uvRel[u].push_back(v);
        }


        cin >> q;

        if(q > 0)
            check();

        cout << "Case " << i << ":" << endl;


        for(int j = 0; j < q; j++)
        {
            cin >> k;

            if(getPrice(k) == IMPOS)
                cout << "impossible" << endl;
            else
                cout << getPrice(k) << endl;
        }
    }


    return 0;
}
