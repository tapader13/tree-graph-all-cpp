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
void dfs(vector<int> &ans, int node, unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited)
{
    ans.push_back(node);
    visited[node] = 1;
    for (auto i : adj[node])
    {
        if (!visited[i])
        {
            dfs(ans, i, adj, visited);
        }
    }
}
vector<int> DFS(int vertex, vector<pair<int, int>> &edges)
{
    unordered_map<int, list<int>> adj;
    vector<int> ans;
    unordered_map<int, bool> visited;
    createAdj(edges, adj);
    for (int i = 0; i < vertex; i++)
    {
        if (!visited[i])
        {
            dfs(ans, i, adj, visited);
        }
    }
    return ans;
}
int main()
{
    vector<pair<int, int>> edges;
    int vertex = 5;
    edges.push_back(make_pair(0, 1));
    edges.push_back(make_pair(0, 2));
    edges.push_back(make_pair(0, 3));
    edges.push_back(make_pair(2, 4));
    edges.push_back(make_pair(3, 2));
    vector<int> v = DFS(vertex, edges);
    for (auto i : v)
    {
        cout << i << " ";
    }
}