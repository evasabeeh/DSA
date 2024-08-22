class Solution
{
public: // partition technique
    int minHeightShelves(vector<vector<int>> &books, int shelfWidth)
    {
        int n = books.size();
        int dp[n + 1]; // height
        dp[0] = 0;     // when no books

        for (int i = 1; i <= n; i++)
        {
            int width = books[i - 1][0], height = books[i - 1][1];
            dp[i] = dp[i - 1] + height; // min height to accomodate first i books

            for (int j = i - 1; j > 0; j--)
            { // at that height how many books can be placed
                width += books[j - 1][0];
                if (width > shelfWidth) // start of new shelf
                    break;

                height = max(height, books[j - 1][1]); // height will be tallest book that is till now present
                dp[i] = min(dp[i], dp[j - 1] + height);
            }
        }
        return dp[n];
    }
};

// https://leetcode.com/problems/filling-bookcase-shelves/