class Solution
{
public:
    pair<int, int> solve(Node *root)
    { // pair < included, excluded>
        if (root == NULL)
        {
            pair<int, int> p = make_pair(0, 0);
            return p;
        }

        pair<int, int> left = solve(root->left);
        pair<int, int> right = solve(root->right);

        pair<int, int> sum;                  // max sum till now
        sum.first = root->data + left.second + right.second;         // if curr node is included
        sum.second = max(left.first, left.second) + max(right.first, right.second);       // if currnode is not included

        return sum;
    }
    int getMaxSum(Node *root)
    {
        pair<int, int> ans = solve(root);
        return max(ans.first, ans.second);
    }
};

// https://www.geeksforgeeks.org/problems/maximum-sum-of-non-adjacent-nodes/1