// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/


class Solution
{
public:
    TreeNode *constructBalanceBST(int start, int end, vector<int> nums)
    {
        if (start > end)
            return NULL;

        int mid = (start + end) / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = constructBalanceBST(start, mid - 1, nums);
        root->right = constructBalanceBST(mid + 1, end, nums);

        return root;
    }

    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return constructBalanceBST(0, nums.size() - 1, nums);
    }
};