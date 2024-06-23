#include<bits/stdc++.h>
using namespace std;        //sort array of 0,1,2          //three ptr approach
int main(){
    vector<int> arr={2, 1, 1, 1, 0, 2, 1, 0, 2, 1, 2, 0};
    int n=arr.size();
    int low=0, high=n-1, mid=0;
    while(mid<=high){
        if(arr[mid]==0)
        swap(arr[low++], arr[mid++]);
        else if(arr[mid]==1)
        mid++;
        else
        swap(arr[high--], arr[mid]);
    }
    for(int i: arr)
    cout<<i<<" ";
    return 0;
}
// low, mid, high
// [0, low-1] have 0's
// [low, mid-1] have 1's
// [mid, high] is unsorted part
// [high+1, n-1] have 2's









//sort 0 and 1
void sortZeroesAndOne(int input[], int size)
{
    int i = 0, j = size - 1;
    while (i < j)
    {
        while (input[i] == 0)
            i++;
        while (input[j] == 1)
            j--;

        if (i < j)
        {
            swap(input[i], input[j]);
            i++;
            j--;
        }
    }
}