
class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == nullptr)
            return root;

        TreeNode *leftS = lowestCommonAncestor(root->left, p, q);
        TreeNode *rightS = lowestCommonAncestor(root->right, p, q);

        if ((leftS && rightS) || (root->val == p->val || root->val == q->val))
            return root;

        if (leftS == nullptr)
            return rightS;
        else
            return leftS;
    }
};