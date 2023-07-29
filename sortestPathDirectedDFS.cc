#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include <limits.h>
using namespace std;
class Graph
{
public:
    unordered_map<int, list<pair<int, int>>> adj;
    void addEdge(int u, int v, int w)
    {
        pair<int, int> p = make_pair(v, w);
        adj[u].push_back(p);
    }
    void print()
    {
        for (auto i : adj)
        {
            cout << i.first << "->";
            for (auto j : i.second)
            {
                cout << "(" << (j.first) << "," << (j.second) << "), ";
            }
            cout << endl;
        }
    }
    void dfs(int node, unordered_map<int, bool> &visited, stack<int> &st)
    {
        visited[node] = 1;
        for (auto i : adj[node])
        {
            if (!visited[i.first])
            {
                dfs(i.first, visited, st);
            }
        }
        st.push(node);
    }
    void sortestPath(int src, vector<int> &distance, stack<int> &st)
    {
        distance[src] = 0;
        while (!st.empty())
        {
            int node = st.top();
            st.pop();
            if (distance[node] != INT_MAX)
            {
                for (auto i : adj[node])
                {
                    if (distance[node] + i.second < distance[i.first])
                    {
                        distance[i.first] = distance[node] + i.second;
                    }
                }
            }
        }
    }
};
int main()
{

    Graph g;
    g.addEdge(0, 2, 4);
    g.addEdge(1, 0, 3);
    g.addEdge(2, 3, -3);
    g.addEdge(2, 4, 2);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 3, 5);
    g.addEdge(4, 3, 2);
    // g.print();
    int n = 5;
    unordered_map<int, bool> visited;
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            g.dfs(i, visited, st);
        }
    }
    int src = 0;
    vector<int> distance(n);
    for (int i = 0; i < n; i++)
    {
        distance[i] = INT_MAX;
    }
    g.sortestPath(src, distance, st);
    for (auto i : distance)
    {
        if (i == INT_MAX)
        {
            cout << "INF ";
        }
        else
        {
            cout << i << " ";
        }
    }
}