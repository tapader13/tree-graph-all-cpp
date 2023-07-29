#include <iostream>

#include <vector>
#include <list>
#include <queue>
#include <unordered_map>
#include <algorithm>
using namespace std;
void createAdj(vector<pair<int, int>> &edges, unordered_map<int, list<int>> &adj)
{
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}
void Cyclebfs(int node, unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited, int source, int target)
{
    unordered_map<int, int> parent;
    parent[node] = -1;
    visited[node] = 1;
    queue<int> q;
    q.push(node);

    while (!q.empty())
    {
        int frontNode = q.front();
        q.pop();

        for (auto i : adj[frontNode])
        {
            if (!visited[i])
            {
                q.push(i);
                visited[i] = 1;
                parent[i] = frontNode;
            }
        }
    }
    vector<int> result;
    int curr = target;
    result.push_back(target);
    while (curr != source)
    {
        curr = parent[curr];
        result.push_back(curr);
    }
    reverse(result.begin(), result.end());
    for (auto i : result)
    {
        cout << i << " ";
    }
}
void BFS(int vertex, vector<pair<int, int>> &edges, int source, int target)
{
    unordered_map<int, list<int>> adj;

    unordered_map<int, bool> visited;
    createAdj(edges, adj);
    for (int i = 1; i <= vertex; i++)
    {
        if (!visited[i])
        {
            Cyclebfs(i, adj, visited, source, target);
        }
    }
}
int main()
{

    int source = 1;
    int target = 8;
    int vertex, edgesCount;
    cout << "Enter the number of vertices: ";
    cin >> vertex;

    cout << "Enter the number of edges: ";
    cin >> edgesCount;

    vector<pair<int, int>> edges;
    for (int i = 0; i < edgesCount; i++)
    {
        int u, v;
        cout << "Enter edge " << i + 1 << " (u v): ";
        cin >> u >> v;
        edges.push_back(make_pair(u, v));
    }
    BFS(vertex, edges, source, target);
}