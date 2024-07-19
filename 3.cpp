#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int maxPathSumUtil(TreeNode *node, int &max_sum)
{
    if (!node)
        return 0;

    int left_sum = max(0, maxPathSumUtil(node->left, max_sum));
    int right_sum = max(0, maxPathSumUtil(node->right, max_sum));

    max_sum = max(max_sum, left_sum + right_sum + node->val);

    return max(left_sum, right_sum) + node->val;
}

int maxPathSum(TreeNode *root)
{
    int max_sum = INT_MIN;
    maxPathSumUtil(root, max_sum);
    return max_sum;
}

int main()
{
    TreeNode *root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    cout << "Maximum path sum: " << maxPathSum(root) << endl;

    return 0;
}
