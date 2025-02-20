// https://leetcode.com/problems/house-robber-iii/

class Solution
{
public:
    pair<int, int> solve(TreeNode *root)
    { // pair < included, excluded>
        if (root == NULL)
        {
            pair<int, int> p = make_pair(0, 0);
            return p;
        }

        pair<int, int> left = solve(root->left);
        pair<int, int> right = solve(root->right);

        pair<int, int> sum; // max sum till now
        sum.first =
            root->val + left.second + right.second; // if curr node is included
        sum.second =
            max(left.first, left.second) +
            max(right.first, right.second); // if currnode is not included

        return sum;
    }
    int rob(TreeNode *root)
    {
        pair<int, int> ans = solve(root);
        return max(ans.first, ans.second);
    }
};