#include<bits/stdc++.h>
using namespace std;              //Insertion method - SC(1)           stable

int main(){
    int arr[]={6, 3, 12, 1, 25, 2, 9};
    int n=7, key=-1;

    for(int i=1;i<n;i++){
        key=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
    for(int i:arr)
    cout<<i<<" ";

    return 0;
}