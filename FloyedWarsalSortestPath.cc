#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

void addEdge(vector<vector<int>> &mat)
{
    int n = mat.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] == -1)
            {
                mat[i][j] = 1e9;
            }
            if (i == j)
            {
                mat[i][j] = 0;
            }
        }
    }

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] == 1e9)
            {
                cout << "INF"
                     << " ";
            }
            else
            {
                cout << mat[i][j] << " ";
            }
        }
        cout << endl;
    }
}

int main()
{
    int v = 4;
    vector<vector<int>> mat(v, vector<int>(v, -1));

    mat[0][1] = 5;
    mat[0][3] = 10;
    mat[1][2] = 3;
    mat[2][3] = 1;

    addEdge(mat);

    return 0;
}
