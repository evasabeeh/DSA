// https:// leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/submissions/1552528373/?envType=daily-question&envId=2025-02-23

class Solution
{
public:
    int findPosition(vector<int> &postorder, int element) // find position in postorder
    {
        for (int i = 0; i < postorder.size(); i++)
        {
            if (postorder[i] == element)
                return i;
        }
        return -1;
    }
    TreeNode *solve(vector<int> &preorder, vector<int> &postorder, int prestart, int preend, int poststart, int postend)
    {
        if (prestart > preend) // there is a no subtree to be built
            return NULL;

        TreeNode *root = new TreeNode(preorder[prestart]); // first element of preorder is always a root

        if (prestart == preend)                    // only single element left
            return root;

        int position = findPosition(postorder, preorder[prestart + 1]); // root of left subtree
        int leftsubtree = position - poststart + 1;                     // number of nodes in left subtree

        root->left = solve(preorder, postorder, prestart + 1, prestart + leftsubtree, poststart, position);
        root->right = solve(preorder, postorder, prestart + leftsubtree + 1, preend, position + 1, postend - 1);
        // (prestart + leftsubtree + 1) elements are utilized by left subtree already
        
        return root;
    }
    TreeNode *constructFromPrePost(vector<int> &preorder, vector<int> &postorder)
    {
        // if(preorder.size() == 1)
        // return new TreeNode(preorder[0]);

        return solve(preorder, postorder, 0, preorder.size() - 1, 0, postorder.size() - 1);
    }
};