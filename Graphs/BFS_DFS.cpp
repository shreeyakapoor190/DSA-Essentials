#include <bits/stdc++.h>
using namespace std;

class graph
{
public:
    int V;
    vector<list<int>> adj;
    vector<int> visited;
    graph(int V);

    void addedge(int u, int v);
    void BFS(int v);
    void DFS(int v);
};

graph::graph(int V)
{
    this->V = V;
    adj.resize(V);
    visited.resize(V);
    for (int i = 0; i < V; i++)
    {
        visited[i] = 0;
    }
}

void graph::addedge(int u, int v)
{
    adj[u].push_back(v);
}

void graph::BFS(int v)
{
    int vis[V];
    for (int i = 0; i < V; i++)
    {
        vis[i] = 0;
    }

    queue<int> q;
    q.push(v);
    vis[v] = 1;

    while (!q.empty())
    {
        v = q.front();
        q.pop();
        cout << v << endl;
        for (auto i = adj[v].begin(); i != adj[v].end(); i++)
        {
            if (!vis[*i])
            {
                vis[*i] = 1;
                q.push(*i);
            }
        }
    }
}

void graph::DFS(int v)
{
    visited[v] = 1;
    cout << v << endl;
    for (auto i : adj[v])
    {
        if (!visited[i])
        {
            DFS(i);
        }
    }
}

int main()
{
    graph g(4);
    g.addedge(0, 1);
    g.addedge(0, 2);
    g.addedge(1, 2);
    g.addedge(2, 0);
    g.addedge(2, 3);
    g.addedge(3, 3);
    cout << "DFS: " << endl;
    g.DFS(2);
    cout << "BFS: " << endl;
    g.BFS(2);
    return 0;
}