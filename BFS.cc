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
void bfs(vector<int> &ans, int node, unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited)
{
    queue<int> q;
    q.push(node);
    visited[node] = 1;
    while (!q.empty())
    {
        int frontNode = q.front();
        q.pop();
        ans.push_back(frontNode);
        for (auto i : adj[frontNode])
        {
            if (!visited[i])
            {
                q.push(i);
                visited[i] = 1;
            }
        }
    }
}
vector<int> BFS(int vertex, vector<pair<int, int>> &edges)
{
    unordered_map<int, list<int>> adj;
    vector<int> ans;
    unordered_map<int, bool> visited;
    createAdj(edges, adj);
    for (int i = 0; i < vertex; i++)
    {
        if (!visited[i])
        {
            bfs(ans, i, adj, visited);
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
    edges.push_back(make_pair(1, 3));
    edges.push_back(make_pair(1, 2));
    edges.push_back(make_pair(2, 4));
    edges.push_back(make_pair(3, 4));
    vector<int> v = BFS(vertex, edges);
    for (auto i : v)
    {
        cout << i << " ";
    }
}