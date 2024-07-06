#include<bitset>/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<pair<int, int>> inc;
    void merge(int start, int mid, int end, vector<int> &less, vector<int> &great)
    {
        // count smaller elements in left subarray and minusing the smaller and equal we would get greater elements in right subarray
        int i = start, j = start;
        for (int k = mid + 1; k <= end; k++)
        {
            while (i <= mid && inc[i].first < inc[k].first)
                i++;
            while (j <= mid && inc[j].first <= inc[k].first)
                j++;

            less[inc[k].second] += (i - start);
            great[inc[k].second] += (mid - j + 1);
        }

        vector<pair<int, int>> temp(end - start + 1); // inc sorted array
        int x = start, y = mid + 1, q = 0;

        while (x <= mid && y <= end)
        {
            // sort in inc order
            if (inc[x].first <= inc[y].first)
                temp[q++] = inc[x++];
            else
                temp[q++] = inc[y++];
        }
        while (x <= mid)
        {
            temp[q++] = inc[x++];
        }
        while (y <= end)
        {
            temp[q++] = inc[y++];
        }

        for (int itr = start; itr <= end; itr++)
            inc[itr] = temp[itr - start];
    }

    void divide(int start, int end, vector<int> &less, vector<int> &great)
    {
        if (start >= end)
        {
            return;
        }
        int mid = start + (end - start) / 2;

        divide(start, mid, less, great);
        divide(mid + 1, end, less, great);

        merge(start, mid, end, less, great);
    }
    int createSortedArray(vector<int> &instructions)
    {
        int n = instructions.size();
        vector<int> less(n, 0), great(n, 0);

        for (int i = 0; i < n; i++)
            inc.push_back({instructions[i], i});

        divide(0, n - 1, less, great);

        long long ans = 0;
        for (int i = 0; i < n; i++)
            ans += min(less[i], great[i]);
        ans %= 1000000007;

        return ans;
    }
};
int main(){
    Solution s;
    vector<int> nums = {1, 5, 6, 2};
    cout<<s.createSortedArray(nums);

    return 0;
}

// https://leetcode.com/problems/create-sorted-array-through-instructions/description/