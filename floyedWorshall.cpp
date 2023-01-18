#include <bits/stdc++.h>

using namespace std;
const int N = 510;
const int INF = 99999;

int dist[N][N];

int main()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (i == j)
                dist[i][j] = 0;
            else
                dist[i][j] = INF;
        }
    }
    int n, m;
    cout << "Enter the number of nodes and edges" << endl;
    cin >> n >> m;
    cout << "Enter all edges and their weigth" << endl;
    for (int i = 0; i < m; i++)
    {
        int x, y, wt;
        cin >> x >> y >> wt;
        dist[x][y] = wt;
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    cout << endl
         << "Output Matrix:" << endl;

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (dist[i][j] == INF)
                cout << "INF  ";
            else
                cout << dist[i][j] << "  ";
        }
        cout << endl;
    }
}