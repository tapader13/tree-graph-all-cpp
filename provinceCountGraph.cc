#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

class Solution
{
private:
    void dfs(int node, unordered_map<int, list<int>> &adjLs, unordered_map<int, bool> &vis)
    {
        vis[node] = 1;
        for (auto it : adjLs[node])
        {
            if (!vis[it])
            {
                dfs(it, adjLs, vis);
            }
        }
    }

public:
    int numProvinces(vector<vector<int>> adj, int V)
    {

        unordered_map<int, list<int>> adjLs;
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (adj[i][j] == 1 && i != j)
                {
                    adjLs[i].push_back(j);
                    adjLs[j].push_back(i);
                }
            }
        }
        unordered_map<int, bool> vis;
        int cnt = 0;
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                cnt++;
                dfs(i, adjLs, vis);
            }
        }
        return cnt;
    }
};

int main()
{

    vector<vector<int>> adj{
        {1, 0, 1},
        {0, 1, 0},
        {1, 0, 1}};

    Solution ob;
    cout << ob.numProvinces(adj, 3) << endl;

    return 0;
}