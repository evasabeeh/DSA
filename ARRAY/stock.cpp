#include<bits/stdc++.h>
using namespace std;                //maximize the profit
                                    //if array is in decreasing order then no profit can be earned
int main(){
    vector<int> price={180, 225, 720, 100, 540, 675, 720};  //represents cost on each day
    
    int n = prices.size();
    int minima = prices[0], maxima = -1, profit = 0;
    for (int i = 1; i < n; i++)
    {
        while (i < n - 1 && prices[i] <= prices[i - 1])    // i < n-1 because, maxima should be last, so minima can not be at last
        { // find minima
            minima = prices[i++];
        }
        while (i <= n - 1 && prices[i] > prices[i - 1])
        { // find maxima
            maxima = prices[i++];
        }
        if (maxima > 0) // if no maxima, then no profit
            profit += (maxima - minima);
        else // when maxima stopped coming
            break;

        maxima = 0; // so that maxima is calculated again
        minima = prices[i];   // next minima
    }
    return profit;
}
//time- O(n), space- O(1)