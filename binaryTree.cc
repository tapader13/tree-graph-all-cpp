#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
    node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};
node *buildTree(node *root)
{
    int d;
    cout << "Enter Root" << endl;
    cin >> d;
    root = new node(d);
    if (d == -1)
    {
        return NULL;
    }
    cout << "Enter left data for Root " << d << endl;
    root->left = buildTree(root->left);
    cout << "Enter right data for Root " << d << endl;
    root->right = buildTree(root->right);
    return root;
}
void levelOrder(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}
void inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
void Preorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    Preorder(root->left);

    Preorder(root->right);
}
void postOrder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    postOrder(root->left);

    postOrder(root->right);
    cout << root->data << " ";
}
void deleteNode(node *root, int data)
{
    if (root == NULL)
    {
        cout << "Tree empty" << endl;
        return;
    }
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        if (temp->data == data)
        {
            node *curr = root;
            node *prev;
            while (curr->right != NULL)
            {
                prev = curr;
                curr = curr->right;
            }
            temp->data = curr->data;
            prev->right = NULL;
            free(curr);
            cout << "Delet Done"
                 << " " << endl;
            return;
        }
        if (temp->left != NULL)
        {
            q.push(temp->left);
        }
        if (temp->right != NULL)
        {
            q.push(temp->right);
        }
    }
    cout << "Not Found" << endl;
}
int height(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int left = height(root->left);
    int right = height(root->right);
    int ans = max(left, right) + 1;
    return ans;
}
int diameter(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int left = diameter(root->left);
    int right = diameter(root->right);
    int dia = height(root->left) + height(root->right) + 1;
    int ans = max(left, max(right, dia));
    return ans;
}
bool balanced(node *root)
{
    if (root == NULL)
    {
        return true;
    }
    bool left = balanced(root->left);
    bool right = balanced(root->right);
    int def = abs(height(root->left) - height(root->right)) <= 1;
    if (left && right && def)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool identical(node *root, node *root1)
{
    if (root == NULL && root1 == NULL)
    {
        return true;
    }
    if (root != NULL && root1 == NULL)
    {
        return false;
    }
    if (root == NULL && root1 != NULL)
    {
        return false;
    }
    bool left = identical(root->left, root1->left);
    bool right = identical(root->right, root1->right);
    bool val = root->data == root1->data;
    if (left && right && val)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool sumTree(node *root)
{

    if (root == NULL)
    {
        return true;
    }
    if (root->left == NULL && root->right == NULL)
    {

        return root->data;
    }
    bool left = sumTree(root->left);
    bool right = sumTree(root->right);

    if (left && right && root->data == left + right)
    {
        return 1;
    }
    return INT_MIN;
}
void bounderyLeft(node *root, vector<int> &ans)
{
    if ((root == NULL) || root->left == NULL && root->right == NULL)
    {
        return;
    }
    ans.push_back(root->data);
    if (root->left)
    {
        bounderyLeft(root->left, ans);
    }
    else
    {
        bounderyLeft(root->right, ans);
    }
}
void leafeLeft(node *root, vector<int> &ans)
{
    if (root == NULL)
    {
        return;
    }
    if (root->left == NULL && root->right == NULL)
    {
        ans.push_back(root->data);
    }

    leafeLeft(root->left, ans);

    leafeLeft(root->right, ans);
}
void bounderyRight(node *root, vector<int> &ans)
{
    if ((root == NULL) || root->left == NULL && root->right == NULL)
    {
        return;
    }

    if (root->right)
    {
        bounderyRight(root->right, ans);
    }
    else
    {
        bounderyRight(root->left, ans);
    }
    ans.push_back(root->data);
}
vector<int> boundaryTraverse(node *root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }
    ans.push_back(root->data);
    bounderyLeft(root->left, ans);
    leafeLeft(root->left, ans);
    leafeLeft(root->right, ans);
    bounderyRight(root->right, ans);
    return ans;
}
vector<vector<int>> zigzag(node *root)
{
    vector<vector<int>> ans;
    if (root == NULL)
    {
        return ans;
    }
    bool leftRight = true;
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        vector<int> res(size);
        for (int i = 0; i < size; i++)
        {
            node *temp = q.front();
            q.pop();
            int index = leftRight ? i : (size - 1 - i);
            res[index] = temp->data;
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
        ans.push_back(res);
        leftRight = !leftRight;
    }
    return ans;
}
vector<int> topView(node *root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }
    map<int, int> mp;
    queue<pair<node *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        pair<node *, int> p = q.front();
        q.pop();
        node *temp = p.first;
        int line = p.second;
        if (mp.find(line) == mp.end())
        {
            mp[line] = temp->data;
        }
        if (temp->left)
        {
            q.push({temp->left, line - 1});
        }
        if (temp->right)
        {
            q.push({temp->right, line + 1});
        }
    }
    for (auto i : mp)
    {
        ans.push_back(i.second);
    }
    return ans;
}
vector<int> vottomView(node *root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }
    map<int, int> mp;
    queue<pair<node *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        pair<node *, int> p = q.front();
        q.pop();
        node *temp = p.first;
        int line = p.second;

        mp[line] = temp->data;

        if (temp->left)
        {
            q.push({temp->left, line - 1});
        }
        if (temp->right)
        {
            q.push({temp->right, line + 1});
        }
    }
    for (auto i : mp)
    {
        ans.push_back(i.second);
    }
    return ans;
}
void solveL(node *root, vector<int> &ans, int lavel)
{
    if (root == NULL)
    {
        return;
    }
    if (lavel == ans.size())
    {
        ans.push_back(root->data);
    }
    solveL(root->left, ans, lavel + 1);
    solveL(root->right, ans, lavel + 1);
}
vector<int> leftView(node *root)
{
    vector<int> ans;
    solveL(root, ans, 0);
    return ans;
}
void solveR(node *root, vector<int> &ans, int lavel)
{
    if (root == NULL)
    {
        return;
    }
    if (lavel == ans.size())
    {
        ans.push_back(root->data);
    }
    solveR(root->right, ans, lavel + 1);
    solveR(root->left, ans, lavel + 1);
}
vector<int> rightView(node *root)
{
    vector<int> ans;
    solveR(root, ans, 0);
    return ans;
}
node *LCA(node *root, int n1, int n2)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == n1 || root->data == n2)
    {
        return root;
    }
    node *left = LCA(root->left, n1, n2);
    node *right = LCA(root->right, n1, n2);
    if (left != NULL && right != NULL)
    {
        return root;
    }
    if (left != NULL && right == NULL)
    {
        return left;
    }
    if (left == NULL && right != NULL)
    {
        return right;
    }
    if (left == NULL && right == NULL)
    {
        return NULL;
    }
}
void result(node *root, int k, vector<int> v, int &count)
{
    if (root == NULL)
    {
        return;
    }
    v.push_back(root->data);
    result(root->left, k, v, count);
    result(root->right, k, v, count);
    int sum = 0;
    for (int i = v.size() - 1; i >= 0; i--)
    {
        sum += v[i];
        if (sum == k)
        {
            count++;
        }
    }
    v.pop_back();
}
int kSumPaths(node *root, int k)
{
    vector<int> v;
    int count = 0;
    result(root, k, v, count);
    return count;
}
node *ansis(node *root, int &k, int n)
{

    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == n)
    {
        return root;
    }
    node *left = ansis(root->left, k, n);
    node *right = ansis(root->right, k, n);
    if (left != NULL && right == NULL)
    {
        k--;
        if (k == 0)
        {
            return root;
        }
        return left;
    }
    if (left == NULL && right != NULL)
    {
        k--;
        if (k == 0)
        {
            return root;
        }
        return right;
    }
    return NULL;
}
int KAnsistor(node *root, int k, int n)
{
    node *ans = ansis(root, k, n);
    if (ans == NULL || ans->data == n)
    {
        return -1;
    }
    else
    {
        return ans->data;
    }
}
class info
{
public:
    int maximum;
    int minimum;
    bool isBst;
    int size;
};
info solve(node *root, int &maxNum)
{
    if (root == NULL)
    {
        return {INT_MIN, INT_MAX, true, 0};
    }
    info left = solve(root->left, maxNum);
    info right = solve(root->right, maxNum);
    info current;
    current.maximum = max(root->data, right.maximum);
    current.minimum = min(root->data, left.minimum);
    current.size = left.size + right.size + 1;
    if (left.isBst && right.isBst && (left.maximum < root->data && root->data < right.minimum))
    {
        current.isBst = true;
    }
    else
    {
        current.isBst = false;
    }
    if (current.isBst)
    {
        maxNum = max(current.size, maxNum);
    }
    return current;
}
int largestBstSubtree(node *root)
{
    int maxNum = 0;
    info temp = solve(root, maxNum);
    return maxNum;
}
int main()
{
    // 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1
    node *root = NULL;
    root = buildTree(root);

    cout << largestBstSubtree(root);

    // node *root1 = NULL;

    // root = buildTree(root);
    // cout << KAnsistor(root, 1, 7);

    // cout << kSumPaths(root, 4);

    // cout << LCA(root, 2, 3)->data;

    // vector<int> res = rightView(root);
    // for (auto i : res)
    // {
    //     cout << i << " ";
    // }

    // vector<int> res = leftView(root);
    // for (auto i : res)
    // {
    //     cout << i << " ";
    // }

    // vector<int> res = vottomView(root);
    // for (auto i : res)
    // {
    //     cout << i << " ";
    // }

    // vector<int> res = topView(root);
    // for (auto i : res)
    // {
    //     cout << i << " ";
    // }

    // vector<vector<int>> res = zigzag(root);
    // for (auto i : res)
    // {
    //     for (auto j : i)
    //     {
    //         cout << j << " ";
    //     }
    //     cout << endl;
    // }

    // vector<int> res = boundaryTraverse(root);
    // for (auto i : res)
    // {
    //     cout << i << " ";
    // }

    // if (sumTree(root) != INT_MIN)
    // {
    //     cout << "Binary tree is a sum tree";
    // }
    // else
    // {
    //     cout << "Binary tree is not a sum tree";
    // }
    // root1 = buildTree(root1);
    // deleteNode(root, 9);
    // levelOrder(root);
    // levelOrder(root1);
    // cout << identical(root, root1);
    // cout << height(root);
    // cout << diameter(root);
    // cout << balanced(root);
    // cout << "Inorder ";
    // inorder(root);
    // cout << endl;
    // cout << "Preorder ";
    // Preorder(root);
    // cout << endl;
    // cout << "postOrder ";
    // postOrder(root);
    // cout << endl;
}
