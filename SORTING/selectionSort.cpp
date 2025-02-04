#include<bits/stdc++.h>
using namespace std;              //Selection method - SC(1) & unstable   

int main(){
    int arr[]={6, 3, 12, 1, 25, 2, 9};
    int n=7, min=-1;

    for(int i=0;i<n;i++){
        min=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min])
            min=j;
        }
        swap(arr[min], arr[i]);
    }
    for(int i:arr)
    cout<<i<<" ";
    return 0;
}