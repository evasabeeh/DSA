#include<bits/stdc++.h>
using namespace std;        

int main(){
    vector<vector<int>> intervals={{1, 3},{2, 6},{8, 10},{15, 18}};
    vector<vector<int>> result;

    sort(intervals.begin(), intervals.end());                       // [a,b][c,d]

    for(int i=0;i<intervals.size();i++){
        if(result.empty()||result.back()[1]<intervals[i][0])
        result.push_back(intervals[i]);
        else
        result.back()[1]=max(intervals[i][1], result.back()[1]);
    }

    for(auto interval: result){
        cout<<"["<<interval[0]<<", "<<interval[1]<<"]"<<endl;
    }
    
    return 0;
}