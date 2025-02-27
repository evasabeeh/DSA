// https://leetcode.com/problems/recover-a-tree-from-preorder-traversal/
// https://www.geeksforgeeks.org/problems/construct-tree-from-preorder-traversal/1


class Solution
{
public:
    TreeNode *recoverFromPreorder(string traversal)
    {
        stack<TreeNode *> levels; // it always holds the path from root to current node and stack size represents the current depth
        int idx = 0;

        while (idx < traversal.size())
        {
            int depth = 0;
            while (idx < traversal.size() && traversal[idx] == '-')
            { // count dashes == depth
                depth++;
                idx++;
            }
            int number = 0;
            while (idx < traversal.size() && isdigit(traversal[idx]))
            { // prepare value
                number = number * 10 + (traversal[idx] - '0');
                idx++;
            }
            TreeNode *node = new TreeNode(number); // make node

            while (levels.size() > depth) // because stack size represents current depth so make it equal that
                levels.pop();

            if (!levels.empty())
            {
                if (levels.top()->left == nullptr)
                    levels.top()->left = node;
                else
                    levels.top()->right = node;
            }
            levels.push(node);
        }
        while (levels.size() > 1)
        { // the first element of stack is the leftmost node of tree so return that
            levels.pop();
        }
        return levels.top();
    }
};