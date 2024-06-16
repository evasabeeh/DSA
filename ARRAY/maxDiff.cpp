// also used when you can buy and sell stock only once
//larger element must appear after smaller element

#include<bits/stdc++.h>
using namespace std;        

int main(){
    int arr[]={7, 1, 8, 2, 4, 10, 3, 6};
    int n=8;
    int maxRight=arr[n-1];
    int maxDiff=-1;
    for(int i=n-2;i>=0;i--){
        if(arr[i]>maxRight)
        maxRight=arr[i];
        else{
            int diff=maxRight-arr[i];
            maxDiff=max(maxDiff, diff);
        }
    }
    cout<<maxDiff;
    return 0;
}