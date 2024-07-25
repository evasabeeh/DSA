// size of largest bst

class info
{
public:
    int minn;      // min element of subtree
    int maxx;
    bool isBST;    // is subtree bst
    int size;      // size of subtree
};

class Solution
{
public:
    int maxSize = 0;

    info solve(Node *root)
    {
        if (root == nullptr)
            return {INT_MAX, INT_MIN, true, 0};

        info left = solve(root->left);
        info right = solve(root->right);

        info curr;
        curr.size = left.size + right.size + 1;
        curr.minn = min(root->data, left.minn);
        curr.maxx = max(root->data, right.maxx);

        if (left.isBST && right.isBST && (root->data < right.minn && root->data > left.maxx))
            curr.isBST = true;
        else
            curr.isBST = false;

        if (curr.isBST)
            maxSize = max(maxSize, curr.size);

        return curr;
    }
    int largestBst(Node *root)
    {
        solve(root);
        return maxSize;
    }
};

// https://www.geeksforgeeks.org/problems/largest-bst/1