class Solution
{
public:
    int findPosition(vector<int> &in, int start, int end, int element, int n)        // or map can be used so that it need not to be traversed again and again
    {
        for (int i = start; i <= end; i++)
        {
            if (in[i] == element)
                return i;
        }
        return -1;
    }
    TreeNode *solve(vector<int> &in, vector<int> &pre, int &index, int inorderStart, int inorderEnd, int n)
    {
        if (index >= n || inorderStart > inorderEnd)
            return NULL;

        int element = pre[index++]; // preorder is root, left, right... so we will traverse one by one and start making one by one roots

        TreeNode *root = new TreeNode(element);
        int pos = findPosition(in, inorderStart, inorderEnd, element, n); // find position of root created in inorder vector
                                                                          // so because inorder is as left root right so
        root->left = solve(in, pre, index, inorderStart, pos - 1, n);     // left portion of element will be in left and other in right
        root->right = solve(in, pre, index, pos + 1, inorderEnd, n);

        return root;
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        int index = 0;
        return solve(inorder, preorder, index, 0, inorder.size() - 1, inorder.size());
    }
};

// TC: O(n log n)    SC: O(n)

// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/


/*
In case of postorder and inorder

right subtree will be built before left tree

*/