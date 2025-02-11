// https://leetcode.com/problems/binary-tree-cameras/

// -1 - out of range; 1 - covered; 0 - node has camera
class Solution
{
public:
    int cameras = 0;
    int solve(TreeNode *root)
    {
        if (!root)
            return 1; // covered by camera

        int left = solve(root->left);
        int right = solve(root->right);

        if (left == -1 || right == -1)
        { // not covered by camera so here camera can be installed
            cameras++;
            return 0;
        }
        else if (left == 0 || right == 0) // left and right any have camera then it is covered
            return 1;
        else
            return -1;
    }
    int minCameraCover(TreeNode *root)
    {
        int ans = solve(root);

        if (ans == -1)
            return ++cameras;

        return cameras;
    }
};