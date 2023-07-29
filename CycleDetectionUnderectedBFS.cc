#include <iostream>
using namespace std;
#include <vector>
#include <list>
#include <queue>
#include <unordered_map>
#include <algorithm>
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
bool Cyclebfs(int node, unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited)
{
    unordered_map<int, int> parent;
    parent[node] = -1;
    queue<int> q;
    q.push(node);
    visited[node] = 1;
    while (!q.empty())
    {
        int frontNode = q.front();
        q.pop();

        for (auto i : adj[frontNode])
        {
            if (visited[i] == true && parent[frontNode] != i)
            {
                return true;
            }
            else if (!visited[i])
            {
                q.push(i);
                visited[i] = 1;
                parent[i] = frontNode;
            }
        }
    }
    return false;
}
int BFS(int vertex, vector<pair<int, int>> &edges)
{
    unordered_map<int, list<int>> adj;
    bool ans;
    unordered_map<int, bool> visited;
    createAdj(edges, adj);
    for (int i = 0; i < vertex; i++)
    {
        if (!visited[i])
        {
            ans = Cyclebfs(i, adj, visited);
        }
    }
    return ans;
}
int main()
{
    vector<pair<int, int>> edges;
    int vertex = 4;
    edges.push_back(make_pair(0, 1));
    edges.push_back(make_pair(0, 2));
    // edges.push_back(make_pair(1, 2));
    edges.push_back(make_pair(2, 3));
    int res = BFS(vertex, edges);
    cout << res;
}