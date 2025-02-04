#include<bits/stdc++.h>
using namespace std;              //Divide & conquer method - SC(n)           stable

void merge(int *arr, int start, int mid, int end){
    int m[end-start+1];
    int i1=start;
    int i2=mid+1;
    int x=0;
    while(i1<=mid&&i2<=end){
        if(arr[i1]<=arr[i2])
        m[x++]=arr[i1++];
        else
        m[x++]=arr[i2++];
    }
    while(i1<=mid){
        m[x++]=arr[i1++];
    }
    while(i2<=end){
        m[x++]=arr[i2++];
    }

    for(int i:m)
    arr[start++]=i;               // add from start pointer only
}
void divide(int *arr, int start, int end){
    if(start>=end){
        return;
    }
    int mid=(start+end)/2;
    divide(arr,start,mid);        //creatig hypothetical arrays
    divide(arr,mid+1,end);
    merge(arr,start,mid,end);
}

int main(){
    int arr[]={6, 3, 12, 1, 25, 2, 9};

    divide(arr, 0, 6);

    for(int i:arr)
    cout<<i<<" ";

    return 0;
}