#include <iostream>
#include <sstream>
#include <queue>
#include <string>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

string serialize(TreeNode *root)
{
    if (!root)
        return "#";

    ostringstream out;
    out << root->val << " ";
    out << serialize(root->left) << " ";
    out << serialize(root->right);
    return out.str();
}

TreeNode *deserializeHelper(istringstream &in)
{
    string val;
    in >> val;

    if (val == "#")
        return nullptr;

    TreeNode *node = new TreeNode(stoi(val));
    node->left = deserializeHelper(in);
    node->right = deserializeHelper(in);
    return node;
}

TreeNode *deserialize(const string &data)
{
    istringstream in(data);
    return deserializeHelper(in);
}

void printInOrder(TreeNode *root)
{
    if (!root)
        return;
    printInOrder(root->left);
    cout << root->val << " ";
    printInOrder(root->right);
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    string serialized = serialize(root);
    cout << "Serialized tree: " << serialized << endl;

    TreeNode *deserialized = deserialize(serialized);
    cout << "Deserialized tree (in-order): ";
    printInOrder(deserialized);
    cout << endl;

    return 0;
}
