#include<bits/stdc++.h>
using namespace std;
class Solution {           //intersection part of intervals
public:
    void intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> ans;
        int i=0, j=0;
        while(i<firstList.size()&&j<secondList.size()){
            int first=max(firstList[i][0], secondList[j][0]), second=min(firstList[i][1], secondList[j][1]);
            if(first<=second)
            ans.push_back({first, second});

            if(firstList[i][1]<secondList[j][1])
            i++;
            else
            j++;
        }
        for(auto v: ans)
        cout<<"["<<v[0]<<", "<<v[1]<<"], ";
    }
};
int main(){
    vector<vector<int>> a={{0,2},{5,10},{13,23},{24,25}}, b={{1,5},{8,12},{15,24},{25,26}};
    Solution s;
    s.intervalIntersection(a, b);
}