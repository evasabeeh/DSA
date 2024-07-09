#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double averageWaitingTime(vector<vector<int>> &customers)
    {
        int n = customers.size();
        customers[0][1] = customers[0][0] + customers[0][1];
        double waitTime = customers[0][1] - customers[0][0];

        for (int i = 1; i < n; i++)
        {

            if (customers[i - 1][1] < customers[i][0])               // just like {10,3} and {20,1}, there is a gap
                customers[i][1] += customers[i][0];
            else
                customers[i][1] += customers[i - 1][1];

            waitTime += (customers[i][1] - customers[i][0]);
            cout << customers[i][1] << " " << waitTime << endl;       // completion time and wait time
        }
        return waitTime / n;
    }
};

int main(){
    Solution s;
    vector<vector<int>> customers = {{5,2},{5,4},{10,3},{20,1}};
    cout << s.averageWaitingTime(customers);
}

// https://leetcode.com/problems/average-waiting-time/description/?envType=daily-question&envId=2024-07-09