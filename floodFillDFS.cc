#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
void dfs(vector<vector<int>> &image, int sr, int sc, int newColor, int iniColor, vector<vector<int>> &newImage, int Row[], int Col[])
{
    int n = image.size();
    int m = image[0].size();
    newImage[sr][sc] = newColor;
    for (int i = 0; i < 4; i++)
    {
        int newRow = sr + Row[i];
        int newCol = sc + Col[i];
        if ((newRow >= 0 && newRow < n) && (newCol >= 0 && newCol < m) && image[newRow][newCol] == iniColor && newImage[newRow][newCol] != newColor)
        {
            dfs(image, newRow, newCol, newColor, iniColor, newImage, Row, Col);
        }
    }
}
vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
{
    int iniColor = image[sr][sc];
    vector<vector<int>> newImage = image;
    int Row[] = {0, 0, -1, +1};
    int Col[] = {-1, +1, 0, 0};
    dfs(image, sr, sc, newColor, iniColor, newImage, Row, Col);
    return newImage;
}
int main()
{
    vector<vector<int>> image{
        {1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 0, 0},
        {1, 0, 0, 1, 1, 0, 1, 1},
        {1, 2, 2, 2, 2, 0, 1, 0},
        {1, 1, 1, 2, 2, 0, 1, 0},
        {1, 1, 1, 2, 2, 2, 2, 0},
        {1, 1, 1, 1, 1, 2, 1, 1},
        {1, 1, 1, 1, 1, 2, 2, 1}};
    int sr = 4, sc = 4, newColor = 3;
    vector<vector<int>> result = floodFill(image, sr, sc, newColor);
    for (auto i : result)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}