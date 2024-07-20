class Solution
{
public:
    int ans = INT_MIN;
    int solve(TreeNode *root)
    {
        if (root == nullptr)
            return 0;

        int leftSum = solve(root->left);           // current left path max sum
        int rightSum = solve(root->right);

        int currMax = max({leftSum + root->val, rightSum + root->val, leftSum + rightSum + root->val, root->val});
        // till this node max sum
        
        ans = max({ans, currMax});

        return max({leftSum + root->val, rightSum + root->val, root->val}); // can go further from one side only
    }
    int maxPathSum(TreeNode *root)
    {
        solve(root);
        return ans;
    }
};

// https://leetcode.com/problems/binary-tree-maximum-path-sum/description/