// nodes at the boundary of tree : anticlockwise beginning from root

class Solution
{
public:
    vector<int> ans;
    void leftT(Node *root)
    {
        if (root == nullptr || (root->left == nullptr && root->right == nullptr))
            return;

        ans.push_back(root->data);

        if (root->left)
            leftT(root->left);
        else
            leftT(root->right);
    }
    void leaves(Node *root)
    {
        if (root == nullptr)
            return;

        if (root->left == nullptr && root->right == nullptr)
            ans.push_back(root->data);

        leaves(root->left);
        leaves(root->right);
    }
    void rightT(Node *root)
    {
        if (root == nullptr || (root->left == nullptr && root->right == nullptr))
            return;

        if (root->right)
            rightT(root->right);
        else
            rightT(root->left);

        ans.push_back(root->data);
    }
    vector<int> boundary(Node *root)
    {
        ans.push_back(root->data); // here so that root is not again and again printed when traversing
        
        leftT(root->left);

        leaves(root->left);       // from left part of root it will traverse so right part leaves will be left
        leaves(root->right);

        rightT(root->right);

        return ans;
    }
};

// https://www.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card