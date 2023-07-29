#include <iostream>
using namespace std;

int main()
{

    int n, m;
    cin >> n >> m;
    int adjMat[n][n];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            adjMat[i][j] = 0;
        }
    }

    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        adjMat[u][v] = 1;
        adjMat[v][u] = 1;
    }
    cout << " ";
    for (int i = 1; i <= n; i++)
    {
        cout << " " << i;
    }
    cout << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << i << " ";
        for (int j = 1; j <= n; j++)
        {
            cout << adjMat[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
