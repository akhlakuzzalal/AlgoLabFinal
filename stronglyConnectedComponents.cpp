#include <bits/stdc++.h>

using namespace std;

void dfs(int node, vector<int> &vis, stack<int> &st, vector<int> adj[])
{
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it])
            dfs(it, vis, st, adj);
    }
    st.push(node);
}

void revDfs(int node, vector<int> &vis, vector<int> transpose[])
{
    vis[node] = 1;
    cout << node << " ";
    for (auto it : transpose[node])
    {
        if (!vis[it])
            revDfs(it, vis, transpose);
    }
}

int main()
{
    int n, m;
    cout << "Enter the number of nodes and edges" << endl;
    cin >> n >> m;
    vector<int> adj[n];
    cout << "Enter all edges" << endl;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    stack<int> st;
    vector<int> vis(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
            dfs(i, vis, st, adj);
    }
    vector<int> transpose[n];
    for (int i = 0; i < n; i++)
    {
        vis[i] = 0;
        for (auto it : adj[i])
            transpose[it].push_back(i);
    }
    while (!st.empty())
    {
        int node = st.top();
        st.pop();
        if (!vis[node])
        {
            cout << "SCC: ";
            revDfs(node, vis, transpose);
            cout << endl;
        }
    }
    return 0;
}