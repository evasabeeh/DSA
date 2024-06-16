#include<bits/stdc++.h>
using namespace std;        //leaders in an array: greater than all the elements int the right
                            //time- O(n), space- O(1)
int main(){
    int arr[]={7, 1, 8, 2, 4, 10, 3, 6};
    int n=8;
    int maxx=arr[n-1];      //last element is always the leader
    cout<<maxx<<" ";
    for(int i=n-2;i>=0;i--){
        if(arr[i]>maxx){
            maxx=arr[i];
            cout<<maxx<<" ";
        }
    }
    return 0;
}

//sizeof(arr)/sizeof(arr[0])