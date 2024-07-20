class Solution
{
public:
    int count = 0;
    void solve(TreeNode *root, int sum, int target)
    {
        if (root == nullptr)
            return;

        sum += root->val;

        if (sum == target)
            count++;

        solve(root->left, sum, target);
        solve(root->right, sum, target);
    }
    int pathSum(TreeNode *root, int targetSum)
    {
        if (root == nullptr)
            return 0;

        solve(root, 0, targetSum);
        pathSum(root->left, targetSum); // this because path can always start from any node not only root node
        pathSum(root->right, targetSum);

        return count;
    }
};

// https://leetcode.com/problems/path-sum-iii/description/