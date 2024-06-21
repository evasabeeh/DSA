#include<bits/stdc++.h>
using namespace std;                           //Partition method            unstable 

int partition(vector<int>&arr, int low, int high)
{
    int pivot=arr[low];                       //first element as pivot
    int i=low, j=high;

    while(i<j){
        while(arr[i]<=pivot&&i<high)          //place smaller elements to the left of pivot and greater on right of the pivot
        i++;
        while(arr[j]>pivot&&j>low)
        j--;

        if(i<j)
        swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);

    return j;
}
void sort(vector<int>&arr, int low, int high)
{
    if(low<high){
        int pivot=partition(arr, low, high);
                                               //Separately sort elements before partition and after partition
        sort(arr, low, pivot-1);
        sort(arr, pivot+1, high);
    }
}
int main(){
    vector<int> arr={4, 5, 4, 2, 1, 4, 3, 7, 10};
    sort(arr, 0, 8);

    for(int i: arr)
    cout<<i<<" ";
    return 0;
}


// smaller on left, pivot, greater on right