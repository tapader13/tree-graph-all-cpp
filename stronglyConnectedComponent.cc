#include <iostream>
using namespace std;
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <unordered_map>
#include <algorithm>

void createAdj(vector<pair<int, int>> &edges, unordered_map<int, list<int>> &adj)
{
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;
        adj[u].push_back(v);
    }
}

void dfs(stack<int> &st, int node, unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited)
{
    visited[node] = true;
    for (auto i : adj[node])
    {
        if (!visited[i])
        {
            dfs(st, i, adj, visited);
        }
    }
    st.push(node);
}
void revDFS(int node, unordered_map<int, list<int>> &transpose, unordered_map<int, bool> &visited)
{
    visited[node] = true;
    for (auto i : transpose[node])
    {
        if (!visited[i])
        {
            revDFS(i, transpose, visited);
        }
    }
}
void DFS(int vertex, vector<pair<int, int>> &edges)
{
    unordered_map<int, list<int>> adj;
    stack<int> st;
    unordered_map<int, bool> visited;
    createAdj(edges, adj);

    for (int i = 0; i < vertex; i++)
    {
        if (!visited[i])
        {
            dfs(st, i, adj, visited);
        }
    }
    unordered_map<int, list<int>> transpose;
    for (int i = 0; i < vertex; i++)
    {
        visited[i] = false;
        for (auto j : adj[i])
        {
            transpose[j].push_back(i);
        }
    }
    int count = 0;
    while (!st.empty())
    {

        int trnFront = st.top();
        st.pop();
        if (!visited[trnFront])
        {
            count++;
            revDFS(trnFront, transpose, visited);
        }
    }
    cout << count;
}

int main()
{
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

    DFS(vertex, edges);

    return 0;
}
