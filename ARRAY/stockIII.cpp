// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<int> left(n, 0), right(n, 0); // first calculate left to right max profit and right to left max profit then add both and get total max

        int minima = prices[0];
        for (int i = 1; i < n; i++)
        {
            int temp = prices[i] - minima;    // if sold on current day
            left[i] = max(temp, left[i - 1]); // maximum profit that can be achieved
            minima = min(minima, prices[i]);  // minima till now
        }

        int maxima = prices[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            int temp = maxima - prices[i];      // if sold on current day
            right[i] = max(temp, right[i + 1]); // maximum profit that can be achieved
            maxima = max(maxima, prices[i]);    // maxima till now
        }

        int ans = right[0];
        for (int i = 0; i < n - 1; i++)
            ans = max(ans, left[i] + right[i + 1]); // left[i]+right[i+1] so that they don't overlap

        return ans;
    }
};

/*
int minima1 = INT_MAX, minima2 = INT_MAX, stock1 = 0, stock2 = 0;
        for(int a: arr){
            minima1 = min(minima1, a);
            stock1 = max(stock1, a - minima1);

            minima2 = min(minima2, a - stock1);
            stock2 = max(stock2, a - minima2);
        }
        return stock2;
*/