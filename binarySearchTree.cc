#include <iostream>
#include <queue>
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
node *insertNode(node *root, int d)
{
    if (root == NULL)
    {
        root = new node(d);
        return root;
    }
    if (d > root->data)
    {
        root->right = insertNode(root->right, d);
    }
    if (d < root->data)
    {
        root->left = insertNode(root->left, d);
    }
    return root;
}
void buildTree(node *&root)
{
    int d;
    cout << "Enter Root" << endl;
    cin >> d;

    while (d != -1)
    {
        root = insertNode(root, d);
        cin >> d;
    }
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
bool searchBst(node *root, int n)
{
    if (root == NULL)
    {
        return false;
    }
    if (root->data == n)
    {
        return true;
    }
    if (root->data > n)
    {
        searchBst(root->left, n);
    }
    else
    {
        searchBst(root->right, n);
    }
}
node *maxValue(node *root)
{
    node *temp = root;
    while (temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp;
}
node *minValue(node *root)
{
    node *temp = root;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}
node *succecor(node *root, node *n)
{
    node *suc = NULL;
    while (root != NULL)
    {
        if (n->data >= root->data)
        {
            root = root->right;
        }
        else
        {
            suc = root;
            root = root->left;
        }
    }
    return suc;
}
node *preseccor(node *root, node *n)
{
    node *pre = NULL;
    while (root != NULL)
    {
        if (n->data <= root->data)
        {
            root = root->left;
        }
        else
        {
            pre = root;
            root = root->right;
        }
    }
    return pre;
}
node *deleteNode(node *root, int d)
{
    if (root == NULL)
    {
        return root;
    }
    if (root->data == d)
    {
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        if (root->left == NULL && root->right != NULL)
        {
            node *temp = root->right;
            delete root;
            return temp;
        }
        if (root->left != NULL && root->right == NULL)
        {
            node *temp = root->left;
            delete root;
            return temp;
        }
        if (root->left != NULL && root->right != NULL)
        {
            int temp = minValue(root->right)->data;
            root->data = temp;
            root->right = deleteNode(root->right, temp);
            return root;
        }
    }
    else if (root->data < d)
    {
        root->right = deleteNode(root->right, d);
        return root;
    }
    else if (root->data > d)
    {
        root->left = deleteNode(root->left, d);
        return root;
    }

    return root;
}
void validBst(node *root, vector<int> &arr)
{
    if (root == NULL)
    {
        return;
    }
    validBst(root->left, arr);
    arr.push_back(root->data);
    validBst(root->right, arr);
}
void smalle(node *root, int n, vector<int> &arr)
{
    if (root == NULL)
    {
        return;
    }
    smalle(root->left, n, arr);
    arr.push_back(root->data);
    smalle(root->right, n, arr);
}
void kThSmallest(node *root, int n)
{
    vector<int> arr;
    smalle(root, n, arr);
    int res = arr[n - 1];
    cout << res;
}
void kThLargest(node *root, int n)
{
    vector<int> arr;
    smalle(root, n, arr);
    int res = arr[arr.size() - n];
    cout << res;
}
node *LCA(node *root, node *r1, node *r2)
{
    if (root == NULL)
    {
        return NULL;
    }
    while (root != NULL)
    {
        if (root->data < r1->data && root->data < r2->data)
        {
            root = root->right;
        }
        else if (root->data > r1->data && root->data > r2->data)
        {
            root = root->left;
        }
        else
        {
            return root;
        }
    }
}
void twoSum(node *root, vector<int> &v)
{
    if (root == NULL)
    {
        return;
    }
    twoSum(root->left, v);
    v.push_back(root->data);
    twoSum(root->right, v);
}
void bstToNode(node *root)
{
    vector<int> arr;
    validBst(root, arr);
    node *newNode = new node(arr[0]);
    node *curr = newNode;
    for (int i = 1; i < arr.size(); i++)
    {
        node *temp = new node(arr[i]);
        curr->left = NULL;
        curr->right = temp;
        curr = temp;
    }
    curr->left = NULL;
    curr->right = NULL;
    while (newNode->right != NULL)
    {
        cout << newNode->data << " ";
        newNode = newNode->right;
    }
}
node *inorderToBst(int s, int e, vector<int> &arr)
{
    if (s > e)
    {
        return NULL;
    }
    int mid = s + (e - s) / 2;
    node *root = new node(arr[mid]);
    root->left = inorderToBst(s, mid - 1, arr);
    root->right = inorderToBst(mid + 1, e, arr);
    return root;
}
node *normalBstToBalanceBst(node *root)
{
    vector<int> arr;
    validBst(root, arr);

    return inorderToBst(0, arr.size() - 1, arr);
}
node *preorderToInorder(vector<int> &preorder, int start, int end)
{
    if (start > end)
    {
        return NULL;
    }

    int mid = start;
    while (mid <= end && preorder[mid] <= preorder[start])
    {
        mid++;
    }

    node *root = new node(preorder[start]);
    root->left = preorderToInorder(preorder, start + 1, mid - 1);
    root->right = preorderToInorder(preorder, mid, end);

    return root;
}

node *preorderToInorder(vector<int> &preorder)
{
    return preorderToInorder(preorder, 0, preorder.size() - 1);
}
node *mergeToSortedTree(node *root, node *root1)
{
    vector<int> v;
    vector<int> v1;
    vector<int> v2;

    validBst(root, v);
    validBst(root1, v1);
    int i = 0, j = 0;
    while (i < v.size() && j < v1.size())
    {
        if (v[i] < v1[j])
        {
            v2.push_back(v[i]);
            i++;
        }
        else
        {
            v2.push_back(v1[j]);
            j++;
        }
    }
    while (i < v.size())
    {

        v2.push_back(v[i]);
        i++;
    }
    while (j < v1.size())
    {

        v2.push_back(v1[j]);
        j++;
    }
    return inorderToBst(0, v2.size() - 1, v2);
}

int main()
{
    // 40 30 25 35 50 45 60 -1
    node *root = NULL;
    buildTree(root);
    //  deleteNode(root, 45);

    // node *root1 = NULL;
    // buildTree(root1);
    // node *balancedRoot = mergeToSortedTree(root, root1);
    // inorder(balancedRoot);

    // vector<int> preorder = {20, 10, 5, 15, 13, 35, 30, 42};

    // node *preorderoot = preorderToInorder(preorder);
    // levelOrder(preorderoot);

    // node *balancedRoot = normalBstToBalanceBst(root);
    // levelOrder(balancedRoot);

    // bstToNode(root);

    // vector<int> v;
    // twoSum(root, v);
    // int i = 0, j = v.size() - 1, target = 70;
    // bool val = false;
    // while (i <= j)
    // {
    //     if (v[i] + v[j] == target)
    //     {
    //         val = true;
    //         break;
    //     }
    //     else if (v[i] + v[j] < target)
    //     {
    //         i++;
    //     }
    //     else if (v[i] + v[j] > target)
    //     {
    //         j--;
    //     }
    // }
    // if (val)
    // {
    //     cout << "Full";
    // }
    // else
    // {
    //     cout << "Not";
    // }

    // node *root1 = new node(45);
    // node *root2 = new node(60);
    // cout << LCA(root, root1, root2)->data;

    // kThLargest(root, 3);

    // kThSmallest(root, 5);

    // vector<int> arr;
    // validBst(root, arr);
    // bool valid = true;
    // for (int i = 0; i < arr.size() - 1; i++)
    // {
    //     if (arr[i] > arr[i + 1])
    //     {
    //         valid = false;
    //         break;
    //     }
    // }
    // if (valid)
    // {
    //     cout << "Valid";
    // }
    // else
    // {
    //     cout << "Not";
    // }

    // node *root1 = new node(30);
    // cout << preseccor(root, root1)->data;

    // node *root1 = new node(30);
    // cout << succecor(root, root1)->data;

    // cout << maxValue(root)->data;
    // cout << minValue(root)->data;

    // levelOrder(root);

    // cout << searchBst(root, 28);
}