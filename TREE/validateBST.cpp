#include <bits/stdc++.h>
bool isBST(BinaryTreeNode<int> *root, int min, int max)
{
    if (root == nullptr)
        return true;

    if (root->data < max && root->data > min)
    {
        bool left = isBST(root->left, min, root->data);         // root->left everything will be smaller than root so max = root->data
        bool right = isBST(root->right, root->data, max);

        return left && right;
    }
    else
        return false;
}
bool validateBST(BinaryTreeNode<int> *root)
{
    return isBST(root, INT_MIN, INT_MAX);
}