class Solution             // sum tree = every node value is equal to its left and right subtree values
{
public:
    bool ans;
    int sum(Node *root)
    {
        if (root == nullptr)
        {
            ans = true;
            return 0;
        }

        int a = sum(root->left);
        int b = sum(root->right);
        int s = a + b;

        if (root->left == nullptr && root->right == nullptr)
            return root->data;
        else if (s == root->data)
            s += root->data;
        else
            ans = false;

        return s;
    }
    bool isSumTree(Node *root)
    {
        ans = true;

        sum(root);

        return ans;
    }
};