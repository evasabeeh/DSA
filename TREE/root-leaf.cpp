// https://leetcode.com/problems/binary-tree-paths/

class Solution
{
public:
    void solve(TreeNode *root, vector<string> &ans, string temp)
    {
        if (root == nullptr)
            return;

        temp = temp + to_string(root->val) + "->";

        if (root->left == nullptr && root->right == nullptr)
            ans.push_back(temp.substr(0, temp.size() - 2));

        solve(root->left, ans, temp);
        solve(root->right, ans, temp);
    }
    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<string> ans;
        string temp;
        solve(root, ans, temp);
        return ans;
    }
};