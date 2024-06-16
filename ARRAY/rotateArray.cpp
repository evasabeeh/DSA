#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[]={7, 1, 8, 2, 4, 10, 3, 6};
    int k=4;
    int n=sizeof(arr)/sizeof(arr[0]);
    k=k%n;
    int temp[n];
    int m=0;

    for(int i:arr){
        temp[m++]=i;
    }
    m=0;

    for(int i=0;i<n;i++){           //right rotation by k
        if(i<k){
            arr[m++]=temp[n+i-k];
        }
        else{
            arr[m++]=temp[i-k];
        }
    }

    for(int i: arr){
        cout<<i<<" ";
    }
    return 0;
}

//left rotation

/*
int temp[d];
for(int i=0;i<d;i++)
temp[i]=arr[i];
for(int i=d;i<n;i++)
arr[i-d]=arr[i];
for(int i=n-d;i<n;i++)
arr[i]=temp[i-(n-d)];
*/

/* Most optimal
reverse(arr, arr+d);
reverse(arr+d, arr+n);
reverse(arr, arr+n);
*/