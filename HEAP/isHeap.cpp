// if CBT
// node is highest or smallest -> maxOrder property or minOrder property


class Solution
{
public:
    int countNodes(struct Node *root)
    {
        if (root == nullptr)
            return 0;

        int ans = 1 + countNodes(root->left) + countNodes(root->right);
        return ans;
    }
    bool isCBT(struct Node *root, int index, int count)
    { // count of nodes
        if (root == nullptr)
            return true;

        if (index >= count)
            return false;

        bool left = isCBT(root->left, 2 * index + 1, count);
        bool right = isCBT(root->right, 2 * index + 2, count);

        return left && right;
    }
    bool isMaxOrder(struct Node *root)
    {
        if (root->left == nullptr && root->right == nullptr) // heap
            return true;

        if (root->right == nullptr) // not checking for left because its CBT
            return (root->data > root->left->data);

        bool left = isMaxOrder(root->left);
        bool rightft = isMaxOrder(root->right);

        return left && right && (root->data > root->left->data && root->data > root->right->data);
    }
    bool isHeap(struct Node *tree)
    {
        int count = countNodes(tree);
        if (isCBT(tree, 0, count) && isMaxOrder(tree))
            return true;

        return false;
    }
};


// O(n)