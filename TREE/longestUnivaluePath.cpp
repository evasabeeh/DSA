class Solution
{
public:
    int maxx = 0;
    int solve(TreeNode *root)
    { // returning current longest path
        if (root == nullptr)
            return 0;

        int leftT = solve(root->left);   // longest univalue path from left
        int rightT = solve(root->right); // from right

        int leftPath = 0, rightPath = 0;              // new variables so that if the right ptr is null then right path value will be 0
        if (root->left != nullptr && root->val == root->left->val) // for current node if its value is same as left node then the univalue path is continued adding 1 more node to it that is the current node
            leftPath = leftT + 1;
        if (root->right != nullptr && root->val == root->right->val)
            rightPath = rightT + 1;

        maxx = max(maxx, leftPath + rightPath); // longest univalue path

        return max(leftPath, rightPath); // return left longest or right longest because for other nodes one path can be continued only if observed
    }
    int longestUnivaluePath(TreeNode *root)
    {
        solve(root);
        return maxx;
    }
};

// https://leetcode.com/problems/longest-univalue-path/