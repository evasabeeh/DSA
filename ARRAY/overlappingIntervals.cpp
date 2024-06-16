#include<bits/stdc++.h>         //no. of intervals to be removed to make it non-overlapping
using namespace std;        
static bool compare(vector<int>&v1,vector<int>&v2){
    return v1[1]<v2[1];                                             //sort on basis of vec[1]
}
int main(){
    vector<vector<int>> intervals={{1, 3},{2, 6},{8, 10},{15, 18}};
    sort(intervals.begin(), intervals.end(), compare);              //vector is sorted based on vec[0]
    int count=0, prev=0;
    for(int i=1;i<intervals.size();i++){
        if(intervals[prev][1]>intervals[i][0])
        count++;
        else
        prev=i;
    }
    cout<<count<<endl;
    
    return 0;
}