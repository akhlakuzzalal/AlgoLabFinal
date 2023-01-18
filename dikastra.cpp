#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int main()
{
    int n, m;
    cout << "Enter the number of nodes and edges: " << endl;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n + 1);
    cout << "Enter the edges and their weights: " << endl;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    int source;
    cout << "Enter the source node: " << endl;
    cin >> source;
    vector<int> dist(n + 1, N);
    dist[source] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source});
    while (!pq.empty())
    {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        if (d > dist[u])
            continue;
        for (auto it : adj[u])
        {
            int v = it.first;
            int w = it.second;
            if (dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    cout << "The shortest distances from the source node are: " << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << "from " << source << " to " << i << " : " << dist[i] << endl;
    }
    cout << endl;

    return 0;
}