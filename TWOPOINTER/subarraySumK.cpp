
#include<bits/stdc++.h>
using namespace std;

int main(){                        //count subarrays that sum upto k
    vector<int> arr={1, 2, 3, -3, 1, 1, 1, 4, 2, -3};
    int k=3;

    int start=0, end=0, sum=0, count=0;
    while(end<arr.size()){
       sum+=arr[end];
       while(sum>k){
           sum-=arr[start];
           start++;
       }
       if(sum==k)
       count++;

       end++;
   }
   cout<<count;
}
