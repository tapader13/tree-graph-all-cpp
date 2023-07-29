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
        // adj[v].push_back(u);
    }
}
bool Cycledfs(int node, unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited, unordered_map<int, bool> &DFSvisited)
{
    visited[node] = 1;
    DFSvisited[node] = 1;

    for (auto i : adj[node])
    {
        if (!visited[i])
        {
            bool ans = Cycledfs(i, adj, visited, DFSvisited);
            if (ans)
            {
                return true;
            }
        }
        else if (DFSvisited[i])
        {
            return true;
        }
    }
    DFSvisited[node] = false;
    return false;
}
int DFS(int vertex, vector<pair<int, int>> &edges)
{
    unordered_map<int, list<int>> adj;

    unordered_map<int, bool> visited;
    unordered_map<int, bool> DFSvisited;
    createAdj(edges, adj);
    for (int i = 0; i < vertex; i++)
    {
        if (!visited[i])
        {
            bool ans = Cycledfs(i, adj, visited, DFSvisited);
            if (ans)
            {
                return true;
            }
        }
    }
    return false;
}
int main()
{
    vector<pair<int, int>> edges;
    int vertex = 4;
    edges.push_back(make_pair(0, 1));
    // edges.push_back(make_pair(0, 2));
    edges.push_back(make_pair(1, 2));
    edges.push_back(make_pair(2, 0));
    int res = DFS(vertex, edges);
    cout << res;
}