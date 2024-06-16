#include<bits/stdc++.h>
using namespace std;
void countFrequency(int arr[], int n){
    map<int, int> mp;
    for(int i=0; i<n; i++)
    mp[arr[i]]++;
    
    for(auto it: mp)
    cout<<"Frequency of "<<it.first<<": "<<it.second<<endl;
}
int main(){
    int arr[]={5, 8, 5, 5, 1, 1, 8, 1, 2, 9, 6, 2, 1};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<"Eva Sabeeh  21BCS8745\n\n";
    cout<<"Frequency of elements:"<<endl;
    countFrequency(arr, n);
    return 0;
}