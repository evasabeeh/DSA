#include<bits/stdc++.h>
using namespace std;         //find max element for each subarray of size k
vector<int> maxSlidingWindow(vector<int> &arr, int n, int k){
    vector<int> ans;
    deque<int> dq(k);
    for(int i=0;i<k;i++){
        while(!dq.empty()&&arr[i]>=arr[dq.back()])
        dq.pop_back();

        dq.push_back(i);
    }
    for(int i=k;i<n;i++){
        ans.push_back(arr[dq.front()]);

        while(!dq.empty()&&dq.front()<=i-k)
        dq.pop_front();
        while(!dq.empty()&&arr[i]>=arr[dq.back()])
        dq.pop_back();
        
        dq.push_back(i);
    }
    ans.push_back(arr[dq.front()]);
    
    return ans;
}
int main(){
    vector<int> arr={3, 4, -1, 1, 5};
    
    vector<int> ans=maxSlidingWindow(arr, 5, 3);

    for(int i: ans)
    cout<<i<<" ";

    return 0;
}