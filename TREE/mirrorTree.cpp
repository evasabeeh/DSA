
class Solution
{
public:
    // Function to convert a binary tree into its mirror tree.
    Node *solve(Node *root)
    {
        if (!root)
            return nullptr;

        Node *left;
        Node *right;

        if (root)
        {
            left = solve(root->left);
            right = solve(root->right);

            Node *temp = root->left;
            root->left = root->right;
            root->right = temp;
        }
        return root;
    }
    void mirror(Node *node)
    {
        node = solve(node);
    }
};