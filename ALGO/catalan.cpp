// unique binary search tree
// combination of n pairs of ()

class Solution
{
public:
    int numTrees(int n)
    {
        // make each node root once
        // if ith is made root then left subtree will have i-1 nodes and n-i nodes in right subtree, considering 1 <= i <= n
        // f(i) = sum [f(i-1) * f(n-i)]

        if (n <= 1)
            return 1;

        int ans = 0;
        for (int i = 1; i <= n; i++)
            ans += numTrees(i - 1) * numTrees(n - i);

        return ans;
    }
};