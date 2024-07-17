class Solution
{
public:
    string lcaA; // path from lca to startValue
    string lcaB; // path from lca to destValue

    TreeNode *lca(TreeNode *root, int n1, int n2)
    { // find the lowest common ancestor
        if (root == nullptr)
            return root;

        TreeNode *leftS = lca(root->left, n1, n2);
        TreeNode *rightS = lca(root->right, n1, n2);

        if ((leftS && rightS) || (root->val == n1 || root->val == n2))
            return root;

        if (leftS == nullptr)
            return rightS;
        else
            return leftS;
    }

    void dfs(TreeNode *lcaNode, int s, int d, string &path)
    { // see the path and convert into string in form of L and R
        if (lcaNode == nullptr)
            return;

        if (lcaNode->val == s)
            lcaA = path;
        if (lcaNode->val == d)
            lcaB = path;

        path.push_back('L');
        dfs(lcaNode->left, s, d, path);
        path.pop_back();

        path.push_back('R');
        dfs(lcaNode->right, s, d, path);
        path.pop_back();
    }

    string getDirections(TreeNode *root, int startValue, int destValue)
    {
        TreeNode *lcaNode = lca(root, startValue, destValue);

        string path = "";
        dfs(lcaNode, startValue, destValue, path);

        for (int i = 0; i < lcaA.size(); i++)
            lcaA[i] = 'U';

        return lcaA + lcaB;
    }
};

// https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/description/?envType=daily-question&envId=2024-07-16