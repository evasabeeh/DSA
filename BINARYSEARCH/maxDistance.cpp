#include<bits>/stdc++.h>
using namespace std;
                                           // what is the min max dist possible between two stalls for k such cows
class Solution
{
public:
    bool isPossible(vector<int> &stalls, int mid, int k)
    {
        int cows = 1, last = stalls[0];
        for (int i = 1; i < stalls.size(); i++)
        {
            if (stalls[i] - last >= mid)
            {
                cows++;
                if (cows == k)
                    return true;

                last = stalls[i];
            }
        }
        return false;
    }
    int maxDistance(vector<int> &stalls, int k)
    {
        int start = 0;
        int ans = -1;

        sort(stalls.begin(), stalls.end());
        int end = stalls.back();
        while (start <= end)
        {
            int mid = (end - start) / 2 + start;

            if (isPossible(stalls, mid, k))
            {
                ans = mid;
                start = mid + 1;
            }
            else
                end = mid - 1;
        }
        return ans;
    }
};
int main(){
    Solution s;
    vector<int> arr = {5, 4, 3, 2, 1, 1000000000};
    s.maxDistance(arr, 2);
    return 0;
}

/*
https : // leetcode.com/problems/magnetic-force-between-two-balls/description/
https: // www.naukri.com/code360/problems/aggressive-cows_1082559?leftPanelTabValue=SUBMISSION
*/