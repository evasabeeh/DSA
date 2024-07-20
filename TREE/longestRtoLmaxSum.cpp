class Solution
{
public:
    int count = 0, ans = 0;
    void solve(Node *root, int sum, int num)           // num is count of nodes till now
    {
        if (root == nullptr)
            return;

        if (root->left == nullptr && root->right == nullptr)
        {
            sum += root->data;
            if (num == count)
                ans = max(sum, ans);
            else if (num > count)
            {
                count = num;
                ans = sum;
            }
            return;
        }
        sum += root->data;
        solve(root->left, sum, num + 1);
        solve(root->right, sum, num + 1);
    }
    int sumOfLongRootToLeafPath(Node *root)
    {
        int sum = 0, num = 0;
        solve(root, sum, num);
        return ans;
    }
};

// https://www.geeksforgeeks.org/problems/sum-of-the-longest-bloodline-of-a-tree/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card